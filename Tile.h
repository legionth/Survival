/* 
 * File:   Tile.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:57
 */

#ifndef TILE_H
#define	TILE_H
#include "LivingObject.h"
#include "Ressource.h"

class LivingObject;
//class Ressource;

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
    void setLivingObject(LivingObject* o);
    void setRessource(Ressource* ressource);
    void removeRessource();
    
    LivingObject* getLivingObject();
    Ressource* getRessource();
    bool getWalkAble();
    bool getDestroyAble();
    
private:
    int xPos;
    int yPos;
    char identifier;
    LivingObject* object;
    Ressource* ressource;
    
    bool destroyAble;
    bool walkAble;
    
};

#endif	/* TILE_H */

