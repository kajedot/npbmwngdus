//
// Created by kajetan on 16.06.2019.
//

#ifndef NPBMWNGDUS_ENVIRONMENTLOGIC_H
#define NPBMWNGDUS_ENVIRONMENTLOGIC_H

#include <vector>
#include "SFML/Graphics.hpp"
#include <utility>
#include <random>
#include <iostream>


enum Field{CLOUD, AIR};

class EnvironmentLogic {

    void setVectors(sf::RenderWindow &mainWindow);

public:
    std::vector < std::vector <Field> > gameBoard;

    explicit EnvironmentLogic(sf::RenderWindow &mainWindow);

    bool isNegativeNumber(int in);

    unsigned int randomNumberInRange(int from, int to);

    bool hasCloud(std::pair<unsigned int, unsigned int> position) const;

    unsigned int countClouds() const;

    unsigned int getCloudsBoardWidth() const;

    unsigned int getCloudsBoardHeight() const;

    void addCloud(std::pair<unsigned int, unsigned int> position);

    void delCloud(std::pair<unsigned int, unsigned int> position);

    void cloudsAtLeftBorder();

    void cloudsAtRightBorder();



};

#endif //NPBMWNGDUS_ENVIRONMENTLOGIC_H