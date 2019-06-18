//
// Created by kajetan on 16.06.2019.
//

#include <functional>
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


}

bool EnvironmentLogic::isNegativeNumber(int in) {
    if (in < 0)
        return true;
    else
        return false;
}

unsigned int EnvironmentLogic::randomNumberInRange(int from, int to) {

    std::random_device r_dev;
    std::mt19937 mt(r_dev());

    std::uniform_int_distribution<int> distribution(from, to);
    int random_number = distribution(mt);

    return random_number;

}

bool EnvironmentLogic::hasCloud(std::pair<unsigned int, unsigned int> position) const{
    if(gameBoard[position.first][position.second] == CLOUD){
        return true;
    }
}

unsigned int EnvironmentLogic::countClouds() const{
    unsigned int counter = 0;
    for (int x = 0; x < getCloudsBoardWidth(); ++x) {
        for (int y = 0; y < getCloudsBoardHeight(); ++y) {
            if(hasCloud(std::make_pair(x, y))){
                counter++;
            }
        }
    }
    return counter;
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

void EnvironmentLogic::delCloud(std::pair<unsigned int, unsigned int> position) {
    gameBoard[position.first][position.second] = AIR;
}

void EnvironmentLogic::cloudsAtLeftBorder() {
    for (int x = 0; x < getCloudsBoardWidth(); ++x) {
        for (int y = 0; y < getCloudsBoardHeight(); ++y) {
            if(hasCloud(std::make_pair(x, y))){
                if (!isNegativeNumber(x-1)) {
                    addCloud(std::make_pair(x-1, y));
                }
                delCloud(std::make_pair(x, y));
            }
        }
    }
}

void EnvironmentLogic::cloudsAtRightBorder() {

    addCloud(std::make_pair(getCloudsBoardWidth()-1, getCloudsBoardHeight()-1));

    std::cout << "Current count of clouds: " << countClouds() << std::endl;
    if (countClouds() < 50) {
        unsigned int cloudsPatternTable[10] = {1, 2, 2, 3, 3, 2, 2, 1, 3, 2};
        unsigned int cloudVerticalPosition = randomNumberInRange(1, getCloudsBoardHeight()-1);
        std::cout << "Picked vertical position for cloud: " << cloudVerticalPosition;
        unsigned int cloudLength = cloudsPatternTable[randomNumberInRange(0, 9)];
        std::cout << " and length: " << cloudLength << std::endl;


        for (int x = 0; x < cloudLength ; ++x) {
            addCloud(std::make_pair(getCloudsBoardWidth()-1-x, cloudVerticalPosition));
        }
    }
}