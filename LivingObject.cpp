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
    bool changedMap = false;
    
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
                            changedMap = true;
                        }
                        else{                                                           // Moving on current map
                            sprite->move(0,FRAME_HEIGHT);
                            this->setPos(getXPos(),0);
                           // this->setSpritePosition(getXPos() * getWalkIterator(),0);
                        } 
                        
                    }else{
                        
                        if(this->getWalkIterator() >= FRAME_WIDTH){
                                this->setPos(getXPos(),getYPos()-1,true);              // Ursprünglich
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
                            changedMap = true;               
                        }
                        else{
                            sprite->move(-FRAME_WIDTH,0);
                            this->setPos(4,getYPos());
                        }
                        
                   }else{
                        
                        if(this->getWalkIterator() >= FRAME_WIDTH){
                            this->setPos(getXPos()+1,getYPos(),true);              // Ursprünglich
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
                            changedMap = true;
                        }else{
                            sprite->move(0,-FRAME_HEIGHT);
                            this->setPos(getXPos(),4);
                        }
                        
                    }else{
                        
                        if(this->getWalkIterator() >= FRAME_WIDTH){
                            this->setPos(getXPos(),getYPos()+1,true);              // Ursprünglich
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
                            changedMap = true;
                        }else{
                            sprite->move(FRAME_WIDTH,0);
                            this->setPos(0,getYPos());
                        }
                        
                    }else{
                        if(this->getWalkIterator() >= FRAME_WIDTH){
                            this->setPos(getXPos()-1,getYPos(),true);              // Ursprünglich
                        }else{
                            this->getSprite()->move(-WALK_ITERATOR,0);
                        }
                        
                    }
                    
                    this->getTileMap()->getTile(getXPos(),getYPos())->setLivingObject(this);
                    
                    this->startAnimation(13,16);
                    this->setCurrentDirection(MOVE_LEFT);
            }        
        }
        
        if(getWalkIterator() >= FRAME_WIDTH || changedMap){                                   //@TODO: Iterate everytime. Stop this !
            resetWalkIterator();
            stopAnimation();
        }else{
            setWalkIterator(getWalkIterator() + WALK_ITERATOR);
            setToWalk(true);
        }
        moveClock.restart();
    }
    
    switch(direction){
        case MOVE_UP:
            setCurrentDirection(MOVE_UP);
           break;
        case MOVE_DOWN:
            setCurrentDirection(MOVE_DOWN);
            break;
        case MOVE_RIGHT:
            setCurrentDirection(MOVE_RIGHT);
            break;
        case MOVE_LEFT:
            setCurrentDirection(MOVE_LEFT);
            break;        
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

bool LivingObject::isAttacked(){
    return this->attacked;
}

void LivingObject::setAttacked(bool b){
    this->attacked = b;
}

int LivingObject::getDirectionRect(){
    int ret = 0;
    
    switch (getCurrentDirection()){
        case MOVE_UP:
            ret = RECT_UP_START;
            break;
        case MOVE_DOWN:
            ret = RECT_DOWN_START;
            break;
        case MOVE_LEFT:
            ret = RECT_LEFT_START;
            break;
        case MOVE_RIGHT:
            ret = RECT_RIGHT_START;
            break;
        default:
            break;
   }
    
   return ret;
}