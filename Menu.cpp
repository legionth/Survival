/* 
 * File:   Menu.cpp
 * Author: niels
 * 
 * Created on 21. Juni 2012, 07:54
 */

#include "Menu.h"
#include <iostream>

Menu::Menu(int posX, int posY,int sizeX,int sizeY) {
    getSprite()->setPosition(posX,posY);
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
    buttons.clear();
}

void Menu::addButton(Button* button){
    buttons.push_back(button);
    int count = buttons.size();
    int posX = getSprite()->getPosition().x;
    int posY = getSprite()->getPosition().y;
    
    if(count == 1){
        button->getSprite()->setPosition((posX*count),posY);
    }else{
        button->getSprite()->setPosition((posX*count)*BUTTON_WIDTH,posY);
    }
    
}

Button* Menu::getButton(int i){
    return buttons[i];
}

std::vector<Button*> Menu::getButtons(){
    return buttons;
}

