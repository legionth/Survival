/* 
 * File:   World.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:55
 */

#ifndef WORLD_H
#define	WORLD_H
#include "TileMap.h"

class World {
public:
    World(sf::Texture* img);
    World(const World& orig);
    virtual ~World();
    TileMap* getTileMap(int x,int y);
    
    int getXSize();
    int getYSize();
private:
    std::vector<std::vector<TileMap*> > tileMap;
    int xSize;
    int ySize;

};

#endif	/* WORLD_H */

