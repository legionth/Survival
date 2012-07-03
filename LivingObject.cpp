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
    this->setCurrentDirection(MOVE_DOWN);
    toWalk = false;
}

LivingObject::LivingObject(const LivingObject& orig) {
}

LivingObject::~LivingObject() {
}
/**
 *  Don't touch it is working ...
 * @param direction
 * @param world         - need to get next TileMap
 */
void LivingObject::move(int direction,World *world){
    sf::Sprite *sprite = this->getSprite();
    
    
    if(moveClock.getElapsedTime().asSeconds() > 0.15f){
        if(direction == MOVE_UP && (this->getYPos() - 1 >= 0 || this->getTileMap()->getYPos() - 1 >= 0)){
            if(this->getYPos() - 1 < 0 || getTileMap()->getTile(getXPos(),getYPos()-1)->getWalkAble() ){
                  //  sprite->move(0,-FRAME_HEIGHT);
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(0);

                    if(this->getYPos() - 1 < 0){  
                        // Moving to next map                                                                              
                        if(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()-1)->getTile(getXPos(),4)->getWalkAble()){
                            this->setTileMap(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()-1));
                            this->setPos(getXPos(),4);
                            resetWalkIterator();
                            //this->setSpritePosition(getXPos() * getWalkIterator() ,getYPos() * FRAME_WIDTH); 
                        }
                        else{                                                           // Moving on current map
                            sprite->move(0,FRAME_HEIGHT);
                            this->setPos(getXPos(),0);
                            resetWalkIterator();
                           // this->setSpritePosition(getXPos() * getWalkIterator(),0);
                        } 
                        
                    }else{
                        
                        if(this->getWalkIterator() + WALK_ITERATOR == FRAME_WIDTH){
                                this->setPos(getXPos(),getYPos()-1,false);              // Ursprünglich
                        }else{
                            //this->setSpritePosition(getXPos() * FRAME_WIDTH ,getYPos() * FRAME_HEIGHT - getWalkIterator());
                            this->getSprite()->move(0,-WALK_ITERATOR);
                        }
                        
                    }
                    
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    this->startAnimation(5,8); 
                    this->setCurrentDirection(MOVE_UP);
            }
        }else if(direction == MOVE_RIGHT && (this->getXPos() + 1 <= 4  || this->getTileMap()->getXPos() + 1 <= 4 )){
            if(this->getXPos() + 1 >= 5 || getTileMap()->getTile(getXPos() + 1,getYPos())->getWalkAble()){
                   // sprite->move(FRAME_WIDTH,0);
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(0);
                    
                    if(this->getXPos() + 1 > 4){
                        
                        if(world->getTileMap(getTileMap()->getXPos()+1,getTileMap()->getYPos())->getTile(0,getYPos())->getWalkAble()){
                            this->setTileMap(world->getTileMap(getTileMap()->getXPos()+1,getTileMap()->getYPos()));
                            this->setPos(0,getYPos());
                            resetWalkIterator();
                        }
                        else{
                            sprite->move(-FRAME_WIDTH,0);
                            this->setPos(4,getYPos());
                            resetWalkIterator();
                        }
                        
                   }else{
                        
                        if(this->getWalkIterator() + WALK_ITERATOR == FRAME_WIDTH){
                            this->setPos(getXPos()+1,getYPos(),false);              // Ursprünglich
                        }else{
                            this->getSprite()->move(WALK_ITERATOR,0);
                        }
                        
                   }
                    
                   this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    
                   this->startAnimation(9,12);
                   this->setCurrentDirection(MOVE_RIGHT);
            }
        }else if(direction == MOVE_DOWN && (this->getYPos() + 1 <= 4  || this->getTileMap()->getYPos() + 1 <= 4 )){
                                        //std::cout<<"start: WALK_ITERATOR"<<WALK_ITERATOR<<"x"<<this->getSprite()->getPosition().x<<"y"<<this->getSprite()->getPosition().y<<std::endl;

            if(this->getYPos() + 1 >= 5 || getTileMap()->getTile(getXPos(),getYPos()+1)->getWalkAble()){
                   // sprite->move(0,FRAME_HEIGHT);
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(0);
                    
                    if(this->getYPos() + 1 > 4){
                        
                        if(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()+1)->getTile(getXPos(),0)->getWalkAble()){
                            this->setTileMap(world->getTileMap(getTileMap()->getXPos(),getTileMap()->getYPos()+1));
                            this->setPos(getXPos(),0);
                            resetWalkIterator();
                        }else{
                            sprite->move(0,-FRAME_HEIGHT);
                            this->setPos(getXPos(),4);
                            resetWalkIterator();
                        }
                        
                    }else{
                        
                        if(this->getWalkIterator() + WALK_ITERATOR == FRAME_WIDTH){
                            this->setPos(getXPos(),getYPos()+1,false);              // Ursprünglich
                        }else{
                            this->getSprite()->move(0,WALK_ITERATOR);
                        }
                        
                    }
                    
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    
                    this->startAnimation(1,4);
                    this->setCurrentDirection(MOVE_DOWN);
            }
        }else if(direction == MOVE_LEFT && (this->getXPos() - 1 >= 0 || this->getTileMap()->getXPos() - 1 >= 0)){
            if(this->getXPos() - 1 < 0 || getTileMap()->getTile(getXPos()-1,getYPos())->getWalkAble()){
                  //  sprite->move(-FRAME_WIDTH,0);
                    
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
                        
                        if(this->getWalkIterator() + WALK_ITERATOR == FRAME_WIDTH){
                            this->setPos(getXPos()-1,getYPos(),false);              // Ursprünglich
                        }else{
                            this->getSprite()->move(-WALK_ITERATOR,0);
                        }
                        
                    }
                    
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    
                    this->startAnimation(13,16);
                    this->setCurrentDirection(MOVE_LEFT);
            }        
        }
        
        if(getWalkIterator() >= FRAME_WIDTH){
            resetWalkIterator();
        }else{
            setWalkIterator(getWalkIterator() + WALK_ITERATOR);
            setToWalk(true);
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

int LivingObject::getWalkIterator(){
    return this->walkIterator;
}

void LivingObject::setWalkIterator(int i){
    this->walkIterator = i;
}


void LivingObject::resetWalkIterator(){
    this->walkIterator = 0;
    setToWalk(false);
}   

bool LivingObject::haveToWalk(){
    return this->toWalk;
}

void LivingObject::setToWalk(bool walk){
    this->toWalk = walk;
}
