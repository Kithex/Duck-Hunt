#include <iostream>
#include "DuckBoard.h"
#include "DuckBoard.cpp"
#include <SFML/Graphics.hpp>
#include "DuckController.h"
#include "SFMLDuck.h"
#include "SFMLController.h"
#include "SFMLMENU.h"
#include "SFMLFINISH.h"
using namespace std;
int main()
{
    DuckBoard board(8,20);
    DuckController control(board);
    SFMLMENU menu(board);
    SFMLDuck view(board);
    SFMLController SFMLControl(board);
    SFMLFINISH finish(board);
    constexpr int screen_width = 1280;
    constexpr int screen_height = 769;
    sf::RenderWindow win(sf::VideoMode(screen_width,screen_height),"DuckHunt",sf::Style::Titlebar | sf::Style::Close);
    win.setVerticalSyncEnabled(true);
    int pom=0;
    sf::Cursor cursor;
    if(cursor.loadFromSystem(sf::Cursor::Cross))
        win.setMouseCursor(cursor);
    while (win.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;


        if(board.getGameState()==START)
        {
            win.clear(sf::Color::Black);
            menu.draw(win);
            menu.handleEvent(event,win);
            win.display();
            while (win.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    win.close();
            }

        }


        if(board.getGameState()==RUNNING)
        {
            while (win.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    win.close();
            }

            pom++;
            // zmienne do sprawdzenia
//            if(pom%100==0)
//            {
//                board.debug_display();
//            }
            if(pom%300==0)
            {
                board.duck_generator();
            }
            if(pom%5==0){
                board.update();
            }
            SFMLControl.handleEvent(event);
            // clear the window with black color
            win.clear(sf::Color::Black);

            // draw everything here...
            view.drawOnWindow(win);
            // end the current frame
            win.display();
        }
        if(board.getGameState()==FINISHED)
        {
            while (win.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    win.close();
            }
            finish.draw(win);
            finish.handleEvent(event,win);
            win.display();
        }



    }

    return 0;
}

