/* 
 * File:   Potion.h
 * Author: niels
 *
 * Created on 7. August 2012, 14:16
 */

#ifndef POTION_H
#define	POTION_H

#include "Ressource.h"
#include "LivingObject.h"

class Potion : public Ressource{
public:
    Potion(int health,int heal,int atk,int def, float max);
    Potion(const Potion& orig);
    void use(LivingObject* livingObject);
    float getMaxTime();
    float getCurrentTime();
    virtual ~Potion();
private:
    int health;         // increase or decrease healthMAX over time
    int heal;           // increase or decrease health permanently
    int attackPower;
    int defense;
    
    float maxTime;
    sf::Clock timer;
};

#endif	/* POTION_H */

