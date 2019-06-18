//
// Created by kajetan on 15.06.2019.
//

#include "GameManager.h"

GameManager::GameManager():SFMLWindow(sf::VideoMode(800, 600), "N.P.B.M.W.N.G.D.U.S. Jumper Edition", sf::Style::Titlebar), mainEnvironmentLogic(SFMLWindow){
    std::cout << "Gathered clouds board size: " << mainEnvironmentLogic.getCloudsBoardWidth() << " x " << mainEnvironmentLogic.getCloudsBoardHeight() << std::endl;
}

void GameManager::windowLoop() {
    while (SFMLWindow.isOpen()) {
        SFMLWindow.clear(sf::Color::Black);

        windowEventsManager(SFMLWindow, event);
        mainWindowView.draw(mainCharacterLogic, mainEnvironmentLogic, SFMLWindow);
        SFMLWindow.display();
        mainCharacterLogic.fallingManager(mainEnvironmentLogic);
        mainEnvironmentLogic.cloudsAtRightBorder();
        mainEnvironmentLogic.cloudsAtLeftBorder();
        collisionManager();
        lifeManager(SFMLWindow);
        winManager(mainEnvironmentLogic, SFMLWindow);

        usleep(100000);

    }
}

void GameManager::windowEventsManager(sf::RenderWindow &window, sf::Event &event) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                mainCharacterLogic.jump(mainEnvironmentLogic);
            }

            if (event.key.code == sf::Keyboard::Left) {
                mainCharacterLogic.moveLeft(mainEnvironmentLogic);
            }

            if (event.key.code == sf::Keyboard::Right) {
                mainCharacterLogic.moveRight(mainEnvironmentLogic);
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

void GameManager::lifeManager(sf::RenderWindow &window) {
    if(mainCharacterLogic.isDead(mainEnvironmentLogic)){
        std::cout << "Game over\n";
        window.close();

    }
}

void GameManager::winManager(EnvironmentLogic &mainEnvironmentLogic, sf::RenderWindow &window) {
    if(mainCharacterLogic.getActualPosition().first == mainEnvironmentLogic.getCloudsBoardWidth()-1 && mainCharacterLogic.getActualPosition().second == 1){
        std::cout << "You win!!!\n";
        window.close();


    }
}