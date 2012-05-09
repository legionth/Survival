/* 
 * File:   Tile.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:57
 */

#include <stddef.h>

#include "Tile.h"

Tile::Tile() {
    object = NULL;
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
