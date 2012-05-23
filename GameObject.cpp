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
    this->sprite = new sf::Sprite();
    frameWidth = 128;
    frameHeight = 128;
    xPos = 0;
    yPos = 0;
}

GameObject::GameObject(const GameObject& orig) {
}

GameObject::~GameObject() {
    delete sprite;
}

void GameObject::setImage(std::string fileName){
    //sf::Texture* texture = new sf::Texture();
    sf::Texture texture;
    if(texture.loadFromFile(fileName)){
        return;
    }
    else{
        sprite->setTexture(texture);
    }
}

void GameObject::setImage(sf::Texture* texture){
    getSprite()->setTexture(*texture);
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
    int tileX = (int)(frame % width);
    int tileY = (int)(frame / width);
    
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
    setCurrentFrame(frame);
    this->getSprite()->setTextureRect(getFrameRect(frame));
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

void GameObject::setXPos(int x){
    this->xPos = x;
    getSprite()->setPosition(getXPos() * FRAME_WIDTH, getYPos() * FRAME_HEIGHT);
}

void GameObject::setYPos(int y){
    this->yPos = y;
    getSprite()->setPosition(getXPos() * FRAME_WIDTH,getYPos() * FRAME_HEIGHT);
}

void GameObject::setPos(int x, int y){
    this->xPos = x;
    this->yPos = y;
    std::cout<<"x="<<x<<"y="<<y<<std::endl;
    getSprite()->setPosition(getXPos() * FRAME_WIDTH,getYPos() * FRAME_HEIGHT);
}

void GameObject::setPos(int x,int y,bool setSprite){
    this->xPos = x;
    this->yPos = y;
    
    if(setSprite){
        getSprite()->setPosition(getXPos() * FRAME_WIDTH,getYPos() * FRAME_HEIGHT);
    }
}

int GameObject::getXPos(){
    return xPos;
}

int GameObject::getYPos(){
    return yPos;
}


