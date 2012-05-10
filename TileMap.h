/* 
 * File:   TileMap.h
 * Author: niels
 *
 * Created on 30. April 2012, 10:57
 */

#ifndef TILEMAP_H
#define	TILEMAP_H

class TileMap {
public:
    TileMap();
    TileMap(const TileMap& orig);
    
    void loadTileMap(std::string fileName);
    int getXPos();
    int getYPos();
    
    void setXPos(int x);
    void setYPos(int y);
    void setIdentifierOnTile(int x, int y, char c);
    virtual ~TileMap();
private:
    std::vector<std::vector<Tile> > tileMap;
    int xPos;
    int yPos;
};

#endif	/* TILEMAP_H */

