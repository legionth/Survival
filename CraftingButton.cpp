/* 
 * File:   CraftingButton.cpp
 * Author: niels
 * 
 * Created on 29. August 2012, 08:53
 */

#include "CraftingButton.h"

CraftingButton::CraftingButton(int frameRect,sf::Texture* tex,int id,sf::Texture* texRes): Button(frameRect,tex,id){
    setFrameSize(BUTTON_WIDTH,BUTTON_HEIGHT);
   // setAlchemy(new Potion(id,texAlchemy,rectAlchemy));
    setVisible(false);
    ressource = new Ressource(id,texRes);
    //ressource->setIdentifier(id);       
    //this->potion = new Potion(id);
}

CraftingButton::CraftingButton(const CraftingButton& orig) {
}

CraftingButton::~CraftingButton() {
    delete this->ressource;
}

void CraftingButton::setRessource(Ressource* res){
    this->ressource = res;
}

Ressource* CraftingButton::getRessource(){
    return new Ressource(this->ressource);
}

