/* 
 * File:   TileMap.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:57
 */

#include "TileMap.h"
#include "Tile.h"

TileMap::TileMap() {
    
}

TileMap::TileMap(int x,int y) {
    this->xPos = x;
    this->yPos = y;
}

TileMap::TileMap(const TileMap& orig) {
}

TileMap::~TileMap() {
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
           tileMap[y][x]->getSprite()->setPosition(x*128,y*128);
           tileMap[y][x]->setFrameSize(64,64);
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
