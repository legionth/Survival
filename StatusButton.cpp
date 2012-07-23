/* 
 * File:   StatusButton.cpp
 * Author: legionth
 * 
 * Created on 19. Juli 2012, 23:04
 */

#include "StatusButton.h"

StatusButton::StatusButton(int id) {
    this->id = id;
    this->setFrameSize(STATUS_BUTTON_WIDTH,STATUS_BUTTON_HEIGHT);
}

StatusButton::StatusButton(const StatusButton& orig) {
}

StatusButton::~StatusButton() {
}

int StatusButton::getId(){
    return this->id;
}


