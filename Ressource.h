/* 
 * File:   Ressource.h
 * Author: niels
 *
 * Created on 7. Juni 2012, 00:48
 */

#ifndef RESSOURCE_H
#define	RESSOURCE_H
#include "GameObject.h"

class Ressource : public GameObject{
public:
    Ressource();
    Ressource(int id,sf::Texture* texture);
    Ressource(const Ressource& orig);
    virtual ~Ressource();
    
    void setIdentifier(int id);
    int getIdentifier();
    
    bool isStatusRessource();
    bool isAlchemyRessource();
    bool isCraftingRessource();
    bool isCookingRessource();
    
    void setStatusRessource(bool b);
    void setAlchemyRessource(bool b);
    void setCraftingRessource(bool b);
    void setCookingRessource(bool b);
private:
    int identifier;
    
    bool statusRessource;
    bool alchemyRessource;
    bool craftingRessource;
    bool cookingRessource;

};

#endif	/* RESSOURCE_H */

