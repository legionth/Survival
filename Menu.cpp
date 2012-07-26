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
    setMaxLineButtons(5);
    this->line = 0;
    this->buttonCounterLine = 0;
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
    
    int mod = count % maxLineButtons;
    
    if(count == 1){
        button->getSprite()->setPosition((posX*count),posY);
        buttonCounterLine++;
    }else if(buttonCounterLine == maxLineButtons){
        line++;
        button->getSprite()->setPosition(posX, posY + (line * BUTTON_WIDTH ));
        buttonCounterLine = 1;
    }
    else{
        button->getSprite()->setPosition(posX + (buttonCounterLine*BUTTON_WIDTH), posY + (line * BUTTON_WIDTH ));
        buttonCounterLine++;
    }
    
}

Button* Menu::getButton(int i){
    return buttons[i];
}

std::vector<Button*> Menu::getButtons(){
    return buttons;
}


void Menu::setMaxLineButtons(int max){
    maxLineButtons = max;
}

int Menu::getMaxLineButtons(){
    return this->maxLineButtons;
}
