/* 
 * File:   WeaponTool.h
 * Author: niels
 *
 * Created on 25. Juli 2012, 09:14
 */

#ifndef WEAPONTOOL_H
#define	WEAPONTOOL_H

#include "Tool.h"
#include "Player.h"

class WeaponTool : public Tool{
public:
  //  WeaponTool(int id, int atk, bool distance, bool melee, bool magic);
    WeaponTool(sf::Texture* tex,int id);
    virtual ~WeaponTool();
    
    int getAttackPower();
    bool isDistanceWeapon();
    bool isMeleeWeapon();
    bool isMagicWeapon();
    
    void setDistanceWeapon(bool b);
    void setMeleeWeapon(bool b);
    void setMagicWeapon(bool b);
    void setAttackPower(int i);
    
    bool use(Player* player);
    void setIdentifier(int id);
private:
    int attackPower;
    
    bool distanceWeapon;
    bool meleeWeapon;
    bool magicWeapon;
    std::map<int,int> ressources;

};

#endif	/* WEAPONTOOL_H */

