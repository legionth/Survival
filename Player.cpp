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
    this->setHunger(3);
    this->setHeat(5);
    
    this->weapon = 0;
    this->axe = 0;
    this->pickAxe = 0;
    this->currentTool = 0;
    
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
    delete weapon;
    delete axe;
    delete pickAxe;
}

void Player::pickup(Tile* tile){
    ressources[tile->getRessource()->getIdentifier()]++;
    tile->removeRessource();
}

void Player::pickup(Tile* tile, bool remove){
    ressources[tile->getRessource()->getIdentifier()]++;
    
    if(remove){
        tile->removeRessource();
    }
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

WeaponTool* Player::getWeapon(){
    return this->weapon;
}

AxeTool* Player::getAxe(){
    return this->axe;
}

PickAxeTool* Player::getPickAxe(){
    return this->pickAxe;
}
    
void Player::setWeapon(WeaponTool* w){
    this->weapon = w;
    setAttackPower(getAttackPower() + w->getAttackPower());
}

void Player::setAxe(AxeTool* axe){
    this->axe = axe;
}

void Player::setHeat(int heat){
    this->heat = heat;
}

void Player::setPickAxe(PickAxeTool* pickAxe){
    this->pickAxe = pickAxe;
}

void Player::setHunger(int i){
    this->hunger = i;
}

int Player::getHunger(){
    return this->hunger;
}

int Player::getHeat(){
    return this->heat;
}