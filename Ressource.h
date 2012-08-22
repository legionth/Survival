/* 
 * File:   Ressource.h
 * Author: niels
 *
 * Created on 7. Juni 2012, 00:48
 */

#ifndef RESSOURCE_H
#define	RESSOURCE_H
#include "GameObject.h"
//#include "LivingObject.h"

class LivingObject;
class Ressource : public GameObject{
public:
    Ressource();
    Ressource(int id,sf::Texture* texture);
     Ressource(int id,sf::Texture* texture,bool setTex);
    Ressource(const Ressource& orig);
    virtual ~Ressource();
    
    void setIdentifier(int id);
    void setIdentifier(int id, bool setTex);

    int getIdentifier();
    
    bool isStatusRessource();
    bool isAlchemyRessource();
    bool isCraftingRessource();
    bool isCookingRessource();
    bool isPotion();
    bool isUsable();
    
    void setStatusRessource(bool b);
    void setAlchemyRessource(bool b);
    void setCraftingRessource(bool b);
    void setCookingRessource(bool b);
    void setPotion(bool b);
    void setUsable(bool b);
    
    bool use(LivingObject* player);
private:
    int identifier;
    
    bool statusRessource;
    bool alchemyRessource;
    bool craftingRessource;
    bool cookingRessource;
    bool potion;
    
    bool usable;
};

#endif	/* RESSOURCE_H */

