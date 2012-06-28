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

Building::Building(Building& orig) : identifier(orig.identifier){
    this->setIdentifier(orig.identifier);
    this->ressources = orig.ressources;
    
    sf::Texture *tex = new sf::Texture(*orig.getSprite()->getTexture());
    int currentFrame = orig.getCurrentFrame();
    
    setImage(tex);
    setFrameRect(currentFrame);
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