/* 
 * File:   CraftingMenu.h
 * Author: legionth
 *
 * Created on 12. August 2012, 12:50
 */

#ifndef CRAFTINGMENU_H
#define	CRAFTINGMENU_H
#include "Menu.h"
#include "CraftingButton.h"

//template<class T>
class CraftingMenu  : public Menu{
public:
    CraftingMenu(int posX, int posY,int sizeX,int sizeY);
    virtual ~CraftingMenu();
    void addButton(CraftingButton* button);
    CraftingButton* getButton(int i);
    std::vector<CraftingButton*> getButtons();
private:
    std::vector<CraftingButton*> buttons;

};

#endif	/* CRAFTINGMENU_H */

