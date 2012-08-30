/* 
 * File:   CraftingMenu.cpp
 * Author: legionth
 * 
 * Created on 12. August 2012, 12:50
 */

#include "CraftingMenu.h"
#include <iostream>

CraftingMenu::CraftingMenu(int posX, int posY,int sizeX,int sizeY) : Menu (posX,posY,sizeX,sizeY){
    setMaxLineButtons(4);
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
        increaseButtonCounterLine();
    }else if(getButtonCounterLine() == getMaxLineButtons()){
        increaseLine();
        setButtonCounterLine(1);
        button->getSprite()->setPosition(posX, posY + (getLine() * BUTTON_WIDTH ));
    }
    else{
        button->getSprite()->setPosition(posX + (getButtonCounterLine()*BUTTON_WIDTH), posY + (getLine() * BUTTON_WIDTH ));
        increaseButtonCounterLine();    
    }
    
}

CraftingButton* CraftingMenu::getButton(int i){
    return buttons[i];
}

std::vector<CraftingButton*> CraftingMenu::getButtons(){
    return buttons;
}
