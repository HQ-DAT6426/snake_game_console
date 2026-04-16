#pragma once
#include <vector>
#include "Point.h"

class Map{
private:
    int width;
    int height;
    std::vector<std::vector<bool>> Wall;
    void createMap();
public:
    Map();
    Map(int w,int h);
    bool isWall(Point posHead);
    int getW();
    int getH();
};
