/* 
 * File:   CraftingRessource.h
 * Author: niels
 *
 * Created on 7. August 2012, 14:35
 */

#ifndef CRAFTINGRESSOURCE_H
#define	CRAFTINGRESSOURCE_H
#include "Ressource.h"

class CraftingRessource : public Ressource{
public:
    CraftingRessource(int id, sf::Texture* tex);
    CraftingRessource(const CraftingRessource& orig);
    virtual ~CraftingRessource();
private:

};

#endif	/* CRAFTINGRESSOURCE_H */

