/* 
 * File:   Dropable.h
 * Author: legionth
 *
 * Created on 23. Juli 2012, 14:35
 */

#ifndef DROPABLE_H
#define	DROPABLE_H
#include "Tile.h"

class Dropable {
public:
    Dropable();
    Dropable(sf::Texture* tex);
//    Dropable(const Dropable& orig);
    virtual ~Dropable();
    
    void addDrop(int ressource);
    void drop(Tile* tile);
    void setRessourceTexture(sf::Texture* tex);
private:
    std::vector<int> dropList;
    sf::Texture* ressourceTex;
 
};

#endif	/* DROPABLE_H */

