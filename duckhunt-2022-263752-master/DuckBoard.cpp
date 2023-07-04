
#include "DuckBoard.h"
#include <iostream>

#include <cstdlib>

using namespace std;

DuckBoard::DuckBoard(int height, int width) {
    start= true;
    auto start=sc.now();
    this->height=height;
    this->width=width;
    duck_generator();
    current_direction=RIGHT;
    GameStatus=RUNNING;
    points=0;
}
void DuckBoard::debug_display() const {

    for (int y = 0; y < height; ++y) {

        for (int x = 0; x < width; ++x) {
            cout <<"[";
            if (duck_cords(x, y)==1) {
                cout << "D";
            }
            else {
                std::cout << ".";
            }
            if(Flying_duck_cords(x,y)==1)
            {
                cout << "F";
            }
            else {
                std::cout << ".";
            }
            std::cout << "]";

        }

        cout << endl;
    }
}
//funkcja sprawdzajaca cordy kaczki
bool DuckBoard::duck_cords(int x, int y) const {
    for(int i=0; i<duck.size();i++)
    {
        if (duck[i].first == x and duck[i].second == y)
        {

            return true;
        }
    }
    return false;
}
//funkcja sprawdzajaca cordy kaczki latajacej
bool DuckBoard::Flying_duck_cords(int x, int y) const {
    for(const auto & i : Flying_duck)
    {
        if (i.first == x and i.second == y)
        {

            return true;
        }
    }
    return false;
}

//Funkcja pozwalajaca strzelanie do kaczek
void DuckBoard::shot(int x, int y) {
    for(int i=0;i<duck.size();i++) {
        if (duck[i].first == x && duck[i].second == y) {
            duck.erase(duck.begin() + i);
            points++;

        }
    }
    for(int i=0;i<Flying_duck.size();i++)
        if (Flying_duck[i].first == x and Flying_duck[i].second == y)
        {
            Flying_duck.erase(duck.begin() + i);
            points++;
        }
}
//próba dodania punktów ujemnych lecz traciło się 10 punktow za nietrafenie wiec dałem spokój z tym
void DuckBoard::miss(int x,int y) {
    if(!duck_cords(x,y) or !Flying_duck_cords(x,y))
    {
        points--;
    }
}
//aktualizowanie pozycji kaczki
bool DuckBoard::update() {
    for(int i=0; i < Flying_duck.size(); i++){
        int x=Flying_duck[i].first;
        int y=Flying_duck[i].second;

        if (x< GetBoardWidth() && current_direction==RIGHT)
        {
            x=x+1;
            Flying_duck.pop_back();
            Flying_duck.insert(Flying_duck.begin(), {x, y});
        }
        if (x>= GetBoardWidth() && current_direction==RIGHT)
        {
            current_direction=LEFT;
            x=x-1;
            Flying_duck.pop_back();
            Flying_duck.insert(Flying_duck.begin(), {x, y});
        }
        if (x< GetBoardWidth() && current_direction==LEFT)
        {
            x=x-1;
            Flying_duck.pop_back();
            Flying_duck.insert(Flying_duck.begin(), {x, y});
        }
        if (x<0 && current_direction==LEFT)
        {
            current_direction=RIGHT;
            x=x+1;
            Flying_duck.pop_back();
            Flying_duck.insert(Flying_duck.begin(), {x, y});
        }
    }


    return false;
}
GameState DuckBoard::getGameState() const
{
    if(points==50)
        return FINISHED;
    else if(start)
        return START;
    else
        return RUNNING;
}


void DuckBoard::duck_generator()
{
    int x=rand()%width;
    int y=rand()%height;
    int z=6;
    if(points==15)
    {
        z=10;
    }
    if(points==10)
    {
        z=8;
    }
    if (duck.size()<z )
    {
       duck.emplace_back(x,y);

       duck_generator();
    }
    if (Flying_duck.size() < 2)
    {
        Flying_duck.emplace_back(0, y);
        duck_generator();
    }

}




void DuckBoard::StartGame() {
    GameStatus=RUNNING;
    start = false;
}
int DuckBoard::GetBoardWidth() const {
    return width;
}
int DuckBoard::GetBoardHeight() const {
    return height;
}
int DuckBoard::getPoints() const {
    return points;
}
int DuckBoard::GetFieldInfo(int x, int y) const {
    if (duck_cords(x,y)) {
        return 0;
    }  if (Flying_duck_cords(x,y)) {
        return 1;
    }
}
Direction DuckBoard::GetDirection() {
    return current_direction;
}
