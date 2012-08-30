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
    setFrameSize(sizeX,sizeY);
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
        button->getSprite()->setPosition((posX*count) + 10,posY + 10);
        buttonCounterLine++;
    }else if(buttonCounterLine == maxLineButtons){
        line++;
        buttonCounterLine = 1;
        button->getSprite()->setPosition(posX + 10, posY + (line * 2) + (line * BUTTON_WIDTH )+10);
    }
    else{
        button->getSprite()->setPosition(posX + (buttonCounterLine * 2 ) + 10 + (buttonCounterLine*BUTTON_WIDTH), posY + (line * 2) +  (line * BUTTON_WIDTH )+ 10);
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

int Menu::getButtonCounterLine(){
    return this->buttonCounterLine;
}

void Menu::increaseButtonCounterLine(){
    this->buttonCounterLine++;
}

void Menu::setButtonCounterLine(int i){
    this->buttonCounterLine = i;
}

int Menu::getLine(){
    return this->line;
}

void Menu::setLine(int line){
    this->line = line;
}

void Menu::increaseLine(){
    this->line++;
}
