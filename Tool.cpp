/* 
 * File:   Tool.cpp
 * Author: niels
 * 
 * Created on 25. Juli 2012, 08:36
 */

#include "Tool.h"
#include "Ressource.h"

Tool::Tool(int id,sf::Texture* tex) {
    //setId(id);
    this->setImage(tex);
    setFrameSize(64,64);
    std::cout<<"wat"<<std::endl;
    setIdentifier(id);
   // setUsable(true);
}

Tool::Tool(const Tool& orig) {
}

Tool::~Tool() {
}

void Tool::setId(int id){
    this->id = id;
}

int Tool::getId(){
   return this->id; 
}
