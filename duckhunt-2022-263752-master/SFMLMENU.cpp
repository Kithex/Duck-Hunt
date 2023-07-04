

#include "SFMLMENU.h"

#include "SFMLMENU.h"
#include<iostream>
using namespace std;
SFMLMENU::SFMLMENU(DuckBoard &b):board(b) {
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
    menutext[0].setFillColor(sf::Color::White);
    menutext[0].setString("Welcome in Duck Hunt");
    menutext[0].setPosition(sf::Vector2f(10, 60));


    menutext[1].setFont(font);
    menutext[1].setFillColor(sf::Color::White);
    menutext[1].setString("Play");
    menutext[1].setPosition(sf::Vector2f(10, screen_height/5));

    menutext[2].setFont(font);
    menutext[2].setFillColor(sf::Color::Red);
    menutext[2].setString("EXIT");
    menutext[2].setPosition(sf::Vector2f(10, screen_height*0.8));

    menutext[3].setFont(font);
    menutext[3].setFillColor(sf::Color::White);
    menutext[3].setString("Credits");
    menutext[3].setPosition(sf::Vector2f(10, screen_height*0.4));

    menutext[4].setFont(font);
    menutext[4].setFillColor(sf::Color::White);
    menutext[4].setString(" Dziekuje za pomoc w ostatnim dniu oddania pracy.");

    menutext[5].setFont(font);
    menutext[5].setFillColor(sf::Color::White);
    menutext[5].setString("Pozdrawiam oraz zycze milego sprawdzania prac :3");


    menutext[5].setPosition(sf::Vector2f(0,30));

}
void SFMLMENU::draw(sf::RenderWindow & window) {
    window.draw(backgroundBlured);
    window.draw(menutext[0]);
    window.draw(menutext[1]);
    window.draw(menutext[2]);
    window.draw(menutext[3]);
}
void SFMLMENU::handleEvent(sf::Event &event,sf::RenderWindow &win) {
    if(event.type==sf::Event::MouseButtonPressed) {

        int x = event.mouseButton.x;
        int y = event.mouseButton.y;
        if(x>10 and x<75 and y>153 and y<180 )
        {
            board.StartGame();

        }
        if (x>10 and x<75 and y>615 and y<645)
        {

                    win.close();
        }
        if (x>10 and x<75 and y>307 and y<340)
        {
            win.draw(backgroundBlured);
            win.draw(menutext[4]);
            win.draw(menutext[5]);
        }
    }
}

