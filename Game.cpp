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
    player->setTileMap(getTileMap(0,0));
    player->setPos(1,1);
    getTileMap(0,0)->loadTileMap("map0_0.map");
   /* 
    getTileMap(0,1)->loadTileMap("map0_1.map");
    getTileMap(0,2)->loadTileMap("map0_2.map");
    getTileMap(0,3)->loadTileMap("map0_3.map");
    getTileMap(0,4)->loadTileMap("map0_4.map");
    getTileMap(1,0)->loadTileMap("map1_0.map");
    getTileMap(1,1)->loadTileMap("map1_1.map");
    getTileMap(1,2)->loadTileMap("map1_2.map");
    getTileMap(1,3)->loadTileMap("map1_3.map");
    getTileMap(1,4)->loadTileMap("map1_4.map");
    getTileMap(2,0)->loadTileMap("map2_0.map");
    getTileMap(2,1)->loadTileMap("map2_1.map");
    getTileMap(2,2)->loadTileMap("map2_2.map");
    getTileMap(2,3)->loadTileMap("map2_3.map");
    getTileMap(2,4)->loadTileMap("map2_4.map");
    getTileMap(3,0)->loadTileMap("map3_0.map");
    getTileMap(3,1)->loadTileMap("map3_1.map");
    getTileMap(3,2)->loadTileMap("map3_2.map");
    getTileMap(3,3)->loadTileMap("map3_3.map");
    getTileMap(3,4)->loadTileMap("map3_4.map");
    getTileMap(4,0)->loadTileMap("map4_0.map");
    getTileMap(4,1)->loadTileMap("map4_1.map");
    getTileMap(4,2)->loadTileMap("map4_2.map");
    getTileMap(4,3)->loadTileMap("map4_3.map");
    getTileMap(4,4)->loadTileMap("map4_4.map");
    */
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
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W){
                    player->move(MOVE_UP);
                }
                else if(event.key.code == sf::Keyboard::D){
                    player->move(MOVE_RIGHT);
                }
                else if(event.key.code == sf::Keyboard::S){
                    player->move(MOVE_DOWN);
                }
                else if(event.key.code == sf::Keyboard::A){
                    player->move(MOVE_LEFT);
                }
                
                if(player->getXPos() > 5){
                    player->setTileMap(world->getTileMap(getCurrentTileMap()->getXPos()+1,getCurrentTileMap()->getYPos()));
                }
                if(player->getYPos() > 5){
                    player->setTileMap(world->getTileMap(getCurrentTileMap()->getXPos(),getCurrentTileMap()->getYPos()+1));
                }
                if(player->getXPos() < 0){
                    player->setTileMap(world->getTileMap(getCurrentTileMap()->getXPos()-1,getCurrentTileMap()->getYPos()));
                }
                if(player->getYPos() < 0){
                    player->setTileMap(world->getTileMap(getCurrentTileMap()->getXPos(),getCurrentTileMap()->getYPos()-1));
                }
            }
        }
        
        // Draw the things
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
