/* 
 * File:   AlchemyAlchemyMenu.cpp
 * Author: niels
 * 
 * Created on 27. Juni 2012, 11:40
 */

#include "AlchemyMenu.h"
#include <iostream>
AlchemyMenu::AlchemyMenu(int posX, int posY,int sizeX,int sizeY) : Menu (posX,posY,sizeX,sizeY){
}

AlchemyMenu::~AlchemyMenu() {
    buttons.clear();
}

void AlchemyMenu::addButton(AlchemyButton* button){
    buttons.push_back(button);
    int count = buttons.size();
    int posX = getSprite()->getPosition().x;
    int posY = getSprite()->getPosition().y;
    
    if(count == 1){
        button->getSprite()->setPosition((posX*count),posY);
    }else{
        button->getSprite()->setPosition((posX)+ (BUTTON_WIDTH*(count - 1)),posY); //Put in line
    }
   //std::cout<<"(posX*count)+BUTTON_WIDTH"<<(posX)+ (BUTTON_WIDTH*count)<<std::endl;
    
}

AlchemyButton* AlchemyMenu::getButton(int i){
    return buttons[i];
}

std::vector<AlchemyButton*> AlchemyMenu::getButtons(){
    return buttons;
}

