/* 
 * File:   GameObject.h
 * Author: niels
 *
 * Created on 30. April 2012, 12:06
 */
#include <SFML/Graphics.hpp>
#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

class GameObject {
public:
    GameObject();
    GameObject(const GameObject& orig);
    virtual ~GameObject();
    
    void setLife(int l);
    void setFrameWidth(int width);
    void setFrameHeight(int height);
    
    int getFrameWidth();
    int getFrameHeight();
    int getLife();
    sf::Sprite* getSprite();
    void setSprite(sf::Sprite* sprite);
    void setImage(std::string fileName);
    void setImage(sf::Texture* texture);

private:
    int life;

    sf::Sprite* sprite;
    int frameWidth;
    int frameHeight;
};

#endif	/* GAMEOBJECT_H */

