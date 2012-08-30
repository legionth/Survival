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

enum WEAPONS{
    WEAPON_SPEAR_WOOD    = 10,
    WEAPON_SWORD_IRON    = 11,
    WEAPON_SWORD_SILVER  = 12,
    WEAPON_SWORD_GOLD    = 13
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
enum BUILDINGS{
        BUILDING_TENT           = '^',
        BUILDING_FIREPLACE	= 'f',
        BUILDING_ANVIL          = 'z',
        BUILDING_SMITH          = 's'
};

const int BUILDING_RECT_TENT            = 0;
const int BUILDING_RECT_FIREPLACE       = 1;
const int BUILDING_RECT_FIREPLACE_END   = 3;
const int BUILDING_RECT_ANVIL           = 4;
const int BUILDING_RECT_HUT             = 5;
const int BUILDING_RECT_SMITH           = 6;
const int BUILDING_RECT_SMITH_END       = 8;
// Button rects
const int BUTTON_BUILDING_RECT_TENT        = 0;
const int BUTTON_BUILDING_RECT_FIREPLACE   = 2;
const int BUTTON_BUILDING_RECT_ANVIL       = 4;
const int BUTTON_BUILDING_RECT_HUT         = 8;
const int BUTTON_BUILDING_RECT_SMITH         = 6;
// Alchemy button rect
const int BUTTON_ALCHEMY_RECT_HEAL_POTION        = 0;
const int BUTTON_ALCHEMY_RECT_POISON_POTION      = 2;

enum CRAFTING_RECTS{
        BUTTON_CRAFTING_RECT_GOLD_BAR         = 0,
        BUTTON_CRAFTING_RECT_SILVER_BAR       = 2,
        BUTTON_CRAFTING_RECT_IRON_BAR         = 4,
        BUTTON_CRAFTING_RECT_WOOD_SPEAR       = 6,
        BUTTON_CRAFTING_RECT_IRON_SWORD       = 8,
        BUTTON_CRAFTING_RECT_SILVER_SWORD     = 10,
        BUTTON_CRAFTING_RECT_GOLD_SWORD       = 12
};
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

//Despawn timer
const float DESPAWN_TIMER = 100.0f;

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
    RECT_INVENTORY_EMPTY         = 0,
    RECT_INVENTORY_ALCHEMY       = 2,
    RECT_INVENTORY_CRAFT         = 4,
    RECT_INVENTORY_COOK          = 6,
    RECT_INVENTORY_BUILD         = 8
};


// id of inveotr buttons
enum IVENTORY_BUTTONS{
    INVENTORY_EMPTY        = 0,
    INVENTORY_ALCHEMY      = 1,
    INVENTORY_CRAFT        = 2,
    INVENTORY_COOK         = 3,
    INVENTORY_BUILD        = 4

};

enum ALCHEMY_RESSOURCES{
    RES_SNAKE_HEAD = 50,
    RES_EVER_GREEN = 51,
    RES_BLADE_LEAF = 52,
    RES_WASP_DEATH = 53
};

enum POTIONS{
    POTION_HEAL         = 0,
    POTION_POISON       = 1
};

#endif	/* CONSTS_H */

