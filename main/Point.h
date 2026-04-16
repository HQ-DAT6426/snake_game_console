#pragma once
class Point{
private:
    int x;
    int y;
public:
    Point(int x,int y);
    Point();
    bool samePoint(Point p);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setPoint(int x, int y);
};
