/* 
 * File:   CraftingMenu.cpp
 * Author: legionth
 * 
 * Created on 12. August 2012, 12:50
 */

#include "CraftingMenu.h"
#include <iostream>

CraftingMenu::CraftingMenu(int posX, int posY,int sizeX,int sizeY) : Menu (posX,posY,sizeX,sizeY){
}

CraftingMenu::~CraftingMenu() {
    buttons.clear();
}

void CraftingMenu::addButton(CraftingButton* button){
    buttons.push_back(button);
    int count = buttons.size();
    int posX = getSprite()->getPosition().x;
    int posY = getSprite()->getPosition().y;
    
    if(count == 1){
        button->getSprite()->setPosition((posX*count),posY);
    }else{
        button->getSprite()->setPosition((posX)+ (BUTTON_WIDTH*(count - 1)),posY); //Put in line
    }
    
}

CraftingButton* CraftingMenu::getButton(int i){
    return buttons[i];
}

std::vector<CraftingButton*> CraftingMenu::getButtons(){
    return buttons;
}