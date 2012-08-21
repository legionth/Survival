/* 
 * File:   AlchemyRessource.cpp
 * Author: niels
 * 
 * Created on 7. August 2012, 14:34
 */

#include "AlchemyRessource.h"

AlchemyRessource::AlchemyRessource(int id, sf::Texture* tex) : Ressource(id,tex,false) {
    std::cout<<"here"<<std::endl;
    this->setAlchemyRessource(true);
    this->setStatusRessource(false);
    this->setIdentifier(id);
}

AlchemyRessource::AlchemyRessource(const AlchemyRessource& orig) {
}

AlchemyRessource::~AlchemyRessource() {
}

void AlchemyRessource::setIdentifier(int id){
    std::cout<<"bla"<<std::endl;
    if(id == RES_SNAKE_HEAD){
        this->setFrameRect(0);
    }
    else if(id == RES_EVER_GREEN){
        this->setFrameRect(1);
    }
    else if(id == RES_BLADE_LEAF){
        this->setFrameRect(2);
    }
    else if(id == RES_WASP_DEATH){
        this->setFrameRect(3);
    }
    else{
        this->setFrameRect(0);
       std::cout<<"No id found for ALCHEMY_RESSOURCE"<<id<<std::endl;
    }
    
    Ressource::setIdentifier(id,false);

}