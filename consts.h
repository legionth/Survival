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

const char BUILDING_TENT		= '^';
const char BUILDING_FIREPLACE	= 'f';

const char TILE_GRASS			= ',';
const char TILE_EARTH			= '.';
const char TILE_TREE			= 'T';
const char TILE_GRASS_EARTH		= ';';
const char TILE_EARTH_LEFT		= '3';
const char TILE_EARTH_RIGHT		= '1';
const char TILE_EARTH_TOP		= '2';
const char TILE_EARTH_DOWN		= '0';
#endif	/* CONSTS_H */

