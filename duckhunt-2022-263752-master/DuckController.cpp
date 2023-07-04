//
// Created by OMEGAPEPE on 16.06.2022.
//
#include <iostream>
#include "DuckController.h"
#include "DuckBoard.h"
#include "stdlib.h"
using namespace std;

DuckController::DuckController(DuckBoard &b) : board(b)
{

}
void DuckController::play() {
    while(1)
    {

        board.debug_display();
        int x,y;
        cout << "Wpisz parametry najpierw x pozniej y"<< endl;
       cin >> x;
//        cout << endl;
       cin >> y;
        board.duck_generator();
        board.shot(x,y);
        cout <<board.getPoints() << endl;
        board.update();

    }
}