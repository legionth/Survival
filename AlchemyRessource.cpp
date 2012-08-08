/* 
 * File:   AlchemyRessource.cpp
 * Author: niels
 * 
 * Created on 7. August 2012, 14:34
 */

#include "AlchemyRessource.h"

AlchemyRessource::AlchemyRessource(int id, sf::Texture* tex) : Ressource(id,tex) {
    this->setAlchemyRessource(true);
    this->setStatusRessource(false);
    this->setIdentifier(id);
}

AlchemyRessource::AlchemyRessource(const AlchemyRessource& orig) {
}

AlchemyRessource::~AlchemyRessource() {
}

