/* 
 * File:   CraftingRessource.cpp
 * Author: niels
 * 
 * Created on 7. August 2012, 14:35
 */

#include "CraftingRessource.h"

CraftingRessource::CraftingRessource(int id, sf::Texture* tex) : Ressource(id,tex){
    this->setCraftingRessource(true);
}

CraftingRessource::CraftingRessource(const CraftingRessource& orig) {
}

CraftingRessource::~CraftingRessource() {
}

