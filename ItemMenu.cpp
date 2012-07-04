/* 
 * File:   ItemMenu.cpp
 * Author: legionth
 * 
 * Created on 4. Juli 2012, 22:20
 */

#include "ItemMenu.h"
#include <iostream>
ItemMenu::ItemMenu(int posX, int posY,int sizeX,int sizeY) : Menu (posX,posY,sizeX,sizeY){
}

ItemMenu::~ItemMenu() {
    buttons.clear();
}

void ItemMenu::addButton(ItemButton* button){
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

ItemButton* ItemMenu::getButton(int i){
    return buttons[i];
}

std::vector<ItemButton*> ItemMenu::getButtons(){
    return buttons;
}

