
#ifndef DUCKHUNT_DUCKCONTROLLER_H
#define DUCKHUNT_DUCKCONTROLLER_H
#include "DuckBoard.h"

class DuckController  {
    DuckBoard & board;
public:
    explicit DuckController(DuckBoard &b);
    void play();

};


#endif //DUCKHUNT_DUCKCONTROLLER_H
