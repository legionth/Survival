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
    Player();
    Player(const Player& orig);
    virtual ~Player();
    
    int getHeat();
    void setHeat(int i);
    
private:
    int heat;

};

#endif	/* PLAYER_H */

