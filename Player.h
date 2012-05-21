/* 
 * File:   Player.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:51
 */

#include "LivingObject.h"
#ifndef PLAYER_H
#define	PLAYER_H

class Player : public LivingObject{
public:
    Player(sf::Texture* img);
    Player(const Player& orig);
    virtual ~Player();
    
    int getHeat();
    void setHeat(int i);
    
private:
    int heat;
    std::map<std::string,int> ressources;

};

#endif	/* PLAYER_H */

