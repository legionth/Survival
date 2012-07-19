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
    isPlaying = false;
    life = 3;
}

GameObject::GameObject(const GameObject& orig) {
}

GameObject::~GameObject() {
    delete sprite;
}

void GameObject::setImage(std::string fileName){
    //sf::Texture* texture = new sf::Texture();
    sf::Texture texture;
    if(!texture.loadFromFile(fileName)){
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
    unsigned int height = this->getSprite()->getTexture()->getSize().y;
    unsigned int width =  this->getSprite()->getTexture()->getSize().x;
    
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
        //std::cout<<"updateAnimation"<<getFrameWidth()<<"bla"<<getFrameHeight()<<std::endl;
    }
    else{
        setFrameRect(getCurrentFrame());
    }
}

sf::IntRect GameObject::getFrameRect(int frame){
    unsigned int width = (getSprite()->getTexture()->getSize().x / getFrameWidth());
    unsigned int height = (getSprite()->getTexture()->getSize().y / getFrameHeight());
   // std::cout<<"width"<<width<<std::endl;
    int tileX = frame % width;
    int tileY = frame / width;
    
    sf::IntRect rect(tileX*getFrameWidth(),
       		     tileY*getFrameHeight(),
                     getFrameWidth(),
                     getFrameHeight());                 // describes now the length and heigth not the end point see SFML docu
    
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
   // std::cout<<"framerect"<<getSprite()<<std::endl;
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
    getSprite()->setPosition(getXPos() * getFrameWidth(), getYPos() * getFrameHeight());
}

void GameObject::setYPos(int y){
    this->yPos = y;
    getSprite()->setPosition(getXPos() * getFrameWidth(),getYPos() * getFrameHeight());
}

void GameObject::setPos(int x, int y){
    this->xPos = x;
    this->yPos = y;
    getSprite()->setPosition(getXPos() * getFrameWidth(),getYPos() * getFrameHeight());
}

void GameObject::setPos(int x,int y,bool setSprite){
    this->xPos = x;
    this->yPos = y;
    
    if(setSprite){
        getSprite()->setPosition(getXPos() * getFrameWidth(),getYPos() * getFrameHeight());
    }
}

void GameObject::setSpritePosition(int x, int y){
    std::cout<<"x"<<x<<"y"<<y<<std::endl;
    this->getSprite()->setPosition(x,y);
}

int GameObject::getXPos(){
    return xPos;
}

int GameObject::getYPos(){
    return yPos;
}


