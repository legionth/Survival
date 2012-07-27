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
const int STATUS_BUTTON_WIDTH = 16;
const int STATUS_BUTTON_HEIGHT = 16;



enum Ressources{ 
    RES_WOOD             = 0, 
    RES_STONE            = 1,
    RES_LEATHER          = 2,
    RES_IRON_ORE         = 3,
    RES_GOLD_ORE         = 4,
    RES_SILVER_ORE       = 5,
    RES_COLE             = 6,
    RES_IRON_BAR         = 7,
    RES_SILVER_BAR       = 8,
    RES_GOLD_BAR         = 9
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

enum StatusButtons{ 
    STATUS_BUTTON_LIFE                  = 0,
    STATUS_BUTTON_HEAT                  = 1,
    STATUS_BUTTON_COIN                  = 2,
    STATUS_BUTTON_HUNGER                = 3,
};

const int RECT_SLOT_EMPTY                 = 0;
//id's for the buildings
const char BUILDING_TENT        = '^';
const char BUILDING_FIREPLACE	= 'f';


const int BUILDING_RECT_TENT            = 0;
const int BUILDING_RECT_FIREPLACE       = 1;
const int BUILDING_RECT_FIREPLACE_END   = 3;
const int BUILDING_RECT_ANVIL           = 4;
const int BUILDING_RECT_HUT             = 5;
// Button rects
const int BUTTON_BUILDING_RECT_TENT        = 0;
const int BUTTON_BUILDING_RECT_FIREPLACE   = 2;
const int BUTTON_BUILDING_RECT_ANVIL       = 4;
const int BUTTON_BUILDING_RECT_HUT         = 5;

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
const int RECT_RIGHT_START = 8;
const int RECT_LEFT_START = 12;

enum RECT_ATTACK{
         RECT_ATTACK_UP_START          = 20,
         RECT_ATTACK_UP_END            = 23,
         RECT_ATTACK_DOWN_START        = 16,
         RECT_ATTACK_DOWN_END          = 19,
         RECT_ATTACK_RIGHT_START       = 24,
         RECT_ATTACK_RIGHT_END         = 27,
         RECT_ATTACK_LEFT_START        = 28,
         RECT_ATTACK_LEFT_END          = 31,
};

enum RECT_INVENTORY{
    RECT_INVENTORY_EMPTY        = 0,
    RECT_INVENTORY_ALCHEMY      = 1,
    RECT_INVENTORY_CRAFT        = 2,
    RECT_INVENTORY_COOK         = 3
};

// id of inveotr buttons
enum IVENTORY_BUTTONS{
    INVENTORY_EMPTY        = 0,
    INVENTORY_ALCHEMY      = 1,
    INVENTORY_CRAFT        = 2,
    INVENTORY_COOK         = 3
};
#endif	/* CONSTS_H */

