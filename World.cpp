/* 
 * File:   World.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:55
 */

#include "World.h"
#include <iostream>
World::World(sf::Texture* img) {
    // Must be done like this, not sure if there is another way
    this->xSize = 5;
    this->ySize = 5;
    
    tileMap.resize(getYSize());
    for(int i = 0; i < getYSize();i++){
        tileMap[i].resize(getXSize());
    }
    
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            tileMap[y][x] = new TileMap(img,x,y);
        }
    }
}

World::World(const World& orig) {
}

World::~World() {
    tileMap.clear();
}

TileMap* World::getTileMap(int x,int y){
    return tileMap[x][y];
}

int World::getXSize(){
    return this->xSize;
}
int World::getYSize(){
    return this->ySize;
}

