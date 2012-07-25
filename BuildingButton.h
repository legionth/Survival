/* 
 * File:   BuildingButton.h
 * Author: niels
 *
 * Created on 21. Juni 2012, 08:01
 */

#ifndef BUILDINGBUTTON_H
#define	BUILDINGBUTTON_H
#include "Building.h"
#include "Button.h"

class BuildingButton : public Button{
public:
    BuildingButton(Building* b, std::string name);
    BuildingButton(int frameRect,sf::Texture* tex,int rectBuilding,sf::Texture* texBuilding,std::string buttonName,char id);
    BuildingButton(const BuildingButton& orig);
    virtual ~BuildingButton();
    
    void setBuilding(Building* building);
    Building* getBuilding();
private:
    Building* building;
};

#endif	/* BUILDINGBUTTON_H */

