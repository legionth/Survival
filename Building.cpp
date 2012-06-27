#include "Building.h"


Building::Building(void)
{
    ressources[RES_WOOD]        = 0;
    ressources[RES_STONE]       = 0;
    ressources[RES_IRON_ORE]    = 0;
    ressources[RES_GOLD_ORE]    = 0;
    ressources[RES_SILVER_ORE]  = 0;
}

Building::Building(char id,sf::Texture *t,int frameRect){
    setIdentifier(id);
    
    ressources[RES_WOOD]        = 0;
    ressources[RES_STONE]       = 0;
    ressources[RES_IRON_ORE]    = 0;
    ressources[RES_GOLD_ORE]    = 0;
    ressources[RES_SILVER_ORE]  = 0;
    
    this->setImage(t);
    this->setFrameRect(frameRect);
}

Building::~Building(void)
{
}

void Building::setIdentifier(char id){
    identifier = id;
}

char Building::getIdentifier(){
    return this->identifier;
}

std::map<int,int> Building::getRessources(){
    return this->ressources;
}