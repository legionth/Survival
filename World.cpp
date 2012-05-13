/* 
 * File:   World.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:55
 */

#include "World.h"
#include <iostream>
World::World() {
    // Must be done like this, not sure if there is another way
    tileMap.resize(5);
    for(int i = 0; i < 5;i++){
        tileMap[i].resize(5);
    }
    
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            tileMap[y][x] = new TileMap(x,y);
            std::cout<<"here?"<<std::endl;
        }
    }
}

World::World(const World& orig) {
}

World::~World() {
}

