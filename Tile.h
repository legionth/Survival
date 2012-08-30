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
#include "Building.h"

class LivingObject;
//class Dropable;
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
    void setRessource(Ressource* ressource,bool setPos);

    void setBuilding(Building* building);
    void removeRessource();
    
    LivingObject* getLivingObject();
    Ressource* getRessource();
    Building* getBuilding();
    bool isWalkAble();
    bool isDestroyAble();
    
    void drop(Tile* tile);              // Must be done like this, because include tiel in Dropable
    void addDrop(int id);
    void setRessourceTexture(sf::Texture* tex);
    void clearDropList();
    float getTime();
private:
    int xPos;
    int yPos;
    char identifier;
    LivingObject* object;
    Ressource* ressource;
    Building* building;
    bool destroyAble;
    bool walkAble;
    
    std::vector<int> dropList;
    sf::Texture* ressourceTex;
    sf::Clock despawnTimer;
};

#endif	/* TILE_H */

