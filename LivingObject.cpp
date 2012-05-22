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
        if(getYPos()-1 >= 0 && getTileMap()->getTile(getXPos(),getYPos()-1)->getWalkAble()){
                sprite->move(0,-FRAME_HEIGHT);
                this->setPos(getXPos(),getYPos()-1,false);
        }
    }else if(direction == 1){
        if(getXPos()+1 <= 5 && getTileMap()->getTile(getXPos()+1,getYPos())->getWalkAble()){
                sprite->move(FRAME_WIDTH,0);
                this->setPos(getXPos()+1,getYPos(),false);
        }
    }else if(direction == 2){
        if(getYPos()+1 <= 5 && getTileMap()->getTile(getXPos(),getYPos()+1)->getWalkAble()){
                sprite->move(0,FRAME_HEIGHT);
                this->setPos(getXPos(),getYPos()+1,false);
        }
    }else if(direction == 3){
        if(getXPos()-1 >= 0 && getTileMap()->getTile(getXPos()-1,getYPos())->getWalkAble()){
                sprite->move(-FRAME_WIDTH,0);
                this->setPos(getXPos()-1,getYPos(),false);
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


