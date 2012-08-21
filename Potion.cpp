/* 
 * File:   Potion.cpp
 * Author: niels
 * 
 * Created on 7. August 2012, 14:16
 */

#include "Potion.h"

Potion::Potion(int health,int heal,int atk,int def, float max,int id) {
    this->health = health;
    this->heal = heal;
    this->attackPower = atk;
    this->defense = def;
    this->maxTime = max;
    
    switch(id){
        
    }
}

Potion::Potion(int id){
    switch(id){
        case POTION_HEAL:
            ressources[RES_SNAKE_HEAD]        = 1;
            ressources[RES_EVER_GREEN]        = 0;
            ressources[RES_WASP_DEATH]        = 0;
            ressources[RES_BLADE_LEAF]        = 0;
        break;
        case POTION_POISON:
            ressources[RES_SNAKE_HEAD]        = 3;
            ressources[RES_EVER_GREEN]        = 0;
            ressources[RES_WASP_DEATH]        = 1;
            ressources[RES_BLADE_LEAF]        = 0;
        break;
    }
}

Potion::Potion(const Potion& orig) {
}

Potion::~Potion() {
}

void Potion::use(LivingObject* livingObject){
    livingObject->setAttackPower(livingObject->getAttackPower() + this->attackPower);
    livingObject->setDefense(livingObject->getDefense() + this->defense);
    livingObject->setLife(getLife() + this->heal);
    livingObject->setMaxLife(livingObject->getMaxLife());
    timer.restart();
}

float Potion::getMaxTime(){
    return this->maxTime;
}

float Potion::getCurrentTime(){
    return this->timer.getElapsedTime().asSeconds();
}

std::map<int,int> Potion::getRessources(){
    return this->ressources;
}