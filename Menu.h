/* 
 * File:   Menu.h
 * Author: niels
 *
 * Created on 21. Juni 2012, 07:54
 */

#ifndef MENU_H
#define	MENU_H
#include "GameObject.h"
#include "Button.h"

class Menu : public GameObject{
public:
    Menu(int posX,int posY,int sizeX,int sizeY);
    Menu(const Menu& orig);
    virtual ~Menu();
    void addButton(Button* button);
    Button* getButton(int i);
    std::vector<Button*> getButtons();
private:
   std::vector<Button*> buttons;
   int sizeX;
   int sizeY;
};

#endif	/* MENU_H */

