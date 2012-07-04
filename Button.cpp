/* 
 * File:   Button.cpp
 * Author: niels
 * 
 * Created on 21. Juni 2012, 07:55
 */

#include "Button.h"
#include "Building.h"
#include <iostream>

Button::Button(){
    this->pressed = false;
}

Button::Button(int frameRect,sf::Texture* tex,std::string buttonName){
    this->pressed = false;
    this->name = buttonName;
    this->setImage(tex);
    setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
    setFrameRect(frameRect);
}

Button::Button(int frameRect,sf::Texture* tex,std::string buttonName,int sizeX,int sizeY){
    this->pressed = false;
    this->name = buttonName;
    this->setImage(tex);
    setFrameSize(sizeX,sizeY);
    setFrameRect(frameRect);
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
    
    if(pressed){
        setFrameRect(getCurrentFrame() + 1);
    }
    else{
        setFrameRect(getCurrentFrame() - 1);
    }
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

void Button::setPressed(bool press){
    this->pressed = press;
}


