/* 
 * File:   Enemy.h
 * Author: niels
 *
 * Created on 20. Juni 2012, 13:48
 */

#ifndef ENEMY_H
#define	ENEMY_H
#include "LivingObject.h"
#include <cstdlib>
#include <iostream>


class Enemy : public LivingObject {
public:
    Enemy(TileMap* tilemap, int posX, int posY, sf::Texture* texture,int frameRect,int id, sf::Texture *ressourceTex);
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    void setBeheavior(int b);
    int getBehavior();
    void execute(World* world);
    void drop();
    
    int getId();
    void setId(int i);          // Also sets Behavior
private:
    int behavior;
    std::vector<int> dropList;
    
    int id;
    sf::Clock passiveClock;
    sf::Texture* ressourceTex;
};

#endif	/* ENEMY_H */

