/* 
 * File:   BuildingButton.cpp
 * Author: niels
 * 
 * Created on 21. Juni 2012, 08:01
 */

#include "BuildingButton.h"

BuildingButton::BuildingButton(Building* b, std::string name) {
    this->building = b;
}

BuildingButton::BuildingButton(const BuildingButton& orig) {
}

BuildingButton::~BuildingButton() {
}

