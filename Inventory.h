/* 
 * File:   Inventory.h
 * Author: legionth
 *
 * Created on 23. Juli 2012, 13:12
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

#include "Menu.h"
#include "InventoryButton.h"

class Inventory : public Menu {
public:
    Inventory();
    virtual ~Inventory();
    bool isShown();
    void show(); 
    void addInventoryButton(InventoryButton* invButton);
    std::vector<InventoryButton*> getInventoryButtons();
    InventoryButton* getInventoryButton(int i);
    InventoryButton* getInventoryButtonById(int id);
    InventoryButton* getCurrentPressed();
    void setCurrentPressed(InventoryButton* cur);
    void addRessource(Ressource* res);
    void addButton(Button* button);
    void decrease(std::map<int,int> decreaseRes);
    void removeRessource(Button* button);
private:
    bool shown;
    std::vector<InventoryButton*> buttons;
    InventoryButton* currentPressed;

    
};

#endif	/* INVENTORY_H */

