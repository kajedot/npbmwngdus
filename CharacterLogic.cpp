

#include <iostream>
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

void CharacterLogic::jump(){
    this -> actualPosition.second = actualPosition.second +5;
    std::cout << "jumping" << std::endl;
}

void CharacterLogic::setActualPosition(std::pair<int, int> position){

    actualPosition = position;
}
