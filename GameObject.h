/* 
 * File:   GameObject.h
 * Author: niels
 *
 * Created on 30. April 2012, 12:06
 */
#include <SFML/Graphics.hpp>
#include "consts.h"
#include <iostream>
#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

class GameObject {
public:
    GameObject();
    GameObject(const GameObject& orig);
    virtual ~GameObject();

    void setLife(int l);
    // Animation & Drawing
    void setFrameWidth(int width);
    void setFrameHeight(int height);
    void setFrameSize(int width, int height);
    
    void setStartFrame(int frame);
    void setStopFrame(int frame);
    void startAnimation(int startFrame, int stopFrame);
    void stopAnimation();
    void updateAnimation();
    void setCurrentFrame(int frame);
    void setFrameRect(int frame);
    
    int getNumberOfFrames();
    sf::IntRect getFrameRect(int frame);
    
    int getFrameWidth();
    int getFrameHeight();
    int getStartFrame();
    int getStopFrame();
    int getCurrentFrame();
    
    int getLife();
    
    int getXPos();
    int getYPos();
    sf::Sprite* getSprite();
    
    void setSprite(sf::Sprite* sprite);
    void setImage(std::string fileName);
    void setImage(sf::Texture* texture);
    void setXPos(int x);
    void setYPos(int y);
    void setPos(int x,int y);
    void setPos(int x,int y,bool setSprite);
    void setSpritePosition(int x, int y);


private:
    int life;
    sf::Sprite* sprite;
    
    int frameWidth;
    int frameHeight;
    int currentFrame;
    int startFrame;
    int stopFrame;
    bool isPlaying;
    int fps;
    sf::Clock clock;
    
    int xPos;
    int yPos;
};

#endif	/* GAMEOBJECT_H */

