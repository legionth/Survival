/* 
 * File:   GameObject.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 12:06
 */

#include <SFML/Graphics/Texture.hpp>

#include "GameObject.h"
#include "Game.h"

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

int GameObject::getNumberOfFrames(){
    unsigned int height = this->getSprite()->getTexture()->getHeight();
    unsigned int width =  this->getSprite()->getTexture()->getWidth();
    
    return height/width;
}

void GameObject::startAnimation(int startFrame, int endFrame){
    setCurrentFrame(startFrame);
    setStartFrame(startFrame);
    setStopFrame(endFrame);
    isPlaying = true;
    fps = 7;
}

void GameObject::stopAnimation(){
    clock.restart();
    isPlaying = false;
}

void GameObject::updateAnimation(){
    if(isPlaying){
        int frameCount = getStopFrame() - getStartFrame();
 	float timePosition = (clock.getElapsedTime().asSeconds() * fps);
                
	setCurrentFrame(getStartFrame() + (int)timePosition % frameCount);
        getSprite()->setTextureRect(getFrameRect(this->getCurrentFrame()));
        if(getCurrentFrame() == getStopFrame()){
            stopAnimation();
        }
    }
    else{
        setFrameRect(getCurrentFrame());
    }
}

sf::IntRect GameObject::getFrameRect(int frame){
    unsigned int width = (getSprite()->getTexture()->getWidth() / getFrameWidth());
    unsigned int height = (getSprite()->getTexture()->getHeight() / getFrameHeight());
    int tileY = frame / width;
    int tileX = frame % width;
    
    sf::IntRect rect(tileX*getFrameWidth(),
       		     tileY*getFrameHeight(),
                     tileX*getFrameWidth() + getFrameWidth(),
                     tileY*getFrameHeight() + getFrameHeight());

    return rect;
}

void GameObject::setStartFrame(int frame){
    this->startFrame = frame;
}

void GameObject::setStopFrame(int frame){
    this->stopFrame = frame;
}

void GameObject::setCurrentFrame(int frame){
    this->currentFrame = frame;
}

void GameObject::setFrameRect(int frame){
 //   this->getSprite()->setTextureRect(ge)
}


int GameObject::getStartFrame(){
    return startFrame;
}
    

int GameObject::getStopFrame(){
    return stopFrame;
}

int GameObject::getCurrentFrame(){
    return this->currentFrame;
}

void GameObject::setFrameSize(int width, int height){
    this->frameWidth = width;
    this->frameHeight = height;
}

sf::Sprite* GameObject::getSprite(){
    return this->sprite;
}
