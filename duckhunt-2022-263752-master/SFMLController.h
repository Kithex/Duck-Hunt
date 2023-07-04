//
// Created by OMEGAPEPE on 19.06.2022.
//

#ifndef DUCKHUNT_SFMLCONTROLLER_H
#define DUCKHUNT_SFMLCONTROLLER_H
#include "DuckBoard.h"
#include "SFMLDuck.h"
namespace sf
{
    class Event;
}

class SFMLController {

    DuckBoard &board;
public:
    explicit SFMLController(DuckBoard & b);
    void handleEvent(sf::Event & event);
};


#endif //DUCKHUNT_SFMLCONTROLLER_H
