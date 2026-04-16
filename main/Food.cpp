#include<cstdlib>
#include <ctime>
#include "Point.h"
#include "Food.h"

void Food::createFood(int h, int w){
    srand(time(NULL));
    int randomW = 1 + rand() % (w-2);
    int randomH = 1 + rand() % (h-2);
    pos.setPoint(randomH,randomW);
}
Food::Food(int h, int w){
    createFood(h,w);
}

bool Food::isFood(Point posHead){
    if(posHead.getX() == pos.getX() && posHead.getY() == pos.getY()) return true;
    else return false;
}
void Food::deleteFood(){
    pos.setPoint(-1,-1);
}
Point Food::getPosFood(){
    return pos;
}
