/* 
 * File:   ItemButton.h
 * Author: legionth
 *
 * Created on 4. Juli 2012, 21:54
 */

#ifndef ITEMBUTTON_H
#define	ITEMBUTTON_H
#include "Button.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


class ItemButton : public Button{
    
public:
    ItemButton();
    ItemButton(int frameRect,sf::Texture* tex,int id);
    ItemButton(const ItemButton& orig);
    sf::Text* getText();
    void setCount(int i);
    void updateCount(int i);
    int getId();
    virtual ~ItemButton();
private:
    int count;          // counter of Ressources
    int id;
    sf::Text* text;

};

#endif	/* ITEMBUTTON_H */

