//
// Created by OMEGAPEPE on 19.06.2022.
//

#ifndef DUCKHUNT_SFMLFINISH_H
#define DUCKHUNT_SFMLFINISH_H
#include "SFMLDuck.h"
#include "DuckBoard.h"

class SFMLFINISH {

        DuckBoard &board;
        sf::Font font;
        sf::Text menutext[3];
        sf::Texture background_blured;
        sf::Sprite backgroundBlured;
    public:
        explicit SFMLFINISH(DuckBoard &b);
        void draw(sf::RenderWindow &window);
        void handleEvent(sf::Event &event, sf::RenderWindow &win);
};


#endif //DUCKHUNT_SFMLFINISH_H
