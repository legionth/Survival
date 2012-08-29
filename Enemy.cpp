/* 
 * File:   Enemy.cpp
 * Author: niels
 * 
 * Created on 20. Juni 2012, 13:48
 */

#include "Enemy.h"

Enemy::Enemy(TileMap* tilemap, int posX, int posY, sf::Texture* texture,int frameRect, int id,sf::Texture *ressourceTex) : Dropable(ressourceTex) {
    this->setTileMap(tilemap);
    this->setImage(texture);
    this->setPos(posX,posY,true);
    this->setFrameRect(frameRect);
    this->setId(id);
    this->setAttacked(false);

    // Put loot list here
    switch(id){
        case ENEMY_PIG:
            addDrop(RES_LEATHER);
            break;            
    }
}

Enemy::~Enemy() {
//    dropList.clear();
}

void Enemy::setBeheavior(int b){
    this->behavior = b;
}

int Enemy::getBehavior(){
    return this->behavior;
}

void Enemy::execute(World* world){
    int rnd = rand() % 5;
    
    switch(this->behavior){
        case BEHAV_AGGRESSIVE:
            
            break;
        case BEHAV_DEFENSIVE:
                if(this->haveToWalk()){
                      this->move(getCurrentDirection(),world);
                }
                else{
                    if(definsiveClock.getElapsedTime().asSeconds() > 1.5f){
                        definsiveClock.restart();
                            
                            int x = 0;
                            int y = 0;
                            bool hadAttack = false;
                            
                            for(int direction = 0 ; direction < 4; direction++){
                                switch(direction){
                                    case MOVE_UP:
                                        x = getXPos();
                                        y = getYPos() - 1;
                                      // startAnimation(RECT_ATTACK_UP_START,RECT_ATTACK_UP_END);
                                      //  toAttack = true;
                                        break;
                                    case MOVE_DOWN:
                                        x = getXPos();
                                        y = getYPos() + 1;
                                      //  startAnimation(RECT_ATTACK_DOWN_START,RECT_ATTACK_DOWN_END);
                                       // toAttack = true;
                                        break;
                                    case MOVE_RIGHT:
                                        x = getXPos() + 1;
                                        y = getYPos();
                                      //  startAnimation(RECT_ATTACK_RIGHT_START,RECT_ATTACK_RIGHT_END);
                                       // toAttack = true;
                                        break;
                                    case MOVE_LEFT:
                                        x = getXPos() - 1;
                                        y = getYPos();
                                      //  startAnimation(RECT_ATTACK_LEFT_START,RECT_ATTACK_LEFT_END);
                                        //toAttack = true;
                                        break;
                                }
                                
                                if((x >= 0 && x < 5) && (y >= 0 && y < 5) && getTileMap()->getTile(x,y)->getLivingObject() != 0){
                                    setCurrentDirection(direction);
                                    setCurrentFrame(getDirectionRect());
                                    attack(getTileMap()->getTile(x,y)->getLivingObject());
                                    setToAttack(false);
                                    hadAttack = true;
                                }
                            }
                            
                            if(!hadAttack){
                                //stopAnimation();
                                this->move(rnd,world);
                            }
                        
                    }

                }
            break;
        case BEHAV_PASSIVE:
            
            break;
       default:
//           std::cout<<"behavior not executable"<<std::endl;
           break;
    }
}


int Enemy::getId(){
    return this->id;
}

void Enemy::setId(int i){
    this->id = i;
    
    switch(this->id){
        case ENEMY_PIG:
            setBeheavior(BEHAV_DEFENSIVE);
            break;
        case ENEMY_WOLF:
            setBeheavior(BEHAV_AGGRESSIVE);
            break;
        default:
            break;
    }
}
