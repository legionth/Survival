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
<<<<<<< HEAD

=======
>>>>>>> abfa2e8395288c787bdd2735fa5c3bc8a6fdf270
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
<<<<<<< HEAD
    int getWalkIterator();
    bool haveToWalk();
    TileMap* getTileMap();
    
    // set Attributes
    void setSpeed(int speed);                           //@TODO: calculate speed with move function
    void setAttackPower(int atk);
    void setDefense(int def);
    void setTileMap(TileMap* tileMap);
    void resetWalkIterator();                   // Set to 0
    void setToWalk(bool walk);
protected:
    void setWalkIterator(int i);

=======
    TileMap* getTileMap();
    
    // set Attributes
    void setSpeed(int speed);
    void setAttackPower(int atk);
    void setDefense(int def);
    void setTileMap(TileMap* tileMap);
>>>>>>> abfa2e8395288c787bdd2735fa5c3bc8a6fdf270
private:
    int currentDirection;
    int currentFrame;
    
    int speed;
    int attackPower;
    int defense;
    int agility;
    
    TileMap* currentTileMap;
    sf::Clock moveClock;
<<<<<<< HEAD
    int walkIterator;
    bool toWalk;
    
=======
>>>>>>> abfa2e8395288c787bdd2735fa5c3bc8a6fdf270
};

#endif	/* LIVINGOBJECT_H */

