/* 
 * File:   LivingObject.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:45
 */

#ifndef LIVINGOBJECT_H
#define	LIVINGOBJECT_H
#include "GameObject.h"
#include "World.h"
#include "TileMap.h"
#include <iostream>

class TileMap;
class World;

class LivingObject : public GameObject{
public:
    LivingObject();
    LivingObject(int frame);
    LivingObject(const LivingObject& orig);
    virtual ~LivingObject();
    
    void move(int direction,World *world);
    
    
    int getCurrentDirection();
    
    void setCurrentDirection(int direction);
    // getAttribute
    int getSpeed();
    int getAttackPower();
    int getDefense();
    int getWalkIterator();
    bool haveToWalk();
    bool haveToAttack();
    TileMap* getTileMap();
    Tile* getTile();
    
    // set Attributes
    void setSpeed(int speed);                           //@TODO: calculate speed with move function
    void setAttackPower(int atk);
    void setDefense(int def);
    void setTileMap(TileMap* tileMap);
    void resetWalkIterator();                   // Set to 0
    void setToWalk(bool walk);
    
    bool isAttacked();
    void setAttacked(bool b);
    int getDirectionRect();
    
    void attack(LivingObject* target);
    void attack(Tile* tile);
    
    void stopAttackAnimation();
    void setToAttack(bool b);
    
    void setPos(int x, int y);
    void setPos(int x, int y, bool setSprite);          // crap -.-
    
    float getAttackTime();
    void restartAttackTime();
    
    void setMaxLife(int maxLife);
    int getMaxLife();
protected:
    void setWalkIterator(int i);

private:
    int currentDirection;
    int currentFrame;
    
    
    // Attack stats
    int speed;
    int attackPower;
    int defense;
    int agility;
    bool attacked;
    
    TileMap* currentTileMap;
    sf::Clock moveClock;
    sf::Clock attackClock;
    int walkIterator;
    bool toWalk;
    bool toAttack;
    
    int maxLife;   
};

#endif	/* LIVINGOBJECT_H */

