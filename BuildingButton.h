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
    BuildingButton(const BuildingButton& orig);
    virtual ~BuildingButton();
private:
    Building* building;

};

#endif	/* BUILDINGBUTTON_H */

