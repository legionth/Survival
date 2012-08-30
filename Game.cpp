/* 
 * File:   Game.cpp
 * Author: niels
 * 
 * Created on 30. April 2012, 10:44
 */

#include <typeinfo>
#include "Game.h"
#include "Menu.h"
#include "BuildingButton.h"
#include "BuildingMenu.h"
#include "AlchemyRessource.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode((5*FRAME_WIDTH)+(2*FRAME_WIDTH), (5*FRAME_HEIGHT)+(2*FRAME_HEIGHT)), "Survival Game");
    
    initImages();
    initWorld();
    initCraftingMenus();
    initItemMenu();
    initStatusMenu();
    initInventory();
    
    Ressource* res = new Ressource(RES_WOOD,images["ressources"]);
    getTileMap(0,0)->getTile(0,1)->setRessource(res);
    Ressource* res2 = new Ressource(RES_WOOD,images["ressources"]);
    getTileMap(0,0)->getTile(1,1)->setRessource(res2);
    
    res2 = new Ressource(RES_IRON_ORE,images["ressources"]);
    getTileMap(0,0)->getTile(2,2)->setRessource(res2);
    
    res2 = new Ressource(RES_IRON_ORE,images["ressources"]);
    getTileMap(0,0)->getTile(3,2)->setRessource(res2);
    
    AlchemyRessource* res3 = new AlchemyRessource(RES_SNAKE_HEAD,images["alchemyRessources"]);
    getTileMap(0,0)->getTile(3,3)->setRessource(res3);
  //  this->spawnEnemy();
    enemies.push_back(new Enemy(world->getTileMap(0,0),0,0,images["enemyPig"],9,0,images["ressources"]));
    pressedW = false;
    pressedA = false;
    pressedS = false;
    pressedD = false;

}

Game::Game(const Game& orig) {
}

