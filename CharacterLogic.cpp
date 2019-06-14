

#include "CharacterLogic.h"
CharacterLogic::CharacterLogic() {
    this -> actualPosition = std::make_pair(10, 15);
}

std::pair<unsigned int, unsigned int> CharacterLogic::getActualPosition() const{
    return this -> actualPosition;
}