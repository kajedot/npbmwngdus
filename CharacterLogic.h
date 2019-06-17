//
// Created by kajetan on 14.06.2019.
//

#ifndef NPBMWNGDUS_CHARACTERLOGIC_H
#define NPBMWNGDUS_CHARACTERLOGIC_H

#include "EnvironmentLogic.h"
#include <iostream>
#include <utility>

class CharacterLogic {
    private:
    std::pair<unsigned int, unsigned int> actualPosition;
    std::pair<unsigned int, unsigned int> futurePosition;

    public:
    CharacterLogic();
    std::pair<unsigned int, unsigned int> getActualPosition() const;
    std::pair<unsigned int, unsigned int> getFuturePosition() const;

    void fallingManager(EnvironmentLogic &mainEnvironmentLogic);

    void jumpingEvent(EnvironmentLogic &mainEnvironmentLogic);

    void jump();
    void setActualPosition(std::pair<int, int> positionToLand);
};


#endif //NPBMWNGDUS_CHARACTERLOGIC_H
