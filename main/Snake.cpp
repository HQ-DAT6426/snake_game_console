
#include "Point.h"
#include <deque>
#include "Snake.h"

Snake::Snake(int h, int w){
    directionX = 0;
    directionY = -1;
    Point p = Point(h/2,w/2);
    for(int i =1;i<=3;i++){
        body.push_back(p);
        p = Point(body.back().getX()+directionX, body.back().getY()+directionY);
    }
}
Point Snake::getHeadPoint(){
    return body.back();
}
void Snake::moveDir( bool ateFood){
    Point p = Point(body.back().getX()+directionX, body.back().getY()+directionY);
    body.push_back(p);
    if(ateFood == false){
        body.pop_front();
    }
}
void Snake::setDirection(char ch){
    if(ch == 'a' && directionX == 0){
        directionX = -1;
        directionY = 0;
    }
    if( ch == 's' && directionY == 0){
        directionX = 0;
        directionY = 1;
    }
    if(ch == 'w' && directionY == 0){
        directionX = 0;
        directionY = -1;
    }
    if(ch == 'd' && directionX == 0){
        directionX = 1;
        directionY = 0;
    }
}
bool Snake::isBody(Point p){
    for(int i=0;i<body.size()-1;i++){
        if(body[i].samePoint(p)) return true;
    }
    return false;
}
std::deque<Point> Snake::getBody(){
    return body;
}
