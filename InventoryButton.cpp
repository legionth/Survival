/* 
 * File:   InventoryButton.cpp
 * Author: niels
 * 
 * Created on 26. Juli 2012, 08:33
 */

#include "InventoryButton.h"

InventoryButton::InventoryButton(int id, int frame, sf::Texture* tex) {
    this->setId(id);
    this->setImage(tex);
    this->setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
    this->setFrameRect(frame);
}

InventoryButton::InventoryButton(const InventoryButton& orig) {
}

InventoryButton::~InventoryButton() {
    if(this->ressource != 0){
        delete ressource;
    }
}

Ressource* InventoryButton::getRessource(){
    return this->ressource;
}

void InventoryButton::setRessource(Ressource* res){
    this->ressource = res;
    
    this->ressource->getSprite()->setPosition(getSprite()->getPosition().x + 16, getSprite()->getPosition().y + 16);
}

