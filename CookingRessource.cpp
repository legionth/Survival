/* 
 * File:   CookingRessource.cpp
 * Author: niels
 * 
 * Created on 7. August 2012, 14:40
 */

#include "CookingRessource.h"

CookingRessource::CookingRessource(int id, sf::Texture* tex) : Ressource(id,tex){
    this->setCookingRessource(true);
}

CookingRessource::CookingRessource(const CookingRessource& orig) {
}

CookingRessource::~CookingRessource() {
}

