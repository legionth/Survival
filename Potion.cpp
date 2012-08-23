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
    this->onTimePotion = true;
    setPotion(true);
    setUsable(true);

}

Potion::Potion(int id){
    setPotion(true);
    setUsable(true);
    this->health = 0;
    this->heal = 0;
    this->attackPower = 0;
    this->defense = 0;
    this->maxTime = 0;
    
    switch(id){
        case POTION_HEAL:
            ressources[RES_SNAKE_HEAD]        = 1;
            ressources[RES_EVER_GREEN]        = 0;
            ressources[RES_WASP_DEATH]        = 0;
            ressources[RES_BLADE_LEAF]        = 0;
            this->heal = 2;
            this->onTimePotion = false;
        break;
        case POTION_POISON:
            ressources[RES_SNAKE_HEAD]        = 3;
            ressources[RES_EVER_GREEN]        = 0;
            ressources[RES_WASP_DEATH]        = 1;
            ressources[RES_BLADE_LEAF]        = 0;
            this->attackPower = 3;
        break;
    }
}

Potion::Potion(const Potion& orig) {
}

Potion::~Potion() {
}

bool Potion::use(Player* player){
    player->setAttackPower(player->getAttackPower() + this->attackPower);
    player->setDefense(player->getDefense() + this->defense);
    player->setLife(player->getLife() + this->heal);
    player->setMaxLife(player->getMaxLife());
    timer.restart();
    return true;
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

bool Potion::isOnTime(){
    return this->onTimePotion;
}
