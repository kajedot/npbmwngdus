//
// Created by kajetan on 14.06.2019.
//

#ifndef NPBMWNGDUS_GAMEWINDOW_H
#define NPBMWNGDUS_GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameWindow {
    sf::Sprite backgroundSprite;

    sf::Sprite characterSprite;

    void drawBackground(sf::RenderWindow &window);

    int logicToScreenPosition(int logicPosition);

    void windowEventsManager(sf::RenderWindow &window);

    void drawCharacter(sf::RenderWindow &window);

public:
    GameWindow();
};


#endif //NPBMWNGDUS_GAMEWINDOW_H