/* 
 * File:   TileMap.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:57
 */
#include "Tile.h"
#include <fstream>
#ifndef TILEMAP_H
#define	TILEMAP_H

class Tile;
class TileMap {
public:
    TileMap(sf::Texture* img,int x, int y);
    TileMap(int x, int y);
    TileMap(const TileMap& orig);
    
    void loadTileMap(std::string fileName);
    int getXPos();
    int getYPos();
    
    void setXPos(int x);
    void setYPos(int y);
    
    int getXSize();
    int getYSize();
    void setIdentifierOnTile(int x, int y, char c);
    Tile* getTile(int x,int y);
    virtual ~TileMap();
    
    int getEnemyCounter();
    void increaseEnemyCounter();
private:
    std::vector<std::vector<Tile*> > tileMap;
    int xPos;
    int yPos;
    
    int xSize;
    int ySize;
    
    // counter the amount of the enemies on the tileMap
    int enemyCounter;
};

#endif	/* TILEMAP_H */

