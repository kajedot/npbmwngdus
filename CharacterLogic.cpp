

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
    std::pair <int, int> characterPosition;
    characterPosition.first = getActualPosition().first;
    characterPosition.second = getActualPosition().second;

    if(! mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second+1))) {
        std::cout << "falling\n";
        actualPosition = std::make_pair(characterPosition.first, characterPosition.second+1);
    }
}

void CharacterLogic::jumpingEvent(EnvironmentLogic &mainEnvironmentLogic) {
    std::pair <int, int> characterPosition;
    characterPosition.first = actualPosition.first;
    characterPosition.second = actualPosition.second;

    if(! mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second-1))
    && mainEnvironmentLogic.hasCloud(std::make_pair(characterPosition.first, characterPosition.second+1))) {
        std::cout << "jumping\n";
        actualPosition = std::make_pair(characterPosition.first, characterPosition.second-3);
    }
}

