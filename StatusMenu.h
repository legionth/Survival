/* 
 * File:   StatusMenu.h
 * Author: legionth
 *
 * Created on 19. Juli 2012, 23:03
 */

#ifndef STATUSMENU_H
#define	STATUSMENU_H

#include "Menu.h"
#include "StatusButton.h"

class StatusMenu : public Menu{
public:
    StatusMenu(int posX, int posY,int sizeX,int sizeY);
    virtual ~StatusMenu();
    void setLifeButton(StatusButton* lifeButton);
    void drawLifeButton(sf::RenderWindow *window, int life);
    void drawCoinButton(sf::RenderWindow *window, int coin);
    void drawHungerButton(sf::RenderWindow *window, int hunger);
    void drawHeatButton(sf::RenderWindow *window, int heat);
private:
    sf::Text coinText;
    StatusButton* coinButton;
    StatusButton* heatButton;
    StatusButton* hungerButton;
    StatusButton* lifeButton;
};

#endif	/* STATUSMENU_H */

