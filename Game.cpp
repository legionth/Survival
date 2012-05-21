/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:44
 */

#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(5*128, 5*128), "Survival Game");
    images["player"] = this->loadImage("player.png");
    images["land"] = this->loadImage("land.png");

    world = new World(images["land"]);
    player = new Player(images["player"]);
    player->getSprite()->setPosition(256,128);
    player->setTileMap(getTileMap(0,0));
    getTileMap(0,0)->loadTileMap("map0_0.map");
}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete world;
    delete player;
    delete window;
    images.clear();
}

void Game::run(){
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
        }
        window->clear();
        for(int y = 0; y < getCurrentTileMap()->getYSize(); y++){
            for(int x = 0; x < getCurrentTileMap()->getXSize(); x++){
                sf::Sprite *sprite = getCurrentTileMap()->getTile(x,y)->getSprite();
                window->draw(*sprite);
            }   
        }
        
        window->draw(*player->getSprite());
        window->display();
    }
}

sf::Texture* Game::loadImage(std::string fileName){
    sf::Texture *texture = new sf::Texture();
    if(!texture->loadFromFile(fileName)){
        std::cout<<"No File was found with name: "<<fileName<<std::endl;
        return NULL;
    }
    return texture;
}

sf::Texture* Game::loadImage(std::string fileName,int position,int width,int height){
    sf::Texture *texture = new sf::Texture();
    if(!texture->loadFromFile(fileName)){
        std::cout<<"No File was found with name: "<<fileName<<std::endl;
        return NULL;
    }
    return texture;
}

TileMap* Game::getCurrentTileMap(){
    return player->getTileMap();
}

TileMap* Game::getTileMap(int x, int y){
    return world->getTileMap(x,y);
}
