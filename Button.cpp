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
    this->id = 0;
    this->ressource = 0;
}

Button::Button(int frameRect,sf::Texture* tex,std::string buttonName){
    this->pressed = false;
    this->name = buttonName;
    this->setImage(tex);
    setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
    setFrameRect(frameRect);
    this->visible = true;
    this->ressource = 0;
}

Button::Button(int frameRect,sf::Texture* tex,std::string buttonName,int sizeX,int sizeY){
    this->pressed = false;
    this->name = buttonName;
    this->setImage(tex);
    setFrameSize(sizeX,sizeY);
    setFrameRect(frameRect);
    this->visible = true;
    this->id = 0;
    this->ressource = 0;
}

Button::Button(int frameRect,sf::Texture* tex,int id){
    this->pressed = false;
    this->setImage(tex);
    setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
    setFrameRect(frameRect);
    this->visible = true;
    this->id = id;
    this->ressource = 0;
}

Button::Button(std::string buttonName){
    this->pressed = false;
    this->name = buttonName;
    this->id = 0;
    this->ressource = 0;
}

Button::Button(const Button& orig) {
}

Button::~Button() {
      if(this->ressource != 0){
        delete ressource;
    }
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

void Button::setVisible(bool vis){
    this->visible = vis;
}

bool Button::isVisible(){
    return this->visible;
}

void Button::setId(int i){
    this->id = i;
}

int Button::getId(){
    return this->id;
}

Ressource* Button::getRessource(){
    return this->ressource;
}

void Button::setRessource(Ressource* res){
    this->ressource = res;
    this->ressource->getSprite()->setPosition(getSprite()->getPosition().x, getSprite()->getPosition().y);
}

 void Button::setRessource(Ressource* res,bool setSprite){
    this->ressource = res;
    
    if(setSprite){
        this->ressource->getSprite()->setPosition(getSprite()->getPosition().x, getSprite()->getPosition().y);
    }
 }
