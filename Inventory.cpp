/* 
 * File:   Inventory.cpp
 * Author: legionth
 * 
 * Created on 23. Juli 2012, 13:12
 */

#include "Inventory.h"
#include <iostream>

Inventory::Inventory() : Menu(0,0,FRAME_WIDTH * 5, FRAME_HEIGHT * 5){
    shown = false;
    setMaxLineButtons(7);
    this->maxItems = 63;
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

void Inventory::addRessource(Ressource* res){
    bool set = false;
    
    for(int i = 0; i < getButtons().size(); i++){
        if(getButton(i)->getRessource() == 0 && !set){
            getButton(i)->setRessource(res);
            set = true;
        }
    }
}

void Inventory::addButton(Button* button){
    Menu::addButton(button);
}

void Inventory::removeRessource(Button* button){
    Ressource* res = button->getRessource();
    delete res;
    button->setRessource(0,false);
}

 void Inventory::decrease(std::map<int,int> decreaseRes){
     int size = decreaseRes.size();
     
     for(int i = 0; i < size; i++){
         for(int j = 0; j < decreaseRes[i]; j++ ){
             for(int button = 0; button < getButtons().size(); button++){
               //  std::cout<<"decreaseRes"<<decreaseRes[i]<<std::endl;
                 if(decreaseRes[i] > 0 && getButtons()[button]->getRessource() != 0 && getButtons()[button]->getRessource()->getIdentifier() == i){
                     removeRessource(getButtons()[button]);
                     decreaseRes[i] -= 1;
                 }
             }
         }
     }
 }
 
 bool Inventory::checkRessources(std::map<int,int> checkRes){
     int size = checkRes.size();
     bool ret = false;
     
     for(int i = 0; i < size; i++){
         for(int j = 0; j < checkRes[i]; j++ ){
             for(int button = 0; button < getButtons().size(); button++){
                 if(checkRes[i] > 0 && getButtons()[button]->getRessource() != 0 && getButtons()[button]->getRessource()->getIdentifier() == i){
                     checkRes[i] -= 1;
                 }
             }
              
             if(checkRes[i] <= 0){
                 ret = true;
             }else{
                 ret = false;
             }
         }
     }
     
     
     return ret;
 }
 
int Inventory::countItems(){
    int ret = 0;
    
    for(int i = 0; i < getButtons().size(); i++){
        if(getButtons()[i]->getRessource() != 0){
            ret++;
        }
    }
    
    return ret;
}

int Inventory::getMaxItems(){
    return this->maxItems;
}