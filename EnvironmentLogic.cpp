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

    gameBoard[9][3] = CLOUD;
    gameBoard[10][3] = CLOUD;
    gameBoard[11][3] = CLOUD;
    gameBoard[12][4] = CLOUD;
    gameBoard[13][4] = CLOUD;
    gameBoard[14][4] = CLOUD;
    gameBoard[15][3] = CLOUD;
    gameBoard[16][3] = CLOUD;
    gameBoard[17][3] = CLOUD;




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

unsigned int EnvironmentLogic::getCloudsBoardWidth() const {
    gameBoard.size();
}

unsigned int EnvironmentLogic::getCloudsBoardHeight() const {
    gameBoard[0].size();
}

void EnvironmentLogic::addCloud(std::pair<unsigned int, unsigned int> position) {
    gameBoard[position.first][position.second] = CLOUD;
}

void EnvironmentLogic::delCloud(std::pair<int, int> position) {
    gameBoard[position.first][position.second] = AIR;
}