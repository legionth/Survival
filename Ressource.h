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
private:
    int identifier;

};

#endif	/* RESSOURCE_H */

