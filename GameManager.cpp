//
// Created by kajetan on 15.06.2019.
//

#include "GameManager.h"

GameManager::GameManager():SFMLWindow(sf::VideoMode(800, 600), "N.P.B.M.W.N.G.D.U.S. Jumper Edition", sf::Style::Titlebar), mainEnvironmentLogic(SFMLWindow){
    std::cout << "Gathered clouds board size: " << mainEnvironmentLogic.getCloudsBoardWidth() << " x " << mainEnvironmentLogic.getCloudsBoardHeight() << std::endl;
}

bool GameManager::isNegativeNumber(int in) {
    if (in < 0)
        return true;
    else
        return false;
}

void GameManager::windowLoop() {
    while (SFMLWindow.isOpen()) {
        sf::Event event;
        SFMLWindow.clear(sf::Color::Black);
        windowEventsManager(SFMLWindow, event);
        fallingManager(SFMLWindow);
        cloudsManager(SFMLWindow);
        collisionManager(SFMLWindow);
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
                jumpingEvent(window);
            }
        }
    }
}

void GameManager::fallingManager(sf::RenderWindow &window) {
    std::pair <int, int> characterPosition;
    characterPosition.first = mainCharacterLogic.getActualPosition().first;
    characterPosition.second = mainCharacterLogic.getActualPosition().second;

    if(! mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second+1))) {
        std::cout << "falling\n";
        mainCharacterLogic.setActualPosition(std::make_pair(characterPosition.first, characterPosition.second+1));
    }
}

void GameManager::jumpingEvent(sf::RenderWindow &window) {
    std::pair <int, int> characterPosition;
    characterPosition.first = mainCharacterLogic.getActualPosition().first;
    characterPosition.second = mainCharacterLogic.getActualPosition().second;

    if(! mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second-1)) && mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second+1))) {
        std::cout << "jumping\n";
        mainCharacterLogic.setActualPosition(std::make_pair(characterPosition.first, characterPosition.second-4));
    }
}


void GameManager::cloudsManager(sf::RenderWindow &window) {
    for (int x = 0; x < mainEnvironmentLogic.getCloudsBoardWidth(); ++x) {
        for (int y = 0; y < mainEnvironmentLogic.getCloudsBoardHeight(); ++y) {
            if(mainEnvironmentLogic.hasCloud(std::make_pair(x, y))){
                if (!isNegativeNumber(x-1)) {
                    mainEnvironmentLogic.addCloud(std::make_pair(x-1, y));
                }
                mainEnvironmentLogic.delCloud(std::make_pair(x, y));
            }
        }
    }
}

void GameManager::collisionManager(sf::RenderWindow &window) {
    std::pair <unsigned int, unsigned int> characterPosition = mainCharacterLogic.getActualPosition();

            if(mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second))){
                std::cout << "Detected collision with cloud\n";
                if (!isNegativeNumber(characterPosition.first-1)) {
                    mainCharacterLogic.setActualPosition(std::make_pair(characterPosition.first-1, characterPosition.second));
                }

            }
}