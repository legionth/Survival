/* 
 * File:   main.cpp
 * Author: niels
 *
 * Created on 30. März 2012, 13:54
 */

#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Game.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Game game;
    game.run();
    return 0;
}

