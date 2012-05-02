/* 
 * File:   Game.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:44
 */

#include <SFML/Window.hpp>
#include "Player.h"
#include "World.h"
#ifndef GAME_H
#define	GAME_H

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    void run();
    void generateRessoruces();
    void changeTileMap(int map);
    void getTileMap(int x, int y);
    
    Player* getPlayer();
    TileMap* getCurrentTileMap();
    sf::Texture* Game::loadImage(std::string);
    sf::Texture* Game::loadImage(std::string,int position,int width,int height);
private:
    sf::RenderWindow *window;
    World *world;
    Player* player;
    std::map<std::string,sf::Texture*> images;

};

#endif	/* GAME_H */

