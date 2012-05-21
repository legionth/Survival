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

