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
    void addRessource(Ressource* res);                                          // Add ressource to next free button
    void addButton(Button* button);
    int getMaxItems();
    void decrease(std::map<int,int> decreaseRes);                               // decrease Ressource to given container
    int countItems();
    void removeRessource(Button* button);                                       
    bool checkRessources(std::map<int,int> checkRes);
private:
    bool shown;
    std::vector<InventoryButton*> buttons;
    InventoryButton* currentPressed;
    int maxItems;
    
};

#endif	/* INVENTORY_H */

