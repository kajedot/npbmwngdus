//
// Created by kajetan on 16.06.2019.
//

#ifndef NPBMWNGDUS_ENVIRONMENTLOGIC_H
#define NPBMWNGDUS_ENVIRONMENTLOGIC_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "utility"

enum Field{CHARACTER_CURRENT, CHARACTER_TO_BE, CLOUD, AIR};

class EnvironmentLogic {

    void setVectors(sf::RenderWindow &mainWindow);

public:
    std::vector < std::vector <Field> > gameBoard;

    EnvironmentLogic(sf::RenderWindow &mainWindow);

    bool isNegativeNumber(int in);

    bool hasCloud(std::pair<unsigned int, unsigned int> position);

    void setCurrentCharacterPosition(std::pair<unsigned int, unsigned int> position);

    void setToBeCharacterPosition(std::pair<unsigned int, unsigned int> position);

    unsigned int getCloudsBoardWidth() const;

    unsigned int getCloudsBoardHeight() const;

    void addCloud(std::pair<unsigned int, unsigned int> position);

    void delCloud(std::pair<unsigned int, unsigned int> position);

    void cloudsManager();






};

#endif //NPBMWNGDUS_ENVIRONMENTLOGIC_H