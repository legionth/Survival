/* 
 * File:   Player.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:51
 */

#include "LivingObject.h"
#include "WeaponTool.h"
#include "AxeTool.h"
#include "PickAxeTool.h"

#ifndef PLAYER_H
#define	PLAYER_H

class WeaponTool;
class Player : public LivingObject{
public:
    Player(sf::Texture* img);
    Player(const Player& orig);
    virtual ~Player();
    
    int getHeat();
    void setHeat(int i);
    void setHunger(int i);
    int getHunger();
    void pickup(Tile* tile);
    void pickup(Tile* tile,bool remove);
    int getRessourceCountById(int id);
    std::map<int,int> getRessources();
    void decreaseRessources(std::map<int,int> decreaseRes);
    
    WeaponTool* getWeapon();
    AxeTool* getAxe();
    PickAxeTool* getPickAxe();
    
    void setWeapon(WeaponTool* w);
    void setAxe(AxeTool* axe);
    void setPickAxe(PickAxeTool* pickAxe);
private:
    int heat;
    int hunger;
    std::map<int,int> ressources;
    
    WeaponTool* weapon;
    AxeTool* axe;
    PickAxeTool* pickAxe;
    
    Tool* currentTool;
};

#endif	/* PLAYER_H */

