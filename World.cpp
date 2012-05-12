/* 
 * File:   World.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:55
 */

#include "World.h"

World::World() {
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            tileMap[x][y] = new TileMap(x,y);
        }
    }
}

World::World(const World& orig) {
}

World::~World() {
}

