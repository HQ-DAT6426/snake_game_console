#pragma once
#include "Map.h"
#include "Snake.h"
#include "Food.h"

class ControlGame{
private:
    Map m;
    Food f;
    Snake s;
    int record;
    bool isGameover;
public:
    ControlGame();
    ControlGame(int h, int w);
    bool SameFoodBody();
    bool hitWall(Point head);
    void startGame();
    void handleInput();
    void update();
    void draw();
    void gotoXY(int x,int y);
};
