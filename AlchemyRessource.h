/* 
 * File:   AlchemyRessource.h
 * Author: niels
 *
 * Created on 7. August 2012, 14:34
 */

#ifndef ALCHEMYRESSOURCE_H
#define	ALCHEMYRESSOURCE_H
#include "Ressource.h"

class AlchemyRessource : public Ressource{
public:
    AlchemyRessource(int id, sf::Texture* tex);
    AlchemyRessource(const AlchemyRessource& orig);
    virtual ~AlchemyRessource();
private:
    
};

#endif	/* ALCHEMYRESSOURCE_H */

