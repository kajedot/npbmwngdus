//
// Created by kajetan on 14.06.2019.
//

#ifndef NPBMWNGDUS_CHARACTERLOGIC_H
#define NPBMWNGDUS_CHARACTERLOGIC_H


#include <utility>

class CharacterLogic {
    private:
    std::pair<unsigned int, unsigned int> actualPosition;
    std::pair<unsigned int, unsigned int> futurePosition;

    public:
    CharacterLogic();
    std::pair<unsigned int, unsigned int> getActualPosition() const;
    std::pair<unsigned int, unsigned int> getFuturePosition() const;

    void jump();
    void setActualPosition(std::pair<int, int> positionToLand);
};


#endif //NPBMWNGDUS_CHARACTERLOGIC_H