Game::~Game() {
    delete world;
    delete player;
    delete window;
    delete buildMenu;
    delete statusMenu;
    delete craftingMenu;
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
                else if(event.key.code == sf::Keyboard::I || event.key.code == sf::Keyboard::Tab){
                    inventory->show();
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
                    
                    if((x >= 0 && x < 5) && (y >= 0 && y < 5)){
                        Tile* tile = player->getTileMap()->getTile(x,y);
                        if(tile->getLivingObject() != 0){
                            player->attack(player->getTileMap()->getTile(x,y)->getLivingObject());
                        }
                        else if(tile->isDestroyAble()){
                            player->attack(tile);
                            if(tile->getLife() <= 0){
                                tile->setRessourceTexture(images["ressources"]);
                                tile->setIdentifier(TILE_GRASS);
                                tile->drop(tile);
                            }
                        }
                    }
                    
                }
                
                // Pickup
                if(event.key.code == sf::Keyboard::Space){
                    if(player->getTileMap()->getTile(player->getXPos(),player->getYPos())->getRessource() != 0){
                        Tile* tile = player->getTileMap()->getTile(player->getXPos(),player->getYPos());
                        int id = tile->getRessource()->getIdentifier();
                        
            //            if(tile->getRessource()->isStatusRessource()){
             //                   player->pickup(tile);
              //                  itemMenu->getButtonById(id)->updateCount(player->getRessourceCountById(id));
               //                 itemMenu->getButtonById(id)->setVisible(true);
                 //       }else{
                            //player->pickup(tile);
                        if(inventory->countItems() < inventory->getMaxItems()){
                                player->pickup(tile,false);
                                inventory->addRessource(tile->getRessource());
                                tile->setRessource(0,false);
                        }
                   //     }
                    }
                }
                
                
                // Toggle throug button Menu
                if(event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left){
                    int pressDirection = 0;
                    
                    if(event.key.code == sf::Keyboard::Right){
                        pressDirection = 1;
                    }else{
                        pressDirection = -1;
                    }
                    
                    if(currentMenu == buildMenu){
                        BuildingButton* selectedButton = 0;
                        int number = 0;
                        int count = buildMenu->getButtons().size();

                        for(int i = 0; i < count; i++){
                            if(buildMenu->getButton(i)->isPressed()){
                                selectedButton = buildMenu->getButton(i);
                                number = i;
                            }
                        }

                        if(number + pressDirection < count && number + pressDirection >= 0){
                            selectedButton->press();
                            buildMenu->getButton(number + pressDirection)->press();
                        }
                    }
                    else if(currentMenu == alchemyMenu){
                        AlchemyButton* selectedButton = 0;
                        int number = 0;
                        int count = alchemyMenu->getButtons().size();

                        for(int i = 0; i < count; i++){
                            if(alchemyMenu->getButton(i)->isPressed()){
                                selectedButton = alchemyMenu->getButton(i);
                                number = i;
                            }
                        }

                        if(number + pressDirection < count && number + pressDirection >= 0){
                            selectedButton->press();
                            alchemyMenu->getButton(number + pressDirection)->press();
                        }
                    }
                    else if(currentMenu == craftingMenu){
                        CraftingButton* selectedButton = 0;
                        int number = 0;
                        int count = craftingMenu->getButtons().size();

                        for(int i = 0; i < count; i++){
                            if(craftingMenu->getButton(i)->isPressed()){
                                selectedButton = craftingMenu->getButton(i);
                                number = i;
                            }
                        }

                        if(number + pressDirection < count && number + pressDirection >= 0){
                            selectedButton->press();
                            craftingMenu->getButton(number + pressDirection)->press();
                        }
                    }
                 }
                
              
                
                // Build a Building :P
                else if(event.key.code == sf::Keyboard::Return){
                    if(currentMenu == buildMenu){
                        for(int i = 0; i < buildMenu->getButtons().size(); i++){
                            if(buildMenu->getButton(i)->isPressed()){
                                Building *building = buildMenu->getButton(i)->getBuilding();
                                int currentDirection = player->getCurrentDirection();

                                int posX = player->getXPos();
                                int posY = player->getYPos();
                                TileMap* map = player->getTileMap();


                              //  std::map<int,int> ressourcesPlayer = player->getRessources();
                                std::map<int,int> ressourcesBuilding = building->getRessources();
                            //    int size = ressourcesPlayer.size();

                                bool canBuild = inventory->checkRessourcesBuilding(ressourcesBuilding);

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
                                    
                                    inventory->decreaseBuildingRessources(ressourcesBuilding);
                                }
                            }
                        }
                    }
                    else if (currentMenu == alchemyMenu){
                        for(int i = 0; i < alchemyMenu->getButtons().size(); i++){
                            if(alchemyMenu->getButton(i)->isPressed()){
                                Potion* potion = alchemyMenu->getButton(i)->getPotion();
                                potion->setImage(images["potions"]);
                                std::map<int,int> ressourcesPotion = potion->getRessources();
                                bool canProduce = inventory->checkRessourcesAlchemy(ressourcesPotion);
                                 //std::cout<<"canProduce"<<canProduce<<std::endl;
                                if(canProduce){
                                    inventory->decreaseAlchemyRessources(ressourcesPotion);
                                    inventory->addRessource(potion);
//                                    bool b = inventory->getButton(0)->(Potion)getRessource()->use(player);
                                }
                            }
                        }
                    }
                    else if (currentMenu == craftingMenu){
                        for(int i = 0; i < craftingMenu->getButtons().size(); i++){
                            if(craftingMenu->getButton(i)->isPressed()){
                                Ressource* res = craftingMenu->getButton(i)->getRessource();
                                
                                std::map<int,int> needRessources = res->getRessources();
                                bool canProduce = inventory->checkRessourcesCrafting(needRessources);
                                
                                if(canProduce){
                                    inventory->decreaseCraftingRessources(needRessources);
                                    inventory->addRessource(res);
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
            else if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if(inventory->isShown()){
                        for(int i = 0; i < inventory->getInventoryButtons().size(); i++){
                            Button* button = inventory->getInventoryButtons()[i];
                            int xMouse = event.mouseButton.x;
                            int yMouse = event.mouseButton.y;
                            int xSprite = button->getSprite()->getPosition().x;
                            int ySprite = button->getSprite()->getPosition().y;
                                                      
                            if(xSprite <= xMouse && 
                               xSprite + button->getFrameWidth() >= xMouse &&
                               ySprite <= yMouse && 
                               ySprite + button->getFrameHeight() >= yMouse
                               ){
                                
                                button->press();
                                
                                if(button->getId() == INVENTORY_BUILD){
                                    currentMenu = buildMenu;
                                }
                                else if(button->getId() == INVENTORY_ALCHEMY){
                                    currentMenu = alchemyMenu;
                                }
                                else if(button->getId() == INVENTORY_CRAFT){
                                    currentMenu = craftingMenu;
                                }
                                // Unselect other buttons
                                for(int j = 0; j < inventory->getInventoryButtons().size(); j++){
                                    if(inventory->getInventoryButton(j)->isPressed() && button != inventory->getInventoryButton(j)){
                                        inventory->getInventoryButton(j)->press();
                                    }
                                }
                            }
                        }
                                                // Ressources
                        //std::cout<<"through buttons"<<std::endl;
                         for(int i = 0; i < inventory->getButtons().size(); i++){
                            Button* button = inventory->getButtons()[i];
                            int xMouse = event.mouseButton.x;
                            int yMouse = event.mouseButton.y;
                            int xSprite = button->getSprite()->getPosition().x;
                            int ySprite = button->getSprite()->getPosition().y;
                             
                            if(xSprite <= xMouse && 
                               xSprite + button->getFrameWidth() >= xMouse &&
                               ySprite <= yMouse && 
                               ySprite + button->getFrameHeight() >= yMouse
                               ){
                                Ressource* res = button->getRessource();
                                
                                if(res != 0){
                                    bool used = false;
                                    std::cout<<"RES CLICK"<<res->getIdentifier()<<std::endl;
                                    if(res->isPotion()){
                                        Potion* ressource = reinterpret_cast<Potion*>(res);
                                        used = ressource->use(this->player);
                                    }
                                    else if(res->isWeapon()){
                                        std::cout<<"is weapon"<<std::endl;
                                        WeaponTool* weapon = reinterpret_cast<WeaponTool*>(res);
                                        WeaponTool* oldWeapon = player->getWeapon();
                                        
                                        
                                        if(oldWeapon != 0){
                                            inventory->addRessource(oldWeapon);
                                        }
                                        
                                        used = weapon->use(player);
                                        statusMenu->getWeaponSlot()->setTool(weapon);
                                    }
                                    else{
                                        Ressource* ressource = res;
                                        used = ressource->use(this->player);
                                    }
                                    
                                    if(used){
                                        inventory->removeRessource(button,false);
                                    }
                                }
                            }
                         }
                    }
                }   
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
        generateAlchemyRessources();
        spawnEnemy();
        
        if(player->haveToAttack()){
            player->stopAttackAnimation();
        }
        
        
        // Draw the things
        
        if(!inventory->isShown()){
            // Draw normal stuff here
            window->clear();

            for(int y = 0; y < getCurrentTileMap()->getYSize(); y++){
                for(int x = 0; x < getCurrentTileMap()->getXSize(); x++){
                    Tile* tile = getCurrentTileMap()->getTile(x,y);
                    sf::Sprite *sprite = tile->getSprite();
                    window->draw(*sprite);
                    
                    if(tile->getTime() >= DESPAWN_TIMER && tile->getRessource() != 0){
                        tile->removeRessource();
                    }
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
               //  std::cout<<"enemy"<<i<<"life="<<enemies[i]->getLife()<<std::endl;
                if(enemies[i]->getLife() <= 0){
                    enemies[i]->getTileMap()->getTile(enemies[i]->getXPos(),enemies[i]->getYPos())->setLivingObject(0);
                    enemies[i]->drop(enemies[i]->getTile());
                    enemies.erase(enemies.begin()+i);
                }
            }

            for(int i = 0; i < enemies.size();i++){
                enemies[i]->execute(world);
            }
            player->updateAnimation();

            window->draw(*player->getSprite());
            // Enemie drawing
            for(int i = 0; i < enemies.size();i++){
               // std::cout<<"life enemy"<<enemies[i]->getLife()<<std::endl;
                if(enemies[i]->getTileMap() == this->getCurrentTileMap()){
                        enemies[i]->updateAnimation();
                        window->draw(*enemies[i]->getSprite());
                }
            }
        }else{
            // Draw inventory
            window->draw(*inventory->getSprite());
            
            for(int i = 0; i < inventory->getInventoryButtons().size(); i++){
                window->draw(*inventory->getInventoryButton(i)->getSprite());
                
            }
            for(int i = 0; i < inventory->getButtons().size(); i++){
                window->draw(*inventory->getButton(i)->getSprite());
                
                if(inventory->getButton(i)->getRessource() != 0){
                    window->draw(*inventory->getButton(i)->getRessource()->getSprite());
                } 
            }
        }
        
        window->draw(*itemMenu->getSprite());
        window->draw(*statusMenu->getSprite());
        
        statusMenu->drawLifeButton(window,player->getLife());
        statusMenu->drawHungerButton(window,player->getHunger());
        statusMenu->drawHeatButton(window,player->getHeat());
        
        window->draw(*statusMenu->getWeaponSlot()->getSprite());
        
        window->draw(*statusMenu->getToolSlot()->getSprite());
        //Drawing the slots
        if(statusMenu->getWeaponSlot()->getTool() != 0){    
            window->draw(* statusMenu->getWeaponSlot()->getTool()->getSprite());
        }
        
        if(statusMenu->getToolSlot()->getTool() != 0){
            window->draw(*statusMenu->getToolSlot()->getTool()->getSprite());
        }
        // Menu drawing
        for(int i = 0; i < inventory->getInventoryButtons().size(); i++){
          //  std::cout<<"id="<<inventory->getInventoryButton(i)->getId()<<std::endl;    
            if(inventory->getInventoryButton(i)->getId() == INVENTORY_BUILD && inventory->getInventoryButton(i)->isPressed()){
                window->draw(*buildMenu->getSprite());
                
                for(int i = 0 ; i < buildMenu->getButtons().size(); i++){
                    window->draw(*buildMenu->getButton(i)->getSprite());
                }
            }
            
            if(inventory->getInventoryButton(i)->getId() == INVENTORY_ALCHEMY && inventory->getInventoryButton(i)->isPressed()){
                window->draw(*alchemyMenu->getSprite());
                
                for(int i = 0 ; i < alchemyMenu->getButtons().size(); i++){
                        window->draw(*alchemyMenu->getButton(i)->getSprite());
                }
            }
            
            if(inventory->getInventoryButton(i)->getId() == INVENTORY_CRAFT && inventory->getInventoryButton(i)->isPressed()){
                window->draw(*craftingMenu->getSprite());
                
                for(int i = 0 ; i < craftingMenu->getButtons().size(); i++){
                        window->draw(*craftingMenu->getButton(i)->getSprite());
                }
            }
        }
        
        for(int i = 0 ; i < itemMenu->getButtons().size(); i++){
            if(itemMenu->getButton(i)->isVisible()){
                window->draw(*itemMenu->getButton(i)->getSprite());
                window->draw(*itemMenu->getButton(i)->getText());
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
    if(ressourceClock.getElapsedTime().asSeconds() > 10){
        int randomXTileMap = rand() % 5;
        int randomYTileMap = rand() % 5;
        int randomXTile = rand() % 5;
        int randomYTile = rand() % 5;
        
        Tile* tile = world->getTileMap(randomXTileMap,randomYTileMap)->getTile(randomXTile,randomYTile);
        
        if(tile->isWalkAble() && tile->getRessource() == 0){
            int res = rand() % 2;
            Ressource* ressource = new Ressource(res,images["ressources"]);
            
            tile->setRessource(ressource);
            ressourceClock.restart();
          //  std::cout<<"generate Rssource map x="<<randomXTileMap<<"map y"<<randomYTileMap<<" x="<<randomXTile<<"y="<<randomYTile<<std::endl;
        }
    }
}

void Game::generateAlchemyRessources(){
    if(ressourceAlchemyClock.getElapsedTime().asSeconds() > 10){
        int randomXTileMap = rand() % 5;
        int randomYTileMap = rand() % 5;
        int randomXTile = rand() % 5;
        int randomYTile = rand() % 5;
        
        Tile* tile = world->getTileMap(randomXTileMap,randomYTileMap)->getTile(randomXTile,randomYTile);
        
        if(tile->isWalkAble() && tile->getRessource() == 0){
            int res = (rand() % 4) + 50;
            AlchemyRessource* ressource = new AlchemyRessource(res,images["alchemyRessources"]);
            
            tile->setRessource(ressource);
            ressourceAlchemyClock.restart();
           // std::cout<<"generate ACLHEMYRssource id"<<res<<" mapx="<<randomXTileMap<<"map y"<<randomYTileMap<<" x="<<randomXTile<<"y="<<randomYTile<<std::endl;
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
    if(enemySpawnClock.getElapsedTime().asSeconds() > 15.0f){
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
            if(getTileMap(randomXTileMap,randomXTile)->getTile(randomXTile,randomYTile)->isWalkAble()){
                enemies.push_back(new Enemy(world->getTileMap(randomXTileMap,randomYTileMap),randomXTile,randomYTile,tex,9,0,images["ressources"]));
            }
            
            enemySpawnClock.restart();
            //  std::cout<<"new enemy at tielmap"<<randomXTileMap<<":"<<randomYTileMap<<"tile="<<randomXTile<<":"<<randomYTile<<std::endl;
        }
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

void Game::initImages(){
    images["player"]            = this->loadImage("player.png");
    images["land"]              = this->loadImage("land.png");
    images["ressources"]        = this->loadImage("ressources.png");
    images["menuBuilding"]      = this->loadImage("menu_building.png");
    images["menuItem"]          = this->loadImage("menu_item.png");
    images["menuStatus"]        = this->loadImage("menu_status.png");
    images["buttonBuilding"]    = this->loadImage("button_building.png");
    images["buttonItem"]        = this->loadImage("button_item.png");
    images["buttonInventory"]   = this->loadImage("button_inventory.png");
    images["buildings"]         = this->loadImage("buildings.png");
    images["enemyPig"]          = this->loadImage("enemy_pig.png");
    images["buttonStatus"]      = this->loadImage("button_status.png");
    images["inventory"]         = this->loadImage("inventory.png");
    images["slot"]              = this->loadImage("slot.png");
    images["alchemyRessources"] = this->loadImage("alchemy_ressources.png");
    images["menuAlchemy"]       = this->loadImage("menu_alchemy.png");
    images["buttonAlchemy"]     = this->loadImage("button_alchemy.png");
    images["buttonCrafting"]    = this->loadImage("button_crafting.png");
    images["potions"]           = this->loadImage("potion.png");
    images["weapons"]           = this->loadImage("weapons.png");
}

void Game::initWorld(){
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
}

void Game::initCraftingMenus(){
    buildMenu = new BuildingMenu(FRAME_WIDTH * 5,0,128,512);
    buildMenu->setImage(images["menuBuilding"]);
    
    BuildingButton *button = new BuildingButton(BUTTON_BUILDING_RECT_TENT,images["buttonBuilding"],BUILDING_RECT_TENT,images["buildings"],"tent",BUILDING_TENT);
    buildMenu->addButton(button);
    button->press();
    
    button = new BuildingButton(BUTTON_BUILDING_RECT_FIREPLACE,images["buttonBuilding"],BUILDING_RECT_FIREPLACE,images["buildings"],"fireplace",BUILDING_FIREPLACE);
    buildMenu->addButton(button);
    
    button = new BuildingButton(BUTTON_BUILDING_RECT_ANVIL,images["buttonBuilding"],BUILDING_RECT_ANVIL,images["buildings"],"smith",BUILDING_ANVIL);
    buildMenu->addButton(button);
    
    button = new BuildingButton(BUTTON_BUILDING_RECT_SMITH,images["buttonBuilding"],BUILDING_RECT_SMITH,images["buildings"],"fireplace",BUILDING_SMITH);
    buildMenu->addButton(button);
    
    alchemyMenu = new AlchemyMenu(FRAME_WIDTH * 5,0,128,512);
    alchemyMenu->setImage(images["menuAlchemy"]);
    
    AlchemyButton *alcButton = new AlchemyButton(BUTTON_ALCHEMY_RECT_HEAL_POTION,images["buttonAlchemy"],POTION_HEAL);
    alchemyMenu->addButton(alcButton);
    alcButton->press();
    
    alcButton = new AlchemyButton(BUTTON_ALCHEMY_RECT_POISON_POTION,images["buttonAlchemy"],POTION_POISON);
    alchemyMenu->addButton(alcButton);
    
    craftingMenu = new CraftingMenu(FRAME_WIDTH * 5,0,128,512);
    craftingMenu->setImage(images["menuAlchemy"]);
    
    CraftingButton* craftButton = new CraftingButton(BUTTON_CRAFTING_RECT_IRON_BAR,images["buttonCrafting"],RES_IRON_BAR,images["ressources"]);
    craftingMenu->addButton(craftButton);
    craftButton->press();
    
    craftButton = new CraftingButton(BUTTON_CRAFTING_RECT_SILVER_BAR,images["buttonCrafting"],RES_SILVER_BAR,images["ressources"]);
    craftingMenu->addButton(craftButton);
    
    craftButton = new CraftingButton(BUTTON_CRAFTING_RECT_GOLD_BAR,images["buttonCrafting"],RES_GOLD_BAR,images["ressources"]);
    craftingMenu->addButton(craftButton);
    
    craftButton = new CraftingButton(BUTTON_CRAFTING_RECT_WOOD_SPEAR,images["buttonCrafting"]);
    craftButton->setRessource(new WeaponTool(images["weapons"],WEAPON_SPEAR_WOOD));
    craftingMenu->addButton(craftButton);
    
    craftButton = new CraftingButton(BUTTON_CRAFTING_RECT_IRON_SWORD,images["buttonCrafting"]);
    craftButton->setRessource(new WeaponTool(images["weapons"],WEAPON_SWORD_IRON));
    craftingMenu->addButton(craftButton);
    
    craftButton = new CraftingButton(BUTTON_CRAFTING_RECT_SILVER_SWORD,images["buttonCrafting"]);
    craftButton->setRessource(new WeaponTool(images["weapons"],WEAPON_SWORD_SILVER));
    craftingMenu->addButton(craftButton);
    
    craftButton = new CraftingButton(BUTTON_CRAFTING_RECT_GOLD_SWORD,images["buttonCrafting"]);
    craftButton->setRessource(new WeaponTool(images["weapons"],WEAPON_SWORD_GOLD));
    craftingMenu->addButton(craftButton);
    
    currentMenu = buildMenu;
}

void Game::initItemMenu(){
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
    
    itemButton = new ItemButton(6,images["buttonItem"],RES_COLE);
    itemMenu->addButton(itemButton);
    
    itemButton = new ItemButton(7,images["buttonItem"],RES_GOLD_BAR);
    itemMenu->addButton(itemButton);
    
    itemButton = new ItemButton(8,images["buttonItem"],RES_SILVER_BAR);
    itemMenu->addButton(itemButton);
    
    itemButton = new ItemButton(9,images["buttonItem"],RES_IRON_BAR);
    itemMenu->addButton(itemButton);
}

void Game::initStatusMenu(){
    statusMenu = new StatusMenu(0,FRAME_HEIGHT * 5,640,256);
    statusMenu->setImage(images["menuStatus"]);
    
        // Life init
    StatusButton* statusButton = new StatusButton(STATUS_BUTTON_LIFE);
    statusButton->setImage(images["buttonStatus"]);      
    statusButton->setFrameRect(0);
    statusMenu->setLifeButton(statusButton);
    
    statusButton = new StatusButton(STATUS_BUTTON_HUNGER);
    statusButton->setImage(images["buttonStatus"]);
    statusButton->setFrameRect(1);
    statusMenu->setHungerButton(statusButton);
    
    statusButton = new StatusButton(STATUS_BUTTON_HEAT);
    statusButton->setImage(images["buttonStatus"]);
    statusButton->setFrameRect(3);
    statusMenu->setHeatButton(statusButton);
    
    SlotButton* slotButton = new SlotButton(0,images["slot"]);
    statusMenu->setWeaponSlot(slotButton);
    
    slotButton = new SlotButton(0,images["slot"]);
    statusMenu->setToolSlot(slotButton);
}

void Game::initInventory(){
    inventory = new Inventory();
    inventory->setImage(images["inventory"]);
    
    InventoryButton* invButton = new InventoryButton(INVENTORY_ALCHEMY,RECT_INVENTORY_ALCHEMY,images["buttonInventory"]);
    inventory->addInventoryButton(invButton);
    
    invButton = new InventoryButton(INVENTORY_CRAFT,RECT_INVENTORY_CRAFT,images["buttonInventory"]);
    inventory->addInventoryButton(invButton);
    
    invButton = new InventoryButton(INVENTORY_COOK,RECT_INVENTORY_COOK,images["buttonInventory"]);
    inventory->addInventoryButton(invButton);
    
    invButton = new InventoryButton(INVENTORY_BUILD,RECT_INVENTORY_BUILD,images["buttonInventory"]);
    inventory->addInventoryButton(invButton);
    invButton->press();
    
    // Empty Buttons
    for(int i = 0; i < inventory->getMaxItems(); i++){
        Button* button = new Button(RECT_INVENTORY_EMPTY,images["buttonInventory"],INVENTORY_EMPTY);
        inventory->addButton(button);
    }
}