/* 
 * File:   Potion.h
 * Author: niels
 *
 * Created on 7. August 2012, 14:16
 */

#ifndef POTION_H
#define	POTION_H

#include "Ressource.h"
//#include "LivingObject.h"
#include "Player.h"
//class LivingObject;
class Potion : public Ressource{
public:
    Potion(int health,int heal,int atk,int def, float max, int id);
    Potion(int id);
    Potion(const Potion& orig);
    float getMaxTime();
    float getCurrentTime();
    std::map<int,int> getRessources();
    virtual ~Potion();
    bool use(Player* player);
    bool isOnTime();
private:
    int health;         // increase or decrease healthMAX over time
    int heal;           // increase or decrease health permanently
    int attackPower;
    int defense;
    
    float maxTime;
    sf::Clock timer;
    std::map<int,int> ressources;
    bool onTimePotion;
};

#endif	/* POTION_H */

