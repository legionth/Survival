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
<<<<<<< HEAD
#include "BuildingButton.h"
=======
>>>>>>> abfa2e8395288c787bdd2735fa5c3bc8a6fdf270

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
    
<<<<<<< HEAD
    BuildingButton* getSelectedBuildingButton();
    void setSelectedBuildingButton(BuildingButton* button);
    
=======
>>>>>>> abfa2e8395288c787bdd2735fa5c3bc8a6fdf270
private:
    sf::RenderWindow *window;
    World *world;
    Player* player;
    std::map<std::string,sf::Texture*> images;
    sf::Clock ressourceClock;
    BuildingMenu* buildMenu;
    Menu* statusMenu;
<<<<<<< HEAD
    Menu* itemMenu;
    
    BuildingButton* selectedButton;
=======
>>>>>>> abfa2e8395288c787bdd2735fa5c3bc8a6fdf270
};

#endif	/* GAME_H */

