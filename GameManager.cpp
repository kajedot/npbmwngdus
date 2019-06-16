//
// Created by kajetan on 15.06.2019.
//

#include "GameManager.h"

GameManager::GameManager():SFMLWindow(sf::VideoMode(800, 600), "N.P.B.M.W.N.G.D.U.S. Jumper Edition", sf::Style::Titlebar), mainEnvironmentLogic(SFMLWindow)
{}

void GameManager::windowLoop() {
    while (SFMLWindow.isOpen()) {
        sf::Event event;
        SFMLWindow.clear(sf::Color::Black);
        windowEventsManager(SFMLWindow, event);
        fallingManager(SFMLWindow);
        mainWindowView.draw(mainCharacterLogic, mainEnvironmentLogic, SFMLWindow);
        cloudsDrawingManager(SFMLWindow);
        SFMLWindow.display();
    }
}

void GameManager::windowEventsManager(sf::RenderWindow &window, sf::Event &event) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                mainCharacterLogic.jump();
            }
        }
    }
}

void GameManager::fallingManager(sf::RenderWindow &window) {
    std::pair <int, int> characterPosition;
    characterPosition.first = mainCharacterLogic.getActualPosition().first;
    characterPosition.second = mainCharacterLogic.getActualPosition().second;

    if(mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second+1))) {

        for (int y = characterPosition.second; y < window.getSize().y / 40; ++y) {
            if (mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, y))) {
                mainWindowView.fallingAnimation(std::make_pair(characterPosition.first, y - 1), mainCharacterLogic, window);
                mainCharacterLogic.setActualPosition(std::make_pair(characterPosition.first, y - 1));
                return;
            }
            mainWindowView.fallingAnimation(std::make_pair(characterPosition.first, 14), mainCharacterLogic, window); //temporary falling to floor
            mainCharacterLogic.setActualPosition(std::make_pair(characterPosition.first, 14));
        }
    }
}

void GameManager::cloudsDrawingManager(sf::RenderWindow &window) {


}