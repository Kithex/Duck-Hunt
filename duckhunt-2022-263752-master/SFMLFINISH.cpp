//
// Created by OMEGAPEPE on 19.06.2022.
//

#include "SFMLFINISH.h"
SFMLFINISH::SFMLFINISH(DuckBoard &b):board(b){
    constexpr int screen_width = 1280;
    constexpr int screen_height = 769;
    if(!font.loadFromFile("../files/arial.ttf"))
    {
        abort();
    }
    if(!background_blured.loadFromFile("../files/stageblure.png"))
    {
        abort();
    }
    backgroundBlured.setTexture(background_blured);
    menutext[0].setFont(font);
    sf::Color color(255, 204, 0);
    menutext[0].setCharacterSize(200);
    menutext[0].setFillColor(color);
    menutext[0].setString("Victory!!!");
    menutext[0].setPosition(sf::Vector2f(screen_width/2 -350, 100));

    menutext[2].setFont(font);
    menutext[2].setFillColor(sf::Color::Red);
    menutext[2].setString("EXIT");
    menutext[2].setPosition(sf::Vector2f(screen_width/2, screen_height*0.8));
}
void SFMLFINISH::draw(sf::RenderWindow & window) {
    window.draw(backgroundBlured);
    window.draw(menutext[0]);

    window.draw(menutext[2]);
}
void SFMLFINISH::handleEvent(sf::Event &event,sf::RenderWindow &win) {
    if(event.type==sf::Event::MouseButtonPressed) {

        int x = event.mouseButton.x;
        int y = event.mouseButton.y;

        if ((x>(1280/2)-40) and x<(1280/2) +40 and y>615 and y<645)
        {

            win.close();
        }
    }
}