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
#include "SlotButton.h"

class StatusMenu : public Menu{
public:
    StatusMenu(int posX, int posY,int sizeX,int sizeY);
    virtual ~StatusMenu();
    void setLifeButton(StatusButton* lifeButton);
    void setHeatButton(StatusButton* button);
    void setHungerButton(StatusButton* button);
    void setCoinButton(StatusButton* button);
    
    void setWeaponSlot(SlotButton* slot);
    void setToolSlot(SlotButton* slot);
    
    void drawLifeButton(sf::RenderWindow *window, int life);
    void drawCoinButton(sf::RenderWindow *window, int coin);
    void drawHungerButton(sf::RenderWindow *window, int hunger);
    void drawHeatButton(sf::RenderWindow *window, int heat);
   
    SlotButton* getWeaponSlot();
    SlotButton* getToolSlot();

    
private:
    sf::Text coinText;
    
    StatusButton* coinButton;
    StatusButton* heatButton;
    StatusButton* hungerButton;
    StatusButton* lifeButton;
    
   std::vector<StatusButton*> buttons;
   
   SlotButton* weaponSlot;
   SlotButton* toolSlot;
   
};

#endif	/* STATUSMENU_H */

