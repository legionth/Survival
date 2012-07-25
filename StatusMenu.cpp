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

void StatusMenu::drawLifeButton(sf::RenderWindow *window, int life){
    for(int i = 0; i < life; i++){
        lifeButton->getSprite()->setPosition(getSprite()->getPosition().x +( i * STATUS_BUTTON_WIDTH ),getSprite()->getPosition().y + 3);
        window->draw(*lifeButton->getSprite());
    }
}
