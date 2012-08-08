/* 
 * File:   InventoryButton.cpp
 * Author: niels
 * 
 * Created on 26. Juli 2012, 08:33
 */

#include "InventoryButton.h"
#include <iostream>

InventoryButton::InventoryButton(int id, int frame, sf::Texture* tex) {
    this->setId(id);
    this->setImage(tex);
    this->setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
    this->setFrameRect(frame);
   // this->ressource = 0;
}

InventoryButton::InventoryButton(const InventoryButton& orig) {
}

InventoryButton::~InventoryButton() {
}


