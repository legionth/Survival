/* 
 * File:   BuildingButton.cpp
 * Author: niels
 * 
 * Created on 21. Juni 2012, 08:01
 */

#include "BuildingButton.h"
#include <iostream>
BuildingButton::BuildingButton(int frameRect,sf::Texture* tex,std::string buttonName,Building *b) : Button(frameRect,tex,buttonName){
    std::cout<<"foobar"<<std::endl;
    std::cout<<"width"<<BUTTON_WIDTH<<std::endl;
    setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
    std::cout<<"set building"<<std::endl;
    setBuilding(b);
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
    return this->building;
}

