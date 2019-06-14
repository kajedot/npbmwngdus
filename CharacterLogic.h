//
// Created by kajetan on 14.06.2019.
//

#ifndef NPBMWNGDUS_CHARACTERLOGIC_H
#define NPBMWNGDUS_CHARACTERLOGIC_H


#include <utility>

class CharacterLogic {
    private:
    std::pair<unsigned int, unsigned int> actualPosition;

    public:
    CharacterLogic();
    std::pair<unsigned int, unsigned int> getActualPosition() const;
};


#endif //NPBMWNGDUS_CHARACTERLOGIC_H
