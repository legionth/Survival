/* 
 * File:   Game.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:44
 */

#include <SFML/Window.hpp>
#include "Player.h"
#include "World.h"
#include <iostream>
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
private:
    sf::RenderWindow *window;
    World *world;
    Player* player;
    std::map<std::string,sf::Texture*> images;

};

#endif	/* GAME_H */

