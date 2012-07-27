/* 
 * File:   SlotButton.cpp
 * Author: legionth
 * 
 * Created on 28. Juli 2012, 00:13
 */

#include "SlotButton.h"

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
}

Tool* SlotButton::getTool(){
    return this->tool;
}

