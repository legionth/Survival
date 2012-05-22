/* 
 * File:   LivingObject.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:45
 */

#include "LivingObject.h"

LivingObject::LivingObject() {
}

LivingObject::LivingObject(const LivingObject& orig) {
}

LivingObject::~LivingObject() {
}

void LivingObject::move(int direction){
    sf::Sprite *sprite = this->getSprite();
    
    if(direction == 0){
        sprite->move(0,-128);
        this->setPos(getXPos(),getYPos()-1,false);
    }else if(direction == 1){
        sprite->move(128,0);
        this->setPos(getXPos()+1,getYPos(),false);
    }else if(direction == 2){
        sprite->move(0,128);
        this->setPos(getXPos(),getYPos()+1,false);
    }else if(direction == 3){
        sprite->move(-128,0);
        this->setPos(getXPos()-1,getYPos(),false);
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


