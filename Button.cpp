/* 
 * File:   Button.cpp
 * Author: niels
 * 
 * Created on 21. Juni 2012, 07:55
 */

#include "Button.h"
#include "Building.h"

Button::Button() {
    this->pressed = false;
}

Button::Button(std::string buttonName){
    this->pressed = false;
    this->name = buttonName;
}

Button::Button(const Button& orig) {
}

Button::~Button() {
}

void Button::press(){
    this->pressed = !isPressed();
}

bool Button::isPressed(){
    return this->pressed;
}

void Button::setName(std::string name){
    this->name = name;
}

std::string Button::getName(){
    return this->name;
}

