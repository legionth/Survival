/* 
 * File:   TileMap.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:57
 */

#include "TileMap.h"
#include <iostream>

TileMap::TileMap(sf::Texture* img, int x, int y) {
    std::cout<<"tileMap constr"<<std::endl;
    this->xPos = x;
    this->yPos = y;
    this->xSize = 5;
    this->ySize = 5;
    
    tileMap.resize(getYSize());
    for(int i = 0; i < getYSize();i++){
        tileMap[i].resize(getXSize());
    }
    
    for(int y = 0; y < getYSize(); y++){
        for(int x = 0; x < getXSize(); x++){
            tileMap[y][x] = new Tile(img,x,y);
        }
    }
}

TileMap::TileMap(int x,int y) {
    this->xPos = x;
    this->yPos = y;
}

TileMap::TileMap(const TileMap& orig) {
}

TileMap::~TileMap() {
    tileMap.clear();
}

 void TileMap::loadTileMap(std::string fileName){
    std::ifstream file(fileName.c_str());
    if(!file.is_open()){
//        std::cout<<"Datei konnte nicht geöffnet werden"<<std::endl;
    }
    std::string line;
    
  // sizeTileMap();
    int y = 0;
    int x = 0;
    
    while(!file.eof()){                                                         //quasi y
        std::getline(file,line);
        for (std::string::iterator i = line.begin(); i != line.end(); i++){     //quasi x
           tileMap[y][x]->setIdentifier(*i);
           tileMap[y][x]->setPos(x,y,true);
           tileMap[y][x]->setFrameSize(128,128);
            x++;
        }
        x=0;
        y++;
    }
    file.close();
 }
 
 int TileMap::getXPos(){
     return yPos;
 }
 
 int TileMap::getYPos(){
     return xPos;
 }
    
 void TileMap::setXPos(int x){
     this->xPos = x;
 }
 
 void TileMap::setYPos(int y){
     this->yPos = y;
 }
 
void TileMap::setIdentifierOnTile(int x,int y, char c){
    tileMap[y][x]->setIdentifier(c);
}

int TileMap::getXSize(){
    return this->xSize;
}

int TileMap::getYSize(){
    return this->ySize;
}

Tile* TileMap::getTile(int x,int y){
    return this->tileMap[y][x];
}
