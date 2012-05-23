/* 
 * File:   LivingObject.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:45
 */

#include "LivingObject.h"
#include "World.h"
#include <iostream>
LivingObject::LivingObject() {
}

LivingObject::LivingObject(const LivingObject& orig) {
}

LivingObject::~LivingObject() {
}

void LivingObject::move(int direction,World *world){
    sf::Sprite *sprite = this->getSprite();
    if(direction == MOVE_UP){
        if(this->getYPos() - 1 < 0 || getTileMap()->getTile(getXPos(),getYPos()-1)->getWalkAble()){
                sprite->move(0,-FRAME_HEIGHT);
                if(this->getYPos() - 1 < 0){
                    this->setTileMap(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()-1));
                    this->setPos(getXPos(),4);
                }else{
                   this->setPos(getXPos(),getYPos()-1,false); 
                }
        }
    }else if(direction == MOVE_RIGHT){
        if(this->getXPos() + 2 > 4 || getTileMap()->getTile(getXPos()+1,getYPos())->getWalkAble()){
                sprite->move(FRAME_WIDTH,0);
                
                if(this->getXPos() + 1 > 4){
                    this->setTileMap(world->getTileMap(getTileMap()->getXPos()+1,getTileMap()->getYPos()));
                    this->setPos(0,getYPos());
               }else{
                    this->setPos(getXPos()+1,getYPos(),false);
               }
        }
    }else if(direction == MOVE_DOWN){
        if(this->getYPos() + 1 >= 4 || getTileMap()->getTile(getXPos(),getYPos()+1)->getWalkAble()){
                sprite->move(0,FRAME_HEIGHT);
                
                if(this->getYPos() + 1 > 4){
                    this->setTileMap(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()+1));
                    this->setPos(getXPos(),0);
                }else{
                    this->setPos(getXPos(),getYPos()+1,false);
                }
        }
    }else if(direction == MOVE_LEFT){
        if(this->getXPos() - 1 < 0 || getTileMap()->getTile(getXPos()-1,getYPos())->getWalkAble()){
                sprite->move(-FRAME_WIDTH,0);
                if(this->getXPos() - 1 < 0){
                    this->setTileMap(world->getTileMap(getTileMap()->getXPos()-1,getTileMap()->getYPos()));
                    this->setPos(4,getYPos());
                }else{
                    this->setPos(getXPos()-1,getYPos(),false);
                }
        }        
    }
}
    
int LivingObject::getCurrentDirection(){
    return this->currentDirection;
}
    
void LivingObject::setCurrentDirection(int direction){
    this->currentDirection = direction;
}

int LivingObject::getSpeed(){
    return this->speed;
}

int LivingObject::getAttackPower(){
    return this->attackPower;
}

int LivingObject::getDefense(){
    return this->defense;
}

TileMap* LivingObject::getTileMap(){
    return this->currentTileMap;
}
    
// set Attributes
void LivingObject::setSpeed(int speed){
    this->speed = speed;
}

void LivingObject::setAttackPower(int atk){
    this->attackPower = atk;
}

void LivingObject::setDefense(int def){
    this->defense = def;
}

void LivingObject::setTileMap(TileMap* tileMap){
    this->currentTileMap = tileMap;
}


