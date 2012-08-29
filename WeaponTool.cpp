/* 
 * File:   WeaponTool.cpp
 * Author: niels
 * 
 * Created on 25. Juli 2012, 09:14
 */

#include <stdlib.h>

#include "WeaponTool.h"
#include "Ressource.h"
#include "Player.h"

WeaponTool::WeaponTool(int id, int atk, bool melee, bool distance, bool magic) : Tool(id){
    this->attackPower = atk;
    
    this->meleeWeapon = melee;
    this->distanceWeapon = distance;
    this->magicWeapon = magic;
    
    setUsable(true);
    setWeapon(true);
}

WeaponTool::WeaponTool(sf::Texture* tex,int id) : Tool(id){
    this->setImage(tex);
    
    setUsable(true);
    setWeapon(true);
}

WeaponTool::~WeaponTool() {
}

int WeaponTool::getAttackPower(){
    return this->attackPower;
}

bool WeaponTool::isDistanceWeapon(){
    return this->distanceWeapon;
}

bool WeaponTool::isMeleeWeapon(){
    return this->meleeWeapon;
}
    
bool WeaponTool::isMagicWeapon(){
    return this->magicWeapon;
}

bool WeaponTool::use(Player* player){
    player->setWeapon(this);
    return true;
}

void WeaponTool::setDistanceWeapon(bool b){
    this->distanceWeapon = b;
}

void WeaponTool::setMeleeWeapon(bool b){
    this->meleeWeapon = b;
}

void WeaponTool::setMagicWeapon(bool b){
    this->magicWeapon = b;
}
void WeaponTool::setAttackPower(int i){
    this->attackPower = i;
}

