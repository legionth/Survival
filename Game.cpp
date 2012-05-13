/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:44
 */

#include "Game.h"

Game::Game() {
    player = new Player();
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Survival Game");
   // world = new World();
    images["player"] = this->loadImage("player.png");
    std::cout<<"load"<<std::endl;
    player->setImage(images["player"]);
    //player->setImage("player.png");
    std::cout<<"after load"<<std::endl;
    player->getSprite()->setPosition(100,100);
}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete world;
    delete player;
    delete window;
}

void Game::run(){
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
            // Insert Events here
        }
        window->clear();
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
