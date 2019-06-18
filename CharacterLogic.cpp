

#include "CharacterLogic.h"
CharacterLogic::CharacterLogic() {
    this -> actualPosition = std::make_pair(9, 1);
    //jump();

}

std::pair<unsigned int, unsigned int> CharacterLogic::getActualPosition() const{
    return this -> actualPosition;
}

std::pair<unsigned int, unsigned int> CharacterLogic::getFuturePosition() const{
    return this -> futurePosition;
}

void CharacterLogic::setActualPosition(std::pair<int, int> position){

    actualPosition = position;
}

void CharacterLogic::fallingManager(EnvironmentLogic &mainEnvironmentLogic) {

    if(! mainEnvironmentLogic.hasCloud(std::make_pair(actualPosition.first, actualPosition.second+1))) {
        std::cout << "falling\n";
        actualPosition = std::make_pair(actualPosition.first, actualPosition.second+1);
    }
}

void CharacterLogic::jump(EnvironmentLogic &mainEnvironmentLogic) {
    if(! mainEnvironmentLogic.hasCloud(std::make_pair(actualPosition.first, actualPosition.second-1))
    && mainEnvironmentLogic.hasCloud(std::make_pair(actualPosition.first, actualPosition.second+1))) {
        std::cout << "jumping\n";
        actualPosition = std::make_pair(actualPosition.first, actualPosition.second-3);
    }
}

void CharacterLogic::moveRight(EnvironmentLogic &mainEnvironmentLogic) {
    if(! mainEnvironmentLogic.hasCloud(std::make_pair(actualPosition.first+1, actualPosition.second))) {
        std::cout << "moving right\n";
        actualPosition = std::make_pair(actualPosition.first+1, actualPosition.second);
    }
}

void CharacterLogic::moveLeft(EnvironmentLogic &mainEnvironmentLogic) {
    if(! mainEnvironmentLogic.hasCloud(std::make_pair(actualPosition.first-1, actualPosition.second))) {
        std::cout << "moving left\n";
        actualPosition = std::make_pair(actualPosition.first-1, actualPosition.second);
    }
}

bool CharacterLogic::isDead(EnvironmentLogic &mainEnvironmentLogic) const{

    if(actualPosition.first == 0 || actualPosition.second == mainEnvironmentLogic.getCloudsBoardHeight())
        return true;
    else
        return false;

}

