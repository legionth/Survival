/* 
 * File:   main.cpp
 * Author: niels
 *
 * Created on 30. März 2012, 13:54
 */

#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "Game.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Game game;
    game.run();
    
    return EXIT_SUCCESS;
}

