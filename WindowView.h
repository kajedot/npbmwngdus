//
// Created by kajetan on 14.06.2019.
//

#ifndef NPBMWNGDUS_WINDOWVIEW_H
#define NPBMWNGDUS_WINDOWVIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "CharacterLogic.h"
#include "EnvironmentLogic.h"

class WindowView {
    sf::Texture backgroundTexture;
    sf::Texture characterTexture;
    sf::Texture cloudTexture;


    sf::Sprite backgroundSprite;
    sf::Sprite characterSprite;
    sf::Sprite cloudSprite;


    int logicToScreenPosition(int logicPosition);
    void drawBackground(sf::RenderWindow &window);
    void drawCharacter(CharacterLogic &mainLogic, sf::RenderWindow &window);


public:
    WindowView();
    void draw(CharacterLogic &mainLogic, EnvironmentLogic &mainEnvironmentLogic, sf::RenderWindow &window);
    void fallingAnimation(std::pair <int, int> positionToLand, CharacterLogic &mainCharacterLogic, sf::RenderWindow &window);
    void drawCloud(EnvironmentLogic &mainEnvironmentLogic, sf::RenderWindow &window);
};


#endif //NPBMWNGDUS_WINDOWVIEW_H