/* 
 * File:   ItemButton.cpp
 * Author: legionth
 * 
 * Created on 4. Juli 2012, 21:54
 */

#include "ItemButton.h"

ItemButton::ItemButton() {
}

ItemButton::ItemButton(const ItemButton& orig) {
}

ItemButton::~ItemButton() {
    delete this->text;
}

ItemButton::ItemButton(int frameRect,sf::Texture* tex,char id){
    this->id = id;
    this->count = 0;
    this->setImage(tex);
    setFrameSize(16,16);
    setFrameRect(frameRect);
    text = new sf::Text();
    text->setString("x "+count);
}

sf::Text* ItemButton::getText(){
    return this->text;
}


void ItemButton::setCount(int i){
    this->count = i;
}
