#include "Point.h"

Point::Point(int x,int y){
    this->x = x;
    this->y = y;
}
Point::Point(){
    this->x = 0;
    this->y = 0;
}
int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}
void Point::setX(int x){
    this->x = x;
}
void Point::setY(int y){
    this->y = y;
}
void Point::setPoint(int x, int y){
    this->x = x;
    this->y = y;
}
bool Point::samePoint(Point p){
    if(p.getX() == this->x && p.getY() == this->y){
        return true;
    }else{
        return false;
    }
}

