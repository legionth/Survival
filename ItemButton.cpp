/* 
 * File:   ItemButton.cpp
 * Author: legionth
 * 
 * Created on 4. Juli 2012, 21:54
 */

#include "ItemButton.h"
#include <iostream>
ItemButton::ItemButton() {
}

ItemButton::ItemButton(const ItemButton& orig) {
}

ItemButton::~ItemButton() {
    delete this->text;
}

ItemButton::ItemButton(int frameRect,sf::Texture* tex,int id){
    this->id = id;
    this->setImage(tex);
    setFrameSize(32,32);
    setFrameRect(frameRect);
    
    text = new sf::Text();
    updateCount(0);
}

sf::Text* ItemButton::getText(){
    return this->text;
}


void ItemButton::setCount(int i){
    updateCount(i);
}

void ItemButton::updateCount(int i){
    this->count = i;
    std::stringstream ss;
    ss << count;
    text->setString("x "+ss.str());
    text->setColor(sf::Color::Black);
    text->setCharacterSize(20);
}

int ItemButton::getId(){
    return this->id;
}
