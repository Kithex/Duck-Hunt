//
// Created by OMEGAPEPE on 17.06.2022.
//

#include <sstream>
#include "SFMLDuck.h"

using namespace std;
SFMLDuck::SFMLDuck(DuckBoard &b) :board(b) {
    if (!font.loadFromFile("../files/arial.ttf"))
        abort();
    text.setFont(font);
    text.setFillColor(sf::Color::Green);
    score.setFont(font);
    score.setFillColor(sf::Color::Black);
    score.setPosition(50,50);
    field = sf::RectangleShape(sf::Vector2f(30, 30));
    sf::Color kolor(161, 131, 242);
    field.setFillColor(kolor);
   shape= sf::RectangleShape(sf::Vector2f(1,769));
   shape.setFillColor(sf::Color::Black);
   shape.setPosition(791,0);
    if(!tex_duck.loadFromFile("../files/duckhunt.png"));
    if(!texture.loadFromFile("../files/stage.png"))
    {
        abort();
    }
    if(!Background2.loadFromFile("../files/stage1.png")){
        abort();
    }
    if(!Duck_texture.loadFromFile("../files/flyinduckhunt.png"))
        abort();
}
void SFMLDuck::drawOnWindow(sf::RenderWindow &win) {
    constexpr int screen_width = 1280;
    constexpr int screen_height = 769;



    sf::Sprite background(texture);



    sf::Sprite tDuck(Duck_texture);

    sf::Sprite duck(tex_duck);



   sf::Sprite background2(Background2);

   background2.setPosition(791,0);
    win.draw(background);
    win.draw(background2);
    win.draw(shape);

    for(int col=0;col<board.GetBoardWidth();col++)
    {
        for(int row=0;row<board.GetBoardHeight();row++)
        {
            double x;
            double y;
            y = (screen_height / board.GetBoardHeight() * row / 1.1);
            x = (screen_width / board.GetBoardWidth() * col / 1.6);

            if(board.Flying_duck_cords(col,row)== 1)
            {
                tDuck.setPosition(x,y);
                win.draw(tDuck);
                }
            else if(board.duck_cords(col,row)== 1)
            {
                duck.setPosition(x,y);
                win.draw(duck);
            }

        }
    }
    text.setString("SCORE");
    text.setCharacterSize(50);
    text.setPosition(958,50);
    text.setFillColor(sf::Color::Black);
    win.draw(text);

    std::stringstream ss;
    ss << board.getPoints();
    score.setCharacterSize(50);
    score.setString(ss.str().c_str()); //używałem tego kodu w sneaku również, a pochodzi ze strony https://en.sfml-dev.org/forums/index.php?topic=8368.0
    score.setPosition(1035,105);

    win.draw(score);
    if (board.getGameState() == FINISHED) {

        win.clear(sf::Color::Yellow);
        text.setString("WINNER!");
        text.setCharacterSize(50);
        text.setPosition(250, 100);
        win.draw(text);



    }
}