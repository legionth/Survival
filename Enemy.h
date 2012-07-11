/* 
 * File:   Enemy.h
 * Author: niels
 *
 * Created on 20. Juni 2012, 13:48
 */

#ifndef ENEMY_H
#define	ENEMY_H
#include "LivingObject.h"

class Enemy : public LivingObject {
public:
    Enemy();
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    void setBeheavior(int b);
    int getBehavior();
    void execute();
    void drop();
    bool isAttacked();
private:
    int behavior;
    std::vector<int> dropList;
    bool attacked;
    
    int id;
};

#endif	/* ENEMY_H */

