//
// Created by kajetan on 15.06.2019.
//

#include "GameManager.h"

GameManager::GameManager():SFMLWindow(sf::VideoMode(800, 600), "N.P.B.M.W.N.G.D.U.S. Jumper Edition", sf::Style::Titlebar), mainEnvironmentLogic(SFMLWindow){
    std::cout << "Gathered clouds board size: " << mainEnvironmentLogic.getCloudsBoardWidth() << " x " << mainEnvironmentLogic.getCloudsBoardHeight() << std::endl;
}

void GameManager::windowLoop() {
    while (SFMLWindow.isOpen()) {
        sf::Event event;
        SFMLWindow.clear(sf::Color::Black);
        windowEventsManager(SFMLWindow, event);
        mainCharacterLogic.fallingManager(mainEnvironmentLogic);
        mainEnvironmentLogic.cloudsManager();
        collisionManager();
        mainWindowView.draw(mainCharacterLogic, mainEnvironmentLogic, SFMLWindow);
        SFMLWindow.display();
        usleep(500000);

    }
}

void GameManager::windowEventsManager(sf::RenderWindow &window, sf::Event &event) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                mainCharacterLogic.jumpingEvent(mainEnvironmentLogic);
            }
        }
    }
}

void GameManager::collisionManager() {
    std::pair <unsigned int, unsigned int> characterPosition = mainCharacterLogic.getActualPosition();

    if(mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second))){
        std::cout << "Detected collision with cloud\n";
        if (! mainEnvironmentLogic.isNegativeNumber(characterPosition.first-1)) {
            mainCharacterLogic.setActualPosition(std::make_pair(characterPosition.first-1, characterPosition.second));
        }
    }
}