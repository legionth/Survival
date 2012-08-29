/* 
 * File:   CraftingButton.h
 * Author: niels
 *
 * Created on 29. August 2012, 08:53
 */

#ifndef CRAFTINGBUTTON_H
#define	CRAFTINGBUTTON_H
#include "Button.h"

class CraftingButton : public  Button{
public:
    CraftingButton(int frameRect,sf::Texture* tex,int id,sf::Texture* texRes);
    CraftingButton(const CraftingButton& orig);
    virtual ~CraftingButton();
    Ressource* getRessource();
    
    void setRessource(Ressource* res);
private:
    Ressource* ressource;
};

#endif	/* CRAFTINGBUTTON_H */

