/* 
 * File:   Tile.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:57
 */

#include <stddef.h>
#include <iostream>
#include "Tile.h"

Tile::Tile(sf::Texture* img, int x,int y) {
    object = NULL;
    this->xPos = x;
    this->yPos = y;
    getSprite()->setPosition(128*x,128*y);
    this->setImage(img);
    setWalkAble(true);
    setDestroyAble(false);
}

Tile::Tile(char c) {
    object = NULL;
    setIdentifier(c);
}

Tile::Tile(const Tile& orig) {
}

Tile::~Tile() {
}


char Tile::getIdentifier(){
    return identifier;
}

void Tile::setIdentifier(char id){
    this->identifier = id;
    if(id == ','){
        this->setFrameRect(0);
        setWalkAble(true);
    }
    else if(id == '.'){
        this->setFrameRect(1);
        setWalkAble(true);
    }
    else if(id == 'T'){
        this->setFrameRect(2);
        setWalkAble(false);
    }
    else if(id == ';'){
        this->setFrameRect(3);
        setWalkAble(true);
    }
    else if(id == '0'){
        this->setFrameRect(7);
        setWalkAble(true);
    }
    else if(id == '1'){
        this->setFrameRect(4);
        setWalkAble(true);
    }
    else if(id == '2'){
        this->setFrameRect(6);
        setWalkAble(true);
    }
    else if(id == '3'){
        this->setFrameRect(5);
        setWalkAble(true);
    }
    else{
        this->setFrameRect(6);
        setWalkAble(true);
    }
}

void Tile::setWalkAble(bool walkable){
    this->walkAble = walkable;
}

void Tile::setDestroyAble(bool destroyable){
    this->destroyAble = destroyable;
}

LivingObject* Tile::getLivingObject(){
    return this->object;
}
    
bool Tile::getWalkAble(){
    return this->walkAble;
}

bool Tile::getDestroyAble(){
    return this->destroyAble;
}
