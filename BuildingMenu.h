/* 
 * File:   BuildingMenu.h
 * Author: niels
 *
 * Created on 27. Juni 2012, 11:40
 */

#ifndef BUILDINGMENU_H
#define	BUILDINGMENU_H

#include "Menu.h"
#include "BuildingButton.h"

class BuildingMenu : public Menu{
public:
    BuildingMenu(int posX, int posY,int sizeX,int sizeY);
    virtual ~BuildingMenu();
    void addButton(BuildingButton* button);
    BuildingButton* getButton(int i);
    std::vector<BuildingButton*> getButtons();
private:
    std::vector<BuildingButton*> buttons;
    

};

#endif	/* BUILDINGMENU_H */

