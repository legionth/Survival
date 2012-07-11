/* 
 * File:   BuildingButton.cpp
 * Author: niels
 * 
 * Created on 21. Juni 2012, 08:01
 */

#include "BuildingButton.h"
#include <iostream>

BuildingButton::BuildingButton(int frameRect,sf::Texture* tex,int rectBuilding,sf::Texture* texBuilding,std::string buttonName,char id) 
                              : Button(frameRect,tex,buttonName){
    
    setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
    setBuilding(new Building(id,texBuilding,rectBuilding));
    
}

BuildingButton::BuildingButton(const BuildingButton& orig) {
}

BuildingButton::~BuildingButton() {
    delete this->building;
}

void BuildingButton::setBuilding(Building* b){
    this->building = b;
}

Building* BuildingButton::getBuilding(){
    return new Building(*this->building);
}

