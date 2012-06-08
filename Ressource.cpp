/* 
 * File:   Ressource.cpp
 * Author: niels
 * 
 * Created on 7. Juni 2012, 00:48
 */

#include "Ressource.h"
#include "GameObject.h"
#include <iostream>

Ressource::Ressource() {
    identifier = 0; 
    setFrameSize(64,64);
}

Ressource::Ressource(const Ressource& orig) {
}

Ressource::~Ressource() {
}

Ressource::Ressource(int id,sf::Texture *texture){
    setFrameSize(64,64);
    setImage(texture);

    setIdentifier(id);
//    this->setPos(x*64,y*64);
}

void Ressource::setIdentifier(int id){
    if(id == RES_WOOD){
        this->setFrameRect(0);
    }
    else if(id == RES_GOLD_ORE){
        this->setFrameRect(0);
    }
    else if(id == RES_IRON_ORE){
        this->setFrameRect(0);
    }
    else if(id == RES_SILVER_ORE){
        this->setFrameRect(0);
    }
    else if(id == RES_STONE){
        this->setFrameRect(0);
    }
    else if(id == RES_LEATHER){
        this->setFrameRect(0);
    }
    else{
        this->setFrameRect(0);
       std::cout<<"No id found for RESSOURCE"<<std::endl;
    }
    this->identifier = id;
}

int Ressource::getIdentifier(){
    return this->identifier;
}

