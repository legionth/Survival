/* 
 * File:   StatusMenu.cpp
 * Author: legionth
 * 
 * Created on 19. Juli 2012, 23:02
 */

#include "StatusMenu.h"

/* 
 * File:   StatusMenu.cpp
 * Author: legionth
 * 
 * Created on 4. Juli 2012, 22:20
 */

#include "StatusMenu.h"
#include <iostream>

StatusMenu::StatusMenu(int posX, int posY,int sizeX,int sizeY) : Menu (posX,posY,sizeX,sizeY){
}

StatusMenu::~StatusMenu() {
   // buttons.clear();
}
/*
void StatusMenu::addButton(StatusButton* button){
    buttons.push_back(button);
    int count = countButton(button->getId());
    
    switch(button->getId()){
        case STATUS_BUTTON_LIFE:
            button->getSprite()->setPosition(getSprite()->getPosition().x +( count * STATUS_BUTTON_WIDTH ),getSprite()->getPosition().y + 3);
            break;
    }
}

StatusButton* StatusMenu::getButton(int i){
    return buttons[i];
}
                               
std::vector<StatusButton*> StatusMenu::getButtons(){
    return buttons;
}

int StatusMenu::countButton(int id){
    int ret = 0;
    
    for(int i = 0; i < buttons.size(); i++){
        if(buttons[i]->getId() == id){
            ret++;
        }
    }
    
    return ret;
}


void StatusMenu::removeById(int id){
    bool removed = false;
    
    for(int i = 0; i > buttons.size(); i++){
        if(!removed && buttons[i]->getId() == id){
            buttons.erase(buttons.end()-i);
            removed = true;
        }
    }
}
*/
void StatusMenu::setLifeButton(StatusButton* lifeButton){
    this->lifeButton = lifeButton;
}

void StatusMenu::setHeatButton(StatusButton* button){
    this->heatButton = button;
}

void StatusMenu::setHungerButton(StatusButton* button){
    this->hungerButton = button;
}

void StatusMenu::setCoinButton(StatusButton* button){
    this->coinButton = button;
}

void StatusMenu::drawLifeButton(sf::RenderWindow *window, int life){
    for(int i = 0; i < life; i++){
        lifeButton->getSprite()->setPosition(getSprite()->getPosition().x +( i * STATUS_BUTTON_WIDTH ),getSprite()->getPosition().y + 3);
        window->draw(*lifeButton->getSprite());
    }
}

void StatusMenu::drawHungerButton(sf::RenderWindow *window, int hunger){    
    for(int i = 0; i < hunger; i++){
        hungerButton->getSprite()->setPosition(getSprite()->getPosition().x +( i * STATUS_BUTTON_WIDTH ),getSprite()->getPosition().y + 3 + 16);
        window->draw(*hungerButton->getSprite());
    }
}

void StatusMenu::drawHeatButton(sf::RenderWindow *window, int heat){    
    for(int i = 0; i < heat; i++){
        heatButton->getSprite()->setPosition(getSprite()->getPosition().x +( i * STATUS_BUTTON_WIDTH ),getSprite()->getPosition().y + 3 + 32);
        window->draw(*heatButton->getSprite());
    }
}

void StatusMenu::setWeaponSlot(SlotButton* slot){
    this->weaponSlot = slot;
    slot->getSprite()->setPosition(getSprite()->getPosition().x + getFrameWidth() - slot->getFrameWidth() - 36,getSprite()->getPosition().y + 30);
}

void StatusMenu::setToolSlot(SlotButton* slot){
    this->toolSlot = slot;
    slot->getSprite()->setPosition(getSprite()->getPosition().x + getFrameWidth() - slot->getFrameWidth() - 36 ,getSprite()->getPosition().y + 128);
}

SlotButton* StatusMenu::getWeaponSlot(){
    return this->weaponSlot;
}

SlotButton* StatusMenu::getToolSlot(){
    return this->toolSlot;
}