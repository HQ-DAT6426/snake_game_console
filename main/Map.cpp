#include <vector>
#include "Map.h"
#include "Point.h"

Map::Map(){
    this->width = 50;
    this->height = 50;
    Wall = std::vector<std::vector<bool>> (height, std::vector<bool>(width,false));
    Map::createMap();
}
Map::Map(int w,int h){
    if(w<=0 ||h<=0){
        this->width = 50;
        this->height = 50;
    }else{
        this->width = w;
        this->height = h;
    }
    Wall = std::vector<std::vector<bool>> (height, std::vector<bool>(width,false) );
    Map::createMap();
}
void Map::createMap(){
    for(int i = 0;i<height;i++){
        Wall[i][0] = true;
        Wall[i][width-1] = true;
    }
    for(int j = 0;j<width;j++){
        Wall[0][j] = true;
        Wall[height-1][j] = true;
    }
}
bool Map::isWall(Point posHead){

    return Wall[posHead.getY()][posHead.getX()];
}
int Map::getW(){
    return width;
}
int Map::getH(){
    return height;
}
