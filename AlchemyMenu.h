/* 
 * File:   AlchemyMenu.h
 * Author: legionth
 *
 * Created on 12. August 2012, 02:24
 */

#ifndef ALCHEMYMENU_H
#define	ALCHEMYMENU_H
#include "Menu.h"
#include "AlchemyButton.h"

class AlchemyMenu : public Menu{
public:
    AlchemyMenu(int posX, int posY,int sizeX,int sizeY);
    virtual ~AlchemyMenu();
    void addButton(AlchemyButton* button);
    AlchemyButton* getButton(int i);
    std::vector<AlchemyButton*> getButtons();
private:
    std::vector<AlchemyButton*> buttons;
    


};

#endif	/* ALCHEMYMENU_H */

