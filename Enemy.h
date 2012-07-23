/* 
 * File:   Enemy.h
 * Author: niels
 *
 * Created on 20. Juni 2012, 13:48
 */

#ifndef ENEMY_H
#define	ENEMY_H
#include "LivingObject.h"
#include "Dropable.h"

#include <cstdlib>
#include <iostream>


class Enemy : public LivingObject, public Dropable{
    
public:
    Enemy(TileMap* tilemap, int posX, int posY, sf::Texture* texture,int frameRect,int id, sf::Texture *ressourceTex);
    virtual ~Enemy();
    void setBeheavior(int b);
    int getBehavior();
    void execute(World* world);
    
    int getId();
    void setId(int i);          // Also sets Behavior
private:
    int behavior;
    int id;
    sf::Clock passiveClock;
};

#endif	/* ENEMY_H */

