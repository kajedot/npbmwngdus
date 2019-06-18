//
// Created by kajetan on 14.06.2019.
//

#include "WindowView.h"

WindowView::WindowView() {

    if(!backgroundTexture.loadFromFile("background.png")){
        std::cout << "ERR: background.png not loaded" << std::endl;
    }else{
        std::cout << "background.png loaded" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);

    if(!characterTexture.loadFromFile("character.png")){
        std::cout << "ERR: character.png not loaded" << std::endl;
    }else{
        std::cout << "character.png loaded" << std::endl;
    }
    characterSprite.setTexture(characterTexture);

    if(!cloudTexture.loadFromFile("cloud.png")){
        std::cout << "ERR: cloud.png not loaded" << std::endl;
    }else{
        std::cout << "cloud.png loaded" << std::endl;
    }
    cloudSprite.setTexture(cloudTexture);

    if(!goalTexture.loadFromFile("goal.png")){
        std::cout << "ERR: goal.png not loaded" << std::endl;
    }else{
        std::cout << "goal.png loaded" << std::endl;
    }
    goalSprite.setTexture(goalTexture);
}
int WindowView::logicToScreenPosition(int logicPosition){
    return logicPosition*40;
}

void WindowView::drawBackground(sf::RenderWindow &window) {
    for (int x = 0; x < window.getSize().x/40 ; ++x) {
        for (int y = 0; y < window.getSize().y/40; ++y) {
            backgroundSprite.setPosition(logicToScreenPosition(x), logicToScreenPosition(y));
            window.draw(backgroundSprite);
        }
    }
}

void WindowView::drawCharacter(CharacterLogic &mainLogic, sf::RenderWindow &window) {
    int actualX = mainLogic.getActualPosition().first, actualY = mainLogic.getActualPosition().second;

    characterSprite.setPosition(logicToScreenPosition(actualX), logicToScreenPosition(actualY));
    window.draw(characterSprite);
}

void WindowView::draw(CharacterLogic &mainLogic, EnvironmentLogic &mainEnvironmentLogic, sf::RenderWindow &window){
    window.clear();
    this -> drawBackground(window);
    this -> drawCharacter(mainLogic, window);
    this -> drawCloud(mainEnvironmentLogic, window);

    goalSprite.setPosition(logicToScreenPosition(mainEnvironmentLogic.getCloudsBoardWidth()-1), 1);
    window.draw(goalSprite);
}


void WindowView::drawCloud(EnvironmentLogic &mainEnvironmentLogic, sf::RenderWindow &window){
    for (int x = 0; x < window.getSize().x / 40; ++x) {
        for (int y = 0; y < window.getSize().y / 40; ++y) {
            if (mainEnvironmentLogic.hasCloud(std::make_pair(x, y))) {
                cloudSprite.setPosition(logicToScreenPosition(x), logicToScreenPosition(y));//
                window.draw(cloudSprite);
            }
        }
    }
}
