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
  //std::cout<<"clock"<<moveClock.getElapsedTime().asSeconds()<<std::endl;
    
    if(moveClock.getElapsedTime().asSeconds() > 0.25f){
        if(direction == MOVE_UP && (this->getYPos() - 1 >= 0 || this->getTileMap()->getYPos() - 1 >= 0)){
            if(this->getYPos() - 1 < 0 || getTileMap()->getTile(getXPos(),getYPos()-1)->getWalkAble() ){
                    sprite->move(0,-FRAME_HEIGHT);
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(0);

                    if(this->getYPos() - 1 < 0){                                        // Moving to next map                                                                              
                        if(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()-1)->getTile(getXPos(),4)->getWalkAble()){
                            this->setTileMap(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()-1));
                            this->setPos(getXPos(),4);
                        }
                        else{                                                           // Moving on current map
                            sprite->move(0,FRAME_HEIGHT);
                            this->setPos(getXPos(),0);
                        } 
                    }else{
                       this->setPos(getXPos(),getYPos()-1,false);
                    }
                    
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    this->startAnimation(5,8);                
            }
        }else if(direction == MOVE_RIGHT && (this->getXPos() + 1 <= 4  || this->getTileMap()->getXPos() + 1 <= 4 )){
            if(this->getXPos() + 2 > 4 || getTileMap()->getTile(getXPos() + 1,getYPos())->getWalkAble()){
                    sprite->move(FRAME_WIDTH,0);
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(0);
                    
                    if(this->getXPos() + 1 > 4){
                        if(world->getTileMap(getTileMap()->getXPos()+1,getTileMap()->getYPos())->getTile(0,getYPos())->getWalkAble()){
                            this->setTileMap(world->getTileMap(getTileMap()->getXPos()+1,getTileMap()->getYPos()));
                            this->setPos(0,getYPos());
                        }
                        else{
                            sprite->move(-FRAME_WIDTH,0);
                            this->setPos(4,getYPos());
                        }
                   }else{
                        this->setPos(getXPos()+1,getYPos(),false);
                   }
                    
                   this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    
                   this->startAnimation(9,12);
            }
        }else if(direction == MOVE_DOWN && (this->getYPos() + 1 <= 4  || this->getTileMap()->getYPos() + 1 <= 4 )){
            if(this->getYPos() + 1 >= 4 || getTileMap()->getTile(getXPos(),getYPos()+1)->getWalkAble()){
                    sprite->move(0,FRAME_HEIGHT);
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(0);
                    
                    if(this->getYPos() + 1 > 4){
                        if(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()+1)->getTile(getXPos(),0)->getWalkAble()){
                            this->setTileMap(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()+1));
                            this->setPos(getXPos(),0);
                        }else{
                            sprite->move(0,-FRAME_HEIGHT);
                            this->setPos(getXPos(),4);
                        }
                    }else{
                        this->setPos(getXPos(),getYPos()+1,false);
                    }
                    
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    
                    this->startAnimation(1,4);
            }
        }else if(direction == MOVE_LEFT && (this->getXPos() - 1 >= 0 || this->getTileMap()->getXPos() - 1 >= 0)){
            if(this->getXPos() - 1 < 0 || getTileMap()->getTile(getXPos()-1,getYPos())->getWalkAble()){
                    sprite->move(-FRAME_WIDTH,0);
                    
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(0);
                    
                    if(this->getXPos() - 1 < 0){
                        if(world->getTileMap(getTileMap()->getXPos()-1,getTileMap()->getYPos())->getTile(4,getYPos())->getWalkAble()){
                            this->setTileMap(world->getTileMap(getTileMap()->getXPos()-1,getTileMap()->getYPos()));
                            this->setPos(4,getYPos());
                        }else{
                            sprite->move(FRAME_WIDTH,0);
                            this->setPos(0,getYPos());
                        }
                    }else{
                        this->setPos(getXPos()-1,getYPos(),false);
                    }
                    
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    
                    this->startAnimation(13,16);
            }        
        }
        moveClock.restart(); 
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


