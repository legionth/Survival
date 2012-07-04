/* 
 * File:   ItemButton.h
 * Author: legionth
 *
 * Created on 4. Juli 2012, 21:54
 */

#ifndef ITEMBUTTON_H
#define	ITEMBUTTON_H
#include "Button.h"

class ItemButton : public Button{
    
public:
    ItemButton();
    ItemButton(int frameRect,sf::Texture* tex,char id);
    ItemButton(const ItemButton& orig);
    sf::Text* getText();
    void setCount(int i);
    virtual ~ItemButton();
private:
    int count;          // counter of Ressources
    char id;
    sf::Text* text;

};

#endif	/* ITEMBUTTON_H */

