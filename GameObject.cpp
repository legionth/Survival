/* 
 * File:   GameObject.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 12:06
 */

#include <SFML/Graphics/Texture.hpp>

#include "GameObject.h"

GameObject::GameObject() {
    frameWidth = 64;
    frameHeight = 64;
}

GameObject::GameObject(const GameObject& orig) {
}

GameObject::~GameObject() {
}

void GameObject::setImage(std::string fileName){
    sf::Texture* texture = new sf::Texture();
    if(texture->loadFromFile(fileName)){
        return;
    }
    else{
        sprite->setTexture(*texture);
    }
}

void GameObject::setImage(sf::Texture* texture){
    sprite->setTexture(*texture);
}

void GameObject::setLife(int l){
    this->life = l;
}

void GameObject::setFrameWidth(int width){
    this->frameWidth = width;
}

void GameObject::setFrameHeight(int height){
    this->frameHeight = height;
}
    
int GameObject::getFrameWidth(){
    return this->frameWidth;
}

int GameObject::getFrameHeight(){
    return this->frameHeight;
}
int GameObject::getLife(){
    return this->life;
}

