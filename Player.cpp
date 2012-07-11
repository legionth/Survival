/* 
 * File:   Player.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:51
 */

#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* img) {
    this->setLife(3);
    this->setImage(img);
    this->setFrameRect(0);
    
    ressources[RES_WOOD]        = 0;
    ressources[RES_STONE]       = 0;
    ressources[RES_IRON_ORE]    = 0;    
    ressources[RES_GOLD_ORE]    = 0;
    ressources[RES_SILVER_ORE]  = 0;
    ressources[RES_LEATHER]     = 0;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

void Player::pickup(Tile* tile){
    ressources[tile->getRessource()->getIdentifier()]++;
    tile->removeRessource();
}

int Player::getRessourceCountById(int id){
    return ressources[id];
}

std::map<int,int> Player::getRessources(){
    return this->ressources;
}

void Player::decreaseRessources(std::map<int,int> decreaseRes){
   int size = ressources.size();
   
   for(int i = 0; i < size; i++){
       ressources[i] -= decreaseRes[i];
   }
}

