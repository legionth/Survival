/* 
 * File:   Inventory.cpp
 * Author: legionth
 * 
 * Created on 23. Juli 2012, 13:12
 */

#include "Inventory.h"

Inventory::Inventory() : Menu(0,0,FRAME_WIDTH * 5, FRAME_HEIGHT * 5){
    shown = false;
    setMaxLineButtons(7);
}

Inventory::~Inventory() {
    buttons.clear();
}


 bool Inventory::isShown(){
     return this->shown;
 }
 
 void Inventory::show(){
     this->shown = !shown;
 }
 
void Inventory::addInventoryButton(InventoryButton* invButton){
    buttons.push_back(invButton);
    int count = buttons.size() - 1;
    
    invButton->getSprite()->setPosition(getSprite()->getPosition().x + 530,getSprite()->getPosition().y + (BUTTON_HEIGHT * 2 * count) + BUTTON_HEIGHT);
}

InventoryButton* Inventory::getInventoryButtonById(int id){
    InventoryButton* inv = 0;
    
    for(int i = 0; i < buttons.size(); i++){
        if(buttons[i]->getId() == id){
             inv = buttons[i];  
        }
    }
    
    return inv;
}

InventoryButton* Inventory::getCurrentPressed(){
    return this->currentPressed;
}

void Inventory::setCurrentPressed(InventoryButton* cur){
    this->currentPressed = cur;
}

std::vector<InventoryButton*> Inventory::getInventoryButtons(){
    return this->buttons;
}
        
InventoryButton* Inventory::getInventoryButton(int i){
    return this->buttons[i];
}