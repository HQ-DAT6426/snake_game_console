#pragma once
#include "Point.h"
#include <deque>

class Snake{
private:
    std::deque<Point> body;
    int directionX;
    int directionY;
public:
    Snake(int h, int w);
    Point getHeadPoint();
    void moveDir(bool ateFood);
    void setDirection(char ch);
    bool isBody(Point p);
    std::deque<Point> getBody();
};
