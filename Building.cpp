#include "Building.h"


Building::Building(void)
{
    ressources[RES_WOOD]        = 0;
    ressources[RES_STONE]       = 0;
    ressources[RES_IRON_ORE]    = 0;
    ressources[RES_GOLD_ORE]    = 0;
    ressources[RES_SILVER_ORE]  = 0;
    ressources[RES_LEATHER]     = 0;
}

Building::Building(char id,sf::Texture *t,int frameRect){
    setIdentifier(id);
    

    
    
    switch (id){
        case BUILDING_TENT:
                ressources[RES_WOOD]        = 1;
                ressources[RES_STONE]       = 0;
                ressources[RES_IRON_ORE]    = 0;
                ressources[RES_GOLD_ORE]    = 0;
                ressources[RES_SILVER_ORE]  = 0;
                ressources[RES_LEATHER]     = 2;
                ressources[RES_IRON_BAR]    = 0;
                ressources[RES_SILVER_BAR]  = 0;
                ressources[RES_GOLD_BAR]    = 0;
            break;
        case BUILDING_FIREPLACE:
                ressources[RES_WOOD]        = 2;
                ressources[RES_STONE]       = 2;
                ressources[RES_IRON_ORE]    = 0;
                ressources[RES_GOLD_ORE]    = 0;
                ressources[RES_SILVER_ORE]  = 0;
                ressources[RES_LEATHER]     = 0;
                ressources[RES_IRON_BAR]    = 0;
                ressources[RES_SILVER_BAR]  = 0;
                ressources[RES_GOLD_BAR]    = 0;
            break;
        case BUILDING_SMITH:
                ressources[RES_WOOD]        = 2;
                ressources[RES_STONE]       = 5;
                ressources[RES_IRON_ORE]    = 0;
                ressources[RES_GOLD_ORE]    = 0;
                ressources[RES_SILVER_ORE]  = 0;
                ressources[RES_LEATHER]     = 0;
                ressources[RES_IRON_BAR]    = 0;
                ressources[RES_SILVER_BAR]  = 0;
                ressources[RES_GOLD_BAR]    = 0;
            break;
       case BUILDING_ANVIL:
                ressources[RES_WOOD]        = 0;
                ressources[RES_STONE]       = 0;
                ressources[RES_IRON_ORE]    = 0;
                ressources[RES_GOLD_ORE]    = 0;
                ressources[RES_SILVER_ORE]  = 0;
                ressources[RES_LEATHER]     = 0;
                ressources[RES_IRON_BAR]    = 5;
                ressources[RES_SILVER_BAR]  = 0;
                ressources[RES_GOLD_BAR]    = 0;
            break;
        default:
                ressources[RES_WOOD]        = 0;
                ressources[RES_STONE]       = 0;
                ressources[RES_IRON_ORE]    = 0;
                ressources[RES_GOLD_ORE]    = 0;
                ressources[RES_SILVER_ORE]  = 0;
                ressources[RES_LEATHER]     = 0;
        break;
    }
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