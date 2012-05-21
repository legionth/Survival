/* 
 * File:   Tile.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:57
 */

#ifndef TILE_H
#define	TILE_H
#include "LivingObject.h"

class LivingObject;
class Tile : public GameObject{
public:
    Tile(sf::Texture* img, int x,int y);
    Tile(char c);
    Tile(const Tile& orig);
    virtual ~Tile();
    char getIdentifier();
    void setIdentifier(char id);
    void setWalkAble(bool walkable);
    void setDestroyAble(bool destroyable);
    LivingObject* getLivingObject();
    
    bool getWalkAble();
    bool getDestroyAble();
    
private:
    int xPos;
    int yPos;
    char identifier;
    LivingObject* object;
    
    bool destroyAble;
    bool walkAble;
    
};

#endif	/* TILE_H */

