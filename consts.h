/* 
 * File:   consts.h
 * Author: niels
 *
 * Created on 22. Mai 2012, 14:00
 */

#ifndef CONSTS_H
#define	CONSTS_H

enum Moves{
      MOVE_UP = 0,
      MOVE_RIGHT = 1,
      MOVE_DOWN = 2,
      MOVE_LEFT = 3
};

const int FRAME_WIDTH = 128;
const int FRAME_HEIGHT = 128;
const int BUTTON_WIDTH = 64;
const int BUTTON_HEIGHT = 64;

enum Ressources{ 
    RES_WOOD             = 0, 
    RES_STONE            = 1,
    RES_LEATHER          = 2,
    RES_IRON_ORE         = 3,
    RES_GOLD_ORE         = 4,
    RES_SILVER_ORE       = 5
};

enum Behavior{ 
    BEHAV_AGGRESSIVE      = 0, 
    BEHAV_DEFENSIVE       = 1,
    BEHAV_PASSIVE         = 2
};
// Enemie id
enum Enemies{ 
    ENEMY_PIG             = 0, 
    ENEMY_WOLF            = 1
};
//id's for the buildings
const char BUILDING_TENT        = '^';
const char BUILDING_FIREPLACE	= 'f';


const int BUILDING_RECT_TENT            = 0;
const int BUILDING_RECT_FIREPLACE       = 1;
const int BUILDING_RECT_FIREPLACE_END   = 3;

// Button rects
const int BUTTON_BUILDING_RECT_TENT        = 0;
const int BUTTON_BUILDING_RECT_FIREPLACE   = 2;

//id's for the tiles
const char TILE_GRASS			= ',';
const char TILE_EARTH			= '.';
const char TILE_TREE			= 'T';
const char TILE_GRASS_EARTH		= ';';
const char TILE_EARTH_LEFT		= '3';
const char TILE_EARTH_RIGHT		= '1';
const char TILE_EARTH_TOP		= '2';
const char TILE_EARTH_DOWN		= '0';

const int WALK_ITERATOR = 32;

const int MAX_ENEMIES = 5;
const int CLOCK_ENEMY_SPAWN = 10;

const int RECT_UP_START = 4;
const int RECT_DOWN_START = 0;
const int RECT_RIGHT_START = 9;
const int RECT_LEFT_START = 13;


#endif	/* CONSTS_H */

