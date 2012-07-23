/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:44
 */

#include "Game.h"
#include "Menu.h"
#include "BuildingButton.h"
#include "BuildingMenu.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode((5*FRAME_WIDTH)+(2*FRAME_WIDTH), (5*FRAME_HEIGHT)+(2*FRAME_HEIGHT)), "Survival Game");
    images["player"] = this->loadImage("player.png");
    images["land"] = this->loadImage("land.png");
    images["ressources"] = this->loadImage("ressources.png");
    images["menuBuilding"] = this->loadImage("menu_building.png");
    images["menuItem"] = this->loadImage("menu_item.png");
    images["menuStatus"] = this->loadImage("menu_status.png");
    images["buttonBuilding"] = this->loadImage("button_building.png");
    images["buttonItem"] = this->loadImage("button_item.png");
    images["buildings"] = this->loadImage("buildings.png");
    images["enemyPig"] = this->loadImage("enemy_pig.png");
    images["buttonStatus"] = this->loadImage("button_status.png");

    
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
    
    
    /**
     * Building menu buttons
     */
    buildMenu = new BuildingMenu(FRAME_WIDTH * 5,0,128,512);
    buildMenu->setImage(images["menuBuilding"]);
    
    BuildingButton *button = new BuildingButton(BUTTON_BUILDING_RECT_TENT,images["buttonBuilding"],BUILDING_RECT_TENT,images["buildings"],"tent",BUILDING_TENT);
    buildMenu->addButton(button);
    button->press();
    
    button = new BuildingButton(BUTTON_BUILDING_RECT_FIREPLACE,images["buttonBuilding"],BUILDING_RECT_FIREPLACE,images["buildings"],"fireplace",BUILDING_FIREPLACE);
    buildMenu->addButton(button);
    
    
    
    
    /**
     * Item Menu buttons
     */
    itemMenu = new ItemMenu(FRAME_WIDTH * 5,FRAME_HEIGHT * 5,256,256);
    itemMenu->setImage(images["menuItem"]);
    
    ItemButton* itemButton = new ItemButton(0,images["buttonItem"],RES_WOOD);
    itemMenu->addButton(itemButton);
    
    itemButton = new ItemButton(1,images["buttonItem"],RES_STONE);
    itemMenu->addButton(itemButton);
    
    itemButton = new ItemButton(2,images["buttonItem"],RES_LEATHER);
    itemMenu->addButton(itemButton);
    
    itemButton = new ItemButton(3,images["buttonItem"],RES_IRON_ORE);
    itemMenu->addButton(itemButton);
    
    itemButton = new ItemButton(4,images["buttonItem"],RES_GOLD_ORE);
    itemMenu->addButton(itemButton);
    
    itemButton = new ItemButton(5,images["buttonItem"],RES_SILVER_ORE);
    itemMenu->addButton(itemButton);
    
  //  this->spawnEnemy();
    enemies.push_back(new Enemy(world->getTileMap(0,0),0,0,images["enemyPig"],9,0,images["ressources"]));
    pressedW = false;
    pressedA = false;
    pressedS = false;
    pressedD = false;
    /**
     * Status Menu init
     */
    statusMenu = new StatusMenu(0,FRAME_HEIGHT * 5,640,256);
    statusMenu->setImage(images["menuStatus"]);
    
    // Life init
    StatusButton* statusButton = new StatusButton(STATUS_BUTTON_LIFE);
    statusButton->setImage(images["buttonStatus"]);
        
    statusButton->setFrameRect(0);
    statusMenu->setLifeButton(statusButton);
    
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
    enemies.clear();
}

