/* 
 * File:   WeaponTool.h
 * Author: niels
 *
 * Created on 25. Juli 2012, 09:14
 */

#ifndef WEAPONTOOL_H
#define	WEAPONTOOL_H

#include "Tool.h"

class WeaponTool : public Tool{
public:
    WeaponTool(int id, int atk, bool distance, bool melee, bool magic);
    virtual ~WeaponTool();
    
    int getAttackPower();
    bool isDistanceWeapon();
    bool isMeleeWeapon();
    bool isMagicWeapon();
private:
    int attackPower;
    
    bool distanceWeapon;
    bool meleeWeapon;
    bool magicWeapon;

};

#endif	/* WEAPONTOOL_H */

