/* 
 * File:   Tile.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:57
 */

//#include <stddef.h>
#include <iostream>
#include "Tile.h"

Tile::Tile(sf::Texture* img, int x,int y) {
    object = 0;
    ressource = 0;
    building = 0;
    this->xPos = x;
    this->yPos = y;
    getSprite()->setPosition(128*x,128*y);
    this->setImage(img);
    setWalkAble(true);
    setDestroyAble(false);
    setLife(3);
}

Tile::Tile(char c) {
    object = 0;
    setIdentifier(c);
}

Tile::Tile(const Tile& orig) {
}

Tile::~Tile() {
    if(this->ressource != 0){
        delete this->ressource;
    }
    
    if(this->building != 0){
        delete this->building;
    }
}


char Tile::getIdentifier(){
    return identifier;
}

void Tile::setIdentifier(char id){
    this->identifier = id;
    
    if(id == TILE_GRASS){
        this->setFrameRect(0);
        setWalkAble(true);
    }
    else if(id == TILE_EARTH){
        this->setFrameRect(1);
        setWalkAble(true);
    }
    else if(id == TILE_TREE){
        this->setFrameRect(2);
        setWalkAble(false);
        setDestroyAble(true);
        addDrop(RES_WOOD);
        setLife(3);
    }
    else if(id == TILE_GRASS_EARTH){
        this->setFrameRect(3);
        setWalkAble(true);
    }
    else if(id == TILE_EARTH_DOWN){
        this->setFrameRect(7);
        setWalkAble(true);
    }
    else if(id == TILE_EARTH_RIGHT){
        this->setFrameRect(4);
        setWalkAble(true);
    }
    else if(id == TILE_EARTH_TOP){
        this->setFrameRect(6);
        setWalkAble(true);
    }
    else if(id == TILE_EARTH_LEFT){
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

void Tile::setLivingObject(LivingObject* o){
    this->object = o;
}

void Tile::setDestroyAble(bool destroyable){
    this->destroyAble = destroyable;
}

LivingObject* Tile::getLivingObject(){
    return this->object;
}
    
bool Tile::isWalkAble(){
    return this->walkAble;
}

bool Tile::isDestroyAble(){
    return this->destroyAble;
}

void Tile::setRessource(Ressource* ressource){
    this->ressource = ressource;
    this->ressource->setPos(this->getXPos(),this->getYPos(),true);
    // Set ressource int the middle of the tile
    ressource->getSprite()->setPosition((ressource->getXPos() * FRAME_WIDTH) + ressource->getFrameWidth()/2,
                                        (ressource->getYPos() * FRAME_HEIGHT) + ressource->getFrameHeight()/2);
}

void Tile::setRessource(Ressource* ressource, bool setPos){
    this->ressource = ressource;
    
    if(setPos){
        this->ressource->setPos(this->getXPos(),this->getYPos(),true);
        // Set ressource int the middle of the tile
        ressource->getSprite()->setPosition((ressource->getXPos() * FRAME_WIDTH) + ressource->getFrameWidth()/2,
                                            (ressource->getYPos() * FRAME_HEIGHT) + ressource->getFrameHeight()/2);
    }
}

Ressource* Tile::getRessource(){
    return this->ressource;
}

void Tile::removeRessource(){
    delete ressource;
    ressource = 0;
}

void Tile::setBuilding(Building* building){
    this->building = building;
    this->building->getSprite()->setPosition(this->xPos * FRAME_WIDTH,this->yPos * FRAME_HEIGHT);
    
    switch(building->getIdentifier()){
        case BUILDING_TENT:
            setWalkAble(false);
            break;
        case BUILDING_FIREPLACE:
            setWalkAble(true);
            building->startAnimation(BUILDING_RECT_FIREPLACE,BUILDING_RECT_FIREPLACE_END);
            break;
    }
}

Building* Tile::getBuilding(){
    return this->building;
}

void Tile::addDrop(int ressource){
    dropList.push_back(ressource);
}

void Tile::drop(Tile* tile){
    int size = dropList.size();
    int rnd = rand() % size;

    tile->setRessource(new Ressource(dropList[rnd], ressourceTex));
}

 void Tile::setRessourceTexture(sf::Texture* tex){
     this->ressourceTex = tex;
 }