void Game::run(){
    while(window->isOpen()){
        sf::Event event;
        
        while(window->pollEvent(event)){
        //    std::cout<<"player"<<player->getLife()<<std::endl;
            if(event.type == sf::Event::Closed){
                window->close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W && !player->haveToWalk()){
                    if(!pressedW){
                        player->setCurrentDirection(MOVE_UP);                   // change directeion without walking
                        pressedW = true;
                        disableTypedKey('W');
                    }
                    else{
                        player->move(MOVE_UP,world);
                        disableTypedKey();
                    }
                }
                else if(event.key.code == sf::Keyboard::D && !player->haveToWalk()){
                   if(!pressedD){
                        player->setCurrentDirection(MOVE_RIGHT);
                        pressedD = true;
                        disableTypedKey('D');
                    }
                    else{
                        player->move(MOVE_RIGHT,world);
                        disableTypedKey();
                    }
                }
                else if(event.key.code == sf::Keyboard::S && !player->haveToWalk()){
                    if(!pressedS){
                        player->setCurrentDirection(MOVE_DOWN);
                        pressedS = true;
                        disableTypedKey('S');
                    }
                    else{
                        player->move(MOVE_DOWN,world);
                        disableTypedKey();
                    }
                }
                else if(event.key.code == sf::Keyboard::A && !player->haveToWalk()){
                    if(!pressedA){
                        player->setCurrentDirection(MOVE_LEFT);
                        pressedA = true;
                        disableTypedKey('A');
                    }
                    else{
                        player->move(MOVE_LEFT,world);
                        disableTypedKey();
                    }
                }
                else if(event.key.code == sf::Keyboard::E && !player->haveToWalk()){
                    int direction = player->getCurrentDirection();
                    int x = 0;
                    int y = 0;
                    
                    switch(direction){
                        case MOVE_UP:
                            x = player->getXPos();
                            y = player->getYPos() - 1;
                            break;
                        case MOVE_DOWN:
                            x = player->getXPos();
                            y = player->getYPos() + 1;
                            break;
                        case MOVE_RIGHT:
                            x = player->getXPos() + 1;
                            y = player->getYPos();
                            break;
                        case MOVE_LEFT:
                            x = player->getXPos() - 1;
                            y = player->getYPos();
                            break;
                    }
                    
                    if((x >= 0 && x < 5) && (y >= 0 && y < 5) && player->getTileMap()->getTile(x,y)->getLivingObject() != 0){
                        player->attack(player->getTileMap()->getTile(x,y)->getLivingObject());
                    }
                    
                }
                
                // Pickup
                if(event.key.code == sf::Keyboard::Space){
                    if(player->getTileMap()->getTile(player->getXPos(),player->getYPos())->getRessource() != 0){
                        int id = player->getTileMap()->getTile(player->getXPos(),player->getYPos())->getRessource()->getIdentifier();
                        player->pickup(player->getTileMap()->getTile(player->getXPos(),player->getYPos()));
                        itemMenu->getButtonById(id)->updateCount(player->getRessourceCountById(id));
                    }
                }
                
                
                // Toggle throug button Menu
                if(event.key.code == sf::Keyboard::Right){
                    BuildingButton* selectedButton = 0;
                    int number = 0;
                    int count = buildMenu->getButtons().size();
                    
                    for(int i = 0; i < count; i++){
                        if(buildMenu->getButton(i)->isPressed()){
                            selectedButton = buildMenu->getButton(i);
                            number = i;
                        }
                    }
                    
                    if(number + 1 < count){
                        selectedButton->press();
                        buildMenu->getButton(number + 1)->press();
                    }
                 }
                
                if(event.key.code == sf::Keyboard::Left){
                    BuildingButton* selectedButton = 0;
                    int number = 0;
                    int count = buildMenu->getButtons().size();
                    
                    for(int i = 0; i < count; i++){
                        if(buildMenu->getButton(i)->isPressed()){
                            selectedButton = buildMenu->getButton(i);
                            number = i;
                        }
                    }
                    
                    if(number - 1 >= 0){
                        selectedButton->press();
                        buildMenu->getButton(number - 1)->press();
                    }
                 }
                
                // Build a Building :P
                if(event.key.code == sf::Keyboard::Return){
                    
                    for(int i = 0; i < buildMenu->getButtons().size(); i++){
                        if(buildMenu->getButton(i)->isPressed()){
                            Building *building = buildMenu->getButton(i)->getBuilding();
                            int currentDirection = player->getCurrentDirection();
                            int posX = player->getXPos();
                            int posY = player->getYPos();
                            TileMap* map = player->getTileMap();
                            
                            // Check if can be build
                            bool canBuild = true;
                            std::map<int,int> ressourcesPlayer = player->getRessources();
                            std::map<int,int> ressourcesBuilding = building->getRessources();
                            int size = ressourcesPlayer.size();
                            
                            for(int i = 0; i < size;i++){
                                if(ressourcesPlayer[i] < ressourcesBuilding[i]){
                                    canBuild = false;
                                }
                            }
                            
                            if(canBuild){
                                switch(currentDirection){
                                    case MOVE_UP:
                                        if(posY - 1 > 0){
                                            map->getTile(posX,posY - 1)->setBuilding(building);
                                        }
                                        break;
                                    case MOVE_DOWN:
                                        if(posY + 1 < 4){
                                            map->getTile(posX,posY + 1)->setBuilding(building);
                                        }
                                        break;
                                    case MOVE_RIGHT:
                                        if(posX + 1 < 4){
                                            map->getTile(posX + 1,posY)->setBuilding(building);
                                        }
                                        break;
                                    case MOVE_LEFT:
                                        if(posX - 1 > 0){
                                            map->getTile(posX - 1,posY)->setBuilding(building);
                                        }
                                        break;
                                    default:
                                        std::cout<<"break up building"<<std::endl;
                                        break;    
                                }
                                
                                player->decreaseRessources(ressourcesBuilding);
                                ressourcesPlayer = player->getRessources();
                                
                                for(int i = 0 ; i < itemMenu->getButtons().size(); i++){
                                        ItemButton* itemButton = itemMenu->getButton(i);
                                        itemButton->setCount(ressourcesPlayer[itemButton->getId()]);
                                //        std::cout<<"id"<<itemButton->getId()<<"="<<ressourcesPlayer[itemButton->getId()]<<std::endl;
                                }
                            }
                        }
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
        
        if(player->haveToWalk()){
            player->move(player->getCurrentDirection(),world);
          //  std::cout<<"direction"<<player->getCurrentDirection()<<std::endl;
        }
        else if(!player->haveToAttack()){
            player->setCurrentFrame(player->getDirectionRect());
        }
        
        generateRessoruces();
      //  spawnEnemy();
        if(player->haveToAttack()){
                player->stopAttackAnimation();
        }
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
                if(tile->getBuilding() != 0){
                    tile->getBuilding()->updateAnimation();
                    window->draw(*tile->getBuilding()->getSprite());  
                   // std::cout<<"tile"<<"x="<<x<<"y="<<y<<"\t"<<"build"<<"x="<<tile->getBuilding()->getSprite()->getPosition().x<<"y="<<tile->getBuilding()->getSprite()->getPosition().y<<std::endl;
                }
            }   
        }
        
        for(int i = 0; i < enemies.size();i++){
            if(enemies[i]->getLife() == 0){
                enemies[i]->getTileMap()->getTile(enemies[i]->getXPos(),enemies[i]->getYPos())->setLivingObject(0);
                enemies[i]->drop();
                enemies.erase(enemies.begin()+i);
            }
        }
        
        for(int i = 0; i < enemies.size();i++){
            enemies[i]->execute(world);
        }
        player->updateAnimation();
        
        window->draw(*player->getSprite());
        window->draw(*buildMenu->getSprite());
        window->draw(*itemMenu->getSprite());
        window->draw(*statusMenu->getSprite());
        
        statusMenu->drawLifeButton(window,player->getLife());

        
        // Menu drawing
        for(int i = 0 ; i < buildMenu->getButtons().size(); i++){
            window->draw(*buildMenu->getButton(i)->getSprite());
        }
        
        for(int i = 0 ; i < itemMenu->getButtons().size(); i++){
            window->draw(*itemMenu->getButton(i)->getSprite());
            window->draw(*itemMenu->getButton(i)->getText());
        }
        
        // Enemie drawing
        for(int i = 0; i < enemies.size();i++){
           // std::cout<<"life enemy"<<enemies[i]->getLife()<<std::endl;
            if(enemies[i]->getTileMap() == this->getCurrentTileMap()){
                    enemies[i]->updateAnimation();
                    window->draw(*enemies[i]->getSprite());
            }
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
            int res = rand() % 2;
            Ressource* ressource = new Ressource(res,images["ressources"]);
            
            tile->setRessource(ressource);
            ressourceClock.restart();
          //  std::cout<<"generate Rssource map x="<<randomXTileMap<<"map y"<<randomYTileMap<<" x="<<randomXTile<<"y="<<randomYTile<<std::endl;
        }
    }
}


BuildingButton* Game::getSelectedBuildingButton(){
    return this->selectedButton;
}

void Game::setSelectedBuildingButton(BuildingButton* button){
    this->selectedButton = button;
}

void Game::spawnEnemy(){
    if(enemySpawnClock.getElapsedTime().asSeconds() > 5.0f){
        int randomXTileMap = rand() % 5;
        int randomYTileMap = rand() % 5;
        int randomXTile = rand() % 5;
        int randomYTile = rand() % 5;
        int enemyId = rand() % 2;
        sf::Texture* tex = 0;
        
        switch(enemyId){
            case ENEMY_PIG:
                tex = images["enemyPig"];
                break;
            case ENEMY_WOLF:
                tex = 0;
                break;
        }
        
        if(tex != 0){
            enemies.push_back(new Enemy(world->getTileMap(randomXTileMap,randomYTileMap),randomXTile,randomYTile,tex,9,0,images["ressources"]));
          //  std::cout<<"new enemy at tielmap"<<randomXTileMap<<":"<<randomYTileMap<<"tile="<<randomXTile<<":"<<randomYTile<<std::endl;
        }
        
        enemySpawnClock.restart();
    }
}

void Game::disableTypedKey(){
    pressedW = false;
    pressedA = false;
    pressedS = false;
    pressedD = false;
}

void Game::disableTypedKey(char key){
    switch (key){
        case 'W':
            pressedA = false;
            pressedS = false;
            pressedD = false;
            break;
        case 'A':
            pressedW = false;
            pressedS = false;
            pressedD = false;
            break;
        case 'S':
            pressedW = false;
            pressedA = false;
            pressedD = false;
            break;
        case 'D':
            pressedW = false;
            pressedA = false;
            pressedS = false;
            break;
        default:
            pressedW = false;
            pressedA = false;
            pressedS = false;
            pressedD = false;
            break;
    }
}