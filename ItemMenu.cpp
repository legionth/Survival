/* 
 * File:   ItemMenu.cpp
 * Author: legionth
 * 
 * Created on 4. Juli 2012, 22:20
 */

#include "ItemMenu.h"
#include <iostream>
ItemMenu::ItemMenu(int posX, int posY,int sizeX,int sizeY) : Menu (posX,posY,sizeX,sizeY){
    line = 0;
    lineChanged = false;
}

ItemMenu::~ItemMenu() {
    buttons.clear();
}

void ItemMenu::addButton(ItemButton* button){
    buttons.push_back(button);
    int count = buttons.size();
    int posX = getSprite()->getPosition().x;
    int posY = getSprite()->getPosition().y;
    int mod = count % 5;
    
    if(count == 1){
        button->getSprite()->setPosition((posX*count),posY);
        button->getText()->setPosition((posX*count) + 32,posY - 2);
        lineChanged = false;
        line = 1;
    }
    else if(lineChanged){
        count = count / 5;
        button->getSprite()->setPosition((posX) + (BUTTON_WIDTH*(count )),posY + 32); //Put in line
        button->getText()->setPosition((posX) + (BUTTON_WIDTH*(count)) + 32,(posY) - 2 + 32);
    }
    else if(mod == 0){                            // sobald 5 icons = naechste reihe
       button->getSprite()->setPosition(posX,posY*(count/5) + 32);
       button->getText()->setPosition(posX+32,posY*(count/5) +32 - 2);
       line++;
       lineChanged = true;
    }
    else{
        button->getSprite()->setPosition((posX) + (BUTTON_WIDTH*(count - line )),posY*line); //Put in line
        button->getText()->setPosition((posX) + (BUTTON_WIDTH*(count - line)) + 32,(posY*line) - 2);
        lineChanged = false;
    }
    std::cout<<"id="<<button->getId()<<"x="<<button->getSprite()->getPosition().x<<"y="<<button->getSprite()->getPosition().y<<std::endl;
    
}

ItemButton* ItemMenu::getButton(int i){
    return buttons[i];
}

ItemButton* ItemMenu::getButtonById(int id){
    ItemButton* button;
    
    for(int i = 0; i < buttons.size(); i++ ){
        if(buttons[i]->getId() == id){
            button = buttons[i];
        }
    }
    return button;
}
                               

std::vector<ItemButton*> ItemMenu::getButtons(){
    return buttons;
}

