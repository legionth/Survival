/* 
 * File:   Tile.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:57
 */

#ifndef TILE_H
#define	TILE_H
#include "GameObject.h"
class Tile : public GameObject{
public:
    Tile();
    Tile(char c);
    Tile(const Tile& orig);
    virtual ~Tile();
    char getIdentifier();
    void setIdentifier(char id);
    GameObject* getObject();
private:
    char identifier;
    GameObject* object;
};

#endif	/* TILE_H */

