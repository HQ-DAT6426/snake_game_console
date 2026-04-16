#pragma once
#include "Point.h"

class Food{
private:
    Point pos;
public:
    Food(int h, int w);
    void createFood(int h, int w);
    bool isFood(Point posHead);
    void deleteFood();
    Point getPosFood();
};
