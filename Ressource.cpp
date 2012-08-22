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
    
    setStatusRessource(true);
    setAlchemyRessource(false);
    setCookingRessource(false);
    setCraftingRessource(false);
    setPotion(false);
    setUsable(false);
}

Ressource::Ressource(const Ressource& orig) {
}

Ressource::~Ressource() {
}

Ressource::Ressource(int id,sf::Texture *texture){
    setFrameSize(64,64);
    setImage(texture);
    
    setStatusRessource(true);
    setAlchemyRessource(false);
    setCookingRessource(false);
    setCraftingRessource(false);
    setPotion(false);
    setUsable(false);
    
    setIdentifier(id);
//    this->setPos(x*64,y*64);
}

Ressource::Ressource(int id,sf::Texture *texture,bool setTex){
    setFrameSize(64,64);
    setImage(texture);
    
    setStatusRessource(true);
    setAlchemyRessource(false);
    setCookingRessource(false);
    setCraftingRessource(false);
    setPotion(false);
    setUsable(false);
    
    setIdentifier(id,false);
//    this->setPos(x*64,y*64);
}

void Ressource::setIdentifier(int id){
    //std::cout<<"this too?"<<std::endl;
    if(id == RES_WOOD){
        this->setFrameRect(0);
    }
    else if(id == RES_GOLD_ORE){
        this->setFrameRect(4);
    }
    else if(id == RES_IRON_ORE){
        this->setFrameRect(3);
    }
    else if(id == RES_SILVER_ORE){
        this->setFrameRect(5);
    }
    else if(id == RES_STONE){
        this->setFrameRect(1);
    }
    else if(id == RES_LEATHER){
        this->setFrameRect(2);
        setStatusRessource(false);
        setCraftingRessource(true);
    }
    else{
       this->setFrameRect(0);
       std::cout<<"No id found for RESSOURCE"<<id<<std::endl;
    }
    this->identifier = id;
}

void Ressource::setIdentifier(int id, bool setTex){
    if(setTex){
        if(id == RES_WOOD){
            this->setFrameRect(0);
        }
        else if(id == RES_GOLD_ORE){
            this->setFrameRect(4);
        }
        else if(id == RES_IRON_ORE){
            this->setFrameRect(3);
        }
        else if(id == RES_SILVER_ORE){
            this->setFrameRect(5);
        }
        else if(id == RES_STONE){
            this->setFrameRect(1);
        }
        else if(id == RES_LEATHER){
            this->setFrameRect(2);
            setStatusRessource(false);
            setCraftingRessource(true);
        }
        else{
            this->setFrameRect(0);
           std::cout<<"No id found for RESSOURCE"<<id<<std::endl;
        }
    }
    this->identifier = id;
}

int Ressource::getIdentifier(){
    return this->identifier;
}

bool Ressource::isAlchemyRessource(){
    return this->alchemyRessource;
}

bool Ressource::isCookingRessource(){
    return this->cookingRessource;
}

bool Ressource::isCraftingRessource(){
    return this->craftingRessource;
}

bool Ressource::isStatusRessource(){
    return this->statusRessource;
}

bool Ressource::isPotion(){
    return this->potion;
}

void Ressource::setAlchemyRessource(bool b){
    this->alchemyRessource = b;
}

void Ressource::setCraftingRessource(bool b){
    this->craftingRessource = b;
}

void Ressource::setCookingRessource(bool b){
    this->cookingRessource = b;
}

void Ressource::setStatusRessource(bool b){
    this->statusRessource = b;
}

void Ressource::setPotion(bool b){
    this->potion = b;
}

bool Ressource::use(LivingObject* player){
    std::cout<<"res use"<<std::endl;
    return false;
}

void Ressource::setUsable(bool b){
    this->usable = b;
}

bool Ressource::isUsable(){
    return this->usable;
}

