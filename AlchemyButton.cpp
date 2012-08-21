#include "AlchemyButton.h"
#include <iostream>

AlchemyButton::AlchemyButton(int frameRect,sf::Texture* tex,int id) 
                              : Button(frameRect,tex,id){
    
    setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
   // setAlchemy(new Potion(id,texAlchemy,rectAlchemy));
    setVisible(false);
    this->potion = new Potion(id);
}

AlchemyButton::AlchemyButton(const AlchemyButton& orig) {
}

AlchemyButton::~AlchemyButton() {
    delete this->potion;
}

void AlchemyButton::setPotion(Potion* p){
    this->potion = p;
}

Potion* AlchemyButton::getPotion(){
    return new Potion(this->getId());
}
