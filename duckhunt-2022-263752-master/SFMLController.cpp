//
// Created by OMEGAPEPE on 19.06.2022.
//
#include <iostream>
#include "SFMLController.h"
SFMLController::SFMLController(DuckBoard &b):board(b)
{

}
void SFMLController::handleEvent(sf::Event &event) {


        if(event.type == sf::Event::MouseButtonPressed)
        {
            int mouse_y = (event.mouseButton.y)/85;
            int mouse_x = (event.mouseButton.x)/40;

            if (event.mouseButton.button == sf::Mouse::Left)
            {
//                std::cout << "mouse x: " << event.mouseButton.x << std::endl; // testowalem polozenie myszy
//                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
//                std::cout << mouse_y << std::endl;
//                board.debug_display() ;
//                std::cout << mouse_x;

                    board.shot(mouse_x,mouse_y);
            }
        }

}