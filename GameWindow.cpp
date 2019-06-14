//
// Created by kajetan on 14.06.2019.
//

#include "GameWindow.h"
#include "CharacterLogic.h"
#include <iostream>

GameWindow::GameWindow() {
    sf::RenderWindow window (sf::VideoMode(800, 600), "N.P.B.M.W.N.G.D.U.S. Jumper Edition", sf::Style::Titlebar);

    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("background.png")){
        std::cout << "ERR: background.png not loaded" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    sf::Texture characterTexture;
    if(!characterTexture.loadFromFile("character.png")){
        std::cout << "ERR: character.png not loaded" << std::endl;
    }

    characterSprite.setTexture(characterTexture);


    while (window.isOpen()){
        window.clear();
        windowEventsManager(window);
        drawBackground(window);

        window.display();
    }
}

int GameWindow::logicToScreenPosition(int logicPosition){
    return logicPosition*40;
}

void GameWindow::windowEventsManager(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void GameWindow::drawBackground(sf::RenderWindow &window) {
    for (int x = 0; x < window.getSize().x/40 ; ++x) {
        for (int y = 0; y < window.getSize().y/40; ++y) {
            backgroundSprite.setPosition(logicToScreenPosition(x), logicToScreenPosition(y));
            window.draw(backgroundSprite);
        }
    }
}

void GameWindow::drawCharacter(sf::RenderWindow &window) {
    for (int x = 0; x < window.getSize().x/40 ; ++x) {
        for (int y = 0; y < window.getSize().y/40; ++y) {
            if (x == CharacterLogic.getActualPosition().x; )
            window.draw(backgroundSprite);
        }
    }
}