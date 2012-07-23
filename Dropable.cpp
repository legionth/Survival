/* 
 * File:   Dropable.cpp
 * Author: legionth
 * 
 * Created on 23. Juli 2012, 14:35
 */

#include <vector>

#include "Dropable.h"

Dropable::Dropable() {
}

Dropable::Dropable(sf::Texture* tex) {
    this->ressourceTex = tex;
}

Dropable::~Dropable() {
    dropList.clear();
}

void Dropable::addDrop(int ressource){
    dropList.push_back(ressource);
}

void Dropable::drop(Tile* tile){
    int size = dropList.size();
    int rnd = rand() % size;

    tile->setRessource(new Ressource(dropList[rnd], ressourceTex));
}

 void Dropable::setRessourceTexture(sf::Texture* tex){
     this->ressourceTex = tex;
 }