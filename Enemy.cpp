/* 
 * File:   Enemy.cpp
 * Author: niels
 * 
 * Created on 20. Juni 2012, 13:48
 */

#include "Enemy.h"

Enemy::Enemy() {
}

Enemy::Enemy(const Enemy& orig) {
}

Enemy::~Enemy() {
}

void Enemy::setBeheavior(int b){
    this->behavior = b;
}

int Enemy::getBehavior(){
    return this->behavior;
}

void Enemy::execute(){
    switch(this->behavior){
        case BEHAV_AGGRESSIVE:
            
            break;
        case BEHAV_DEFENSIVE:
            
            break;
        case BEHAV_PASSIVE:
            
            break;
       default:
           std::cout<<"behavior not executable"<<std::endl;
           break;
    }
}

bool Enemy::isAttacked(){
    return this->attacked;
}
