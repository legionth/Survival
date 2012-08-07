/* 
 * File:   CookingRessource.h
 * Author: niels
 *
 * Created on 7. August 2012, 14:40
 */

#ifndef COOKINGRESSOURCE_H
#define	COOKINGRESSOURCE_H
#include "Ressource.h"

class CookingRessource : public Ressource{
public:
    CookingRessource(int id, sf::Texture* tex);
    CookingRessource(const CookingRessource& orig);
    virtual ~CookingRessource();
private:

};

#endif	/* COOKINGRESSOURCE_H */

