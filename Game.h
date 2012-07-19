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
//#include <thread>
#include "Menu.h"
#include "BuildingMenu.h"
//#include "BuildingButton.h"
#include "ItemMenu.h"
//#include "ItemButton.h"
#include "StatusMenu.h"s
#include "Enemy.h"

#ifndef GAME_H
#define	GAME_H

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void run();
    void generateRessoruces();
    Player* getPlayer();
    TileMap* getCurrentTileMap();
    TileMap* getTileMap(int x, int y);
    sf::Texture* loadImage(std::string);
    sf::Texture* loadImage(std::string,int position,int width,int height);
    
    BuildingButton* getSelectedBuildingButton();
    void setSelectedBuildingButton(BuildingButton* button);
    void spawnEnemy();
    
private:
    sf::RenderWindow *window;
    World *world;
    Player* player;
    std::map<std::string,sf::Texture*> images;
    sf::Clock ressourceClock;
    BuildingMenu* buildMenu;
    StatusMenu* statusMenu;
    ItemMenu* itemMenu;
    
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

};

#endif	/* GAME_H */

