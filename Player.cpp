/* 
 * File:   Player.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:51
 */

#include "Player.h"

Player::Player(sf::Texture* img) {
    this->setLife(3);
    this->setImage(img);
    this->setFrameRect(0);
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

