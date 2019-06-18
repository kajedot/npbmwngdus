//
// Created by kajetan on 15.06.2019.
//

#ifndef NPBMWNGDUS_GAMEMANAGER_H
#define NPBMWNGDUS_GAMEMANAGER_H

#include "WindowView.h"
#include "CharacterLogic.h"
#include "EnvironmentLogic.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>



class GameManager {
    sf::RenderWindow SFMLWindow;
    sf::Event event;
    CharacterLogic mainCharacterLogic;
    WindowView mainWindowView;
    EnvironmentLogic mainEnvironmentLogic;

    void windowEventsManager(sf::RenderWindow &window, sf::Event &event);

    void collisionManager();

    void lifeManager(sf::RenderWindow &window);

public:
    GameManager();
    void windowLoop();
};

#endif //NPBMWNGDUS_GAMEMANAGER_H
