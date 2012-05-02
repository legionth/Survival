/* 
 * File:   LivingObject.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:45
 */

#ifndef LIVINGOBJECT_H
#define	LIVINGOBJECT_H
#include "GameObject.h"
#include "TileMap.h"

class LivingObject : public GameObject{
public:
    LivingObject();
    LivingObject(int frame);
    LivingObject(const LivingObject& orig);
    virtual ~LivingObject();
    
    void startAnimation();
    void stopAnimation();
    void move(int direction);
    
    int getCurrentDirection();
    int getCurrentFrame();
    
    void setCurrentDirection(int direction);
    // getAttribute
    int getSpeed();
    int getAttackPower();
    int getDefense();
    TileMap* getTileMap();
    
    // set Attributes
    void setSpeed(int speed);
    void setAttackPower(int atk);
    void setDefense(int def);
    void setTileMap(TileMap* TileMap);
    
private:
    int currentDirection;
    int currentFrame;
    
    int speed;
    int attackPower;
    int defense;
    int agility;
    
    TileMap* currentTileMap;
};

#endif	/* LIVINGOBJECT_H */

