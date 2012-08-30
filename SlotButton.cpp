/* 
 * File:   SlotButton.cpp
 * Author: legionth
 * 
 * Created on 28. Juli 2012, 00:13
 */

#include "SlotButton.h"
#include <iostream>

SlotButton::SlotButton(Tool* tool,sf::Texture* tex) {
    this->tool = tool;
    setImage(tex);
    setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
    setFrameRect(RECT_SLOT_EMPTY);
}

SlotButton::SlotButton(const SlotButton& orig) {
}

SlotButton::~SlotButton() {
}

void SlotButton::setTool(Tool* tool){
    this->tool = tool;
    std::cout<<"setTool"<<std::endl;
    tool->getSprite()->setPosition(this->getSprite()->getPosition().x,this->getSprite()->getPosition().y);
    std::cout<<"setTool after pos"<<std::endl;
}

Tool* SlotButton::getTool(){
    return this->tool;
}

