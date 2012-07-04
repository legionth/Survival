/* 
 * File:   ItemMenu.h
 * Author: legionth
 *
 * Created on 4. Juli 2012, 22:20
 */

#ifndef ITEMMENU_H
#define	ITEMMENU_H
#include "Menu.h"
#include "ItemButton.h"

class ItemMenu : public Menu{
public:
    ItemMenu(int posX, int posY,int sizeX,int sizeY);
    virtual ~ItemMenu();
    void addButton(ItemButton* button);
    ItemButton* getButton(int i);
    std::vector<ItemButton*> getButtons();
private:
    std::vector<ItemButton*> buttons;

};

#endif	/* ITEMMENU_H */

