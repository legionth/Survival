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
    void addButton(StatusButton* button);
    StatusButton* getButton(int i);
    std::vector<StatusButton*> getButtons();
    int countButton(int id);    // Counts Button of this kind
    void removeById(int id);
private:
    std::vector<StatusButton*> buttons;
    sf::Text coinText;
};

#endif	/* STATUSMENU_H */

