/* 
 * File:   Menu.cpp
 * Author: niels
 * 
 * Created on 21. Juni 2012, 07:54
 */

#include "Menu.h"

Menu::Menu(int posX, int posY) {
    getSprite()->setPosition(posX,posY);
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

void Menu::addButton(Button* button){
    buttons.push_back(button);
}

Button* Menu::getButton(int i){
    return buttons[i];
}

