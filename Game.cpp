/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:44
 */

#include "Game.h"
#include "Menu.h"
#include "BuildingButton.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode((5*FRAME_WIDTH)+(2*FRAME_WIDTH), (5*FRAME_HEIGHT)+(2*FRAME_HEIGHT)), "Survival Game");
    images["player"] = this->loadImage("player.png");
    images["land"] = this->loadImage("land.png");
    images["ressources"] = this->loadImage("ressources.png");
    images["menuBuilding"] = this->loadImage("menu_building.png");
    images["buttonBuilding"] = this->loadImage("button_building.png");
    images["buildings"] = this->loadImage("buildings.png");
    
    world = new World(images["land"]);
    player = new Player(images["player"]);
    player->setTileMap(getTileMap(0,0));
    player->setPos(1,1);
    
    getTileMap(0,0)->loadTileMap("map0_0.map");
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
   
    Ressource* res = new Ressource(RES_WOOD,images["ressources"]);
    getTileMap(0,0)->getTile(0,1)->setRessource(res);
    Ressource* res2 = new Ressource(RES_WOOD,images["ressources"]);
    getTileMap(0,0)->getTile(1,1)->setRessource(res2);
    
      buildMenu = new Menu(FRAME_WIDTH * 5,0,128,512);
      buildMenu->setImage(images["menuBuilding"]);
      Building *building = new Building('^',images["buildings"],1);
      BuildingButton *button = new BuildingButton(1,images["buttonBuilding"],"tent",building);
      buildMenu->addButton(button);
    
  //  statusMenu = new Menu(FRAME_WIDTH * 5,0,256,128);
}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete world;
    delete player;
    delete window;
    delete buildMenu;
    delete statusMenu;
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
                    player->move(MOVE_UP,world);
                }
                else if(event.key.code == sf::Keyboard::D){
                    player->move(MOVE_RIGHT,world);
                }
                else if(event.key.code == sf::Keyboard::S){
                    player->move(MOVE_DOWN,world);
                }
                else if(event.key.code == sf::Keyboard::A){
                    player->move(MOVE_LEFT,world);
                }
                if(event.key.code == sf::Keyboard::Space){
                    if(player->getTileMap()->getTile(player->getXPos(),player->getYPos())->getRessource() != 0){
                        player->pickup(player->getTileMap()->getTile(player->getXPos(),player->getYPos()));
                    }
                }
            }
            else if(event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::W ||
                                                             event.key.code == sf::Keyboard::D ||
                                                             event.key.code == sf::Keyboard::S ||
                                                             event.key.code == sf::Keyboard::A)
                   ){
                player->stopAnimation();
            }
        }
        
        
        generateRessoruces();
        // Draw the things
        window->clear();
        
        for(int y = 0; y < getCurrentTileMap()->getYSize(); y++){
            for(int x = 0; x < getCurrentTileMap()->getXSize(); x++){
                Tile* tile = getCurrentTileMap()->getTile(x,y);
                sf::Sprite *sprite = tile->getSprite();
                window->draw(*sprite);
                
                if(tile->getRessource() != 0){
                    window->draw(*tile->getRessource()->getSprite());
                }
            }   
        }
        
        player->updateAnimation();
        window->draw(*player->getSprite());
        window->draw(*buildMenu->getSprite());
        
        for(int i = 0 ; i < buildMenu->getButtons().size(); i++){
            window->draw(*buildMenu->getButton(i)->getSprite());
        }
       // std::cout<<"sprite pos"<<buildMenu->getSprite()->getPosition().x<<" "<<buildMenu->getSprite()->getPosition().y<<std::endl;
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


void Game::generateRessoruces(){
    if(ressourceClock.getElapsedTime().asSeconds() > 5){
        int randomXTileMap = rand() % 5;
        int randomYTileMap = rand() % 5;
        int randomXTile = rand() % 5;
        int randomYTile = rand() % 5;
        
        Tile* tile = world->getTileMap(randomXTileMap,randomYTileMap)->getTile(randomXTile,randomYTile);
        
        if(tile->getWalkAble() && tile->getRessource() == 0){
            int res = rand() % 5;
            Ressource* ressource = new Ressource(res,images["ressources"]);
            
            tile->setRessource(ressource);
            ressourceClock.restart();
          //  std::cout<<"generate Rssource map x="<<randomXTileMap<<"map y"<<randomYTileMap<<" x="<<randomXTile<<"y="<<randomYTile<<std::endl;
        }
    }
}