/* 
 * File:   Game.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:44
 */

#include <SFML/Window.hpp>
#include "Player.h"
#include "World.h"
#include "Ressource.h"
#include <iostream>
#include "consts.h"
#include "BuildingMenu.h"
#include "ItemMenu.h"
#include "StatusMenu.h"
#include "Enemy.h"
#include "Inventory.h"
#include "CraftingMenu.h"
#include "AlchemyMenu.h"

#ifndef GAME_H 
#define	GAME_H

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void run();
    Player* getPlayer();
    TileMap* getCurrentTileMap();
    TileMap* getTileMap(int x, int y);
    sf::Texture* loadImage(std::string);
    sf::Texture* loadImage(std::string,int position,int width,int height);
    
    BuildingButton* getSelectedBuildingButton();
    void setSelectedBuildingButton(BuildingButton* button);
    void spawnEnemy();
    void generateRessoruces();
    void generateAlchemyRessources();
    // init functions
    void initImages();          // should be called first
    void initWorld();
    void initCraftingMenus();
    void initItemMenu();
    void initStatusMenu();
    void initInventory();
private:
    sf::RenderWindow *window;
    World *world;
    Player* player;
    std::map<std::string,sf::Texture*> images;
    sf::Clock ressourceClock;
    sf::Clock ressourceAlchemyClock;
    
    BuildingMenu* buildMenu;
    AlchemyMenu* alchemyMenu;
    StatusMenu* statusMenu;
    ItemMenu* itemMenu;
    Inventory* inventory;
    BuildingButton* selectedButton;
    
    // Enemies vars
    std::vector<Enemy*> enemies;
    sf::Clock enemySpawnClock;
    
    bool pressedW;              // needed for change direction wihtout walking
    bool pressedA;
    bool pressedS;
    bool pressedD;
    
    void disableTypedKey();
    void disableTypedKey(char key);
    Menu* currentMenu;

};

#endif	/* GAME_H */

