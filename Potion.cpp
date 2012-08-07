/* 
 * File:   Potion.cpp
 * Author: niels
 * 
 * Created on 7. August 2012, 14:16
 */

#include "Potion.h"

Potion::Potion(int health,int heal,int atk,int def, float max) {
    this->health = health;
    this->heal = heal;
    this->attackPower = atk;
    this->defense = def;
    this->maxTime = max;
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