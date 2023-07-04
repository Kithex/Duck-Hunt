//
// Created by OMEGAPEPE on 17.06.2022.
//

#ifndef DUCKHUNT_SFMLDUCK_H
#define DUCKHUNT_SFMLDUCK_H
#include "DuckBoard.h"
#include <SFML/Graphics.hpp>

class SFMLDuck {
DuckBoard &board;
sf::Texture tex_duck;
sf::RectangleShape field;
sf::RectangleShape shape;
sf::Texture texture;
sf::Texture Background2;
sf::Texture Duck_texture;
sf::Font font;
sf::Text text;
sf::Text score;
public:
    explicit SFMLDuck(DuckBoard &b);
    void drawOnWindow(sf::RenderWindow &win);
};


#endif //DUCKHUNT_SFMLDUCK_H
