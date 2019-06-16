//
// Created by kajetan on 16.06.2019.
//

#include "EnvironmentLogic.h"

EnvironmentLogic::EnvironmentLogic(sf::RenderWindow &mainWindow) {
    setVectors(mainWindow);
}

void EnvironmentLogic::setVectors(sf::RenderWindow &mainWindow) {
    std::vector<Field> temp;
    temp.assign(mainWindow.getSize().y / 40, AIR);
    gameBoard.assign(mainWindow.getSize().x / 40, temp);

    gameBoard[2][13] = CLOUD;
}

bool EnvironmentLogic::hasCloud(std::pair<int, int> position) {
    if(gameBoard[position.first][position.second] == CLOUD){
        return true;
    }
}

void EnvironmentLogic::setCurrentCharacterPosition(std::pair<int, int> position){
    gameBoard[position.first][position.second] = CHARACTER_CURRENT;
}

void EnvironmentLogic::setToBeCharacterPosition(std::pair<int, int> position){
    gameBoard[position.first][position.second] = CHARACTER_TO_BE;
}
