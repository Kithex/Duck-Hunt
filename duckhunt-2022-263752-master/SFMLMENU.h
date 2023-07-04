//
// Created by OMEGAPEPE on 19.06.2022.
//

#ifndef DUCKHUNT_SFMLMENU_H
#define DUCKHUNT_SFMLMENU_H
#include "SFMLDuck.h"
#include "DuckBoard.h"

class SFMLMENU {
DuckBoard &board;
sf::Font font;
sf::Text menutext[6];

sf::Texture background_blured;
sf::Sprite backgroundBlured;
public:
    explicit  SFMLMENU(DuckBoard &b);
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event &event, sf::RenderWindow &win);
};


#endif //DUCKHUNT_SFMLMENU_H
