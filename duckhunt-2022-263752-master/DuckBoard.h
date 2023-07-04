//
// Created by OMEGAPEPE on 02.06.2022.
//

#ifndef DUCKHUNT_DUCKBOARD_H
#define DUCKHUNT_DUCKBOARD_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
enum GameState{RUNNING,START,FINISHED};
enum Direction{LEFT,RIGHT};

class DuckBoard {
    int width;  //ilość wartości w wektorze
    int height;
    std::chrono::steady_clock sc;

    bool start;

    std::vector<std::pair <int,int>> duck;
    std::vector<std::pair <int,int>> Flying_duck;

    Direction current_direction;
    int points;
    GameState GameStatus;

public:

    DuckBoard(int height, int width);
    void debug_display() const;
    //porusznie sie kaczki latajacej
    bool update();
   // tworzenie kaczek
    void duck_generator();
    void miss(int x,int y);
    //gettery
    int getPoints() const;
    int GetBoardHeight() const;
    int GetBoardWidth() const;
    int GetFieldInfo(int x,int y) const;
    bool Flying_duck_cords(int x,int y) const;
    bool duck_cords(int x,int y) const;
    void StartGame();

    //funkcje by kaczka zmienila strone lotu po dojściu do końca
    Direction GetDirection();
    GameState getGameState() const;

    void shot(int x,int y);


};


#endif //DUCKHUNT_DUCKBOARD_H
