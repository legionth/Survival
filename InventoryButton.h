/* 
 * File:   InventoryButton.h
 * Author: niels
 *
 * Created on 26. Juli 2012, 08:33
 */

#ifndef INVENTORYBUTTON_H
#define	INVENTORYBUTTON_H

#include "Button.h"

/**
 * This Buttons are the craft buttons
 */
class InventoryButton : public Button{
public:
    InventoryButton(int id, int frame, sf::Texture* tex);
    InventoryButton(const InventoryButton& orig);
    void addInventoryButtons();
    virtual ~InventoryButton();
    
    Ressource* getRessource();
    void setRessource(Ressource* res);
private:
    Ressource* ressource;

};

#endif	/* INVENTORYBUTTON_H */

