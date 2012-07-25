/* 
 * File:   WeaponTool.cpp
 * Author: niels
 * 
 * Created on 25. Juli 2012, 09:14
 */

#include <stdlib.h>

#include "WeaponTool.h"

WeaponTool::WeaponTool(int id, int atk, bool melee, bool distance, bool magic) : Tool(id){
    this->attackPower = atk;
    
    this->meleeWeapon = melee;
    this->distanceWeapon = distance;
    this->magicWeapon = magic;
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

