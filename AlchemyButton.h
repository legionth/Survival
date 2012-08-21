/* 
 * File:   AlchemyButton.h
 * Author: niels
 *
 * Created on 21. Juni 2012, 08:01
 */

#ifndef AlchemyBUTTON_H
#define	AlchemyBUTTON_H
#include "Button.h"
#include "Potion.h"

class AlchemyButton : public Button{
public:
    AlchemyButton(Potion* p, std::string name);
    AlchemyButton(int frameRect,sf::Texture* tex,int id);
    AlchemyButton(const AlchemyButton& orig);
    virtual ~AlchemyButton();
    
    void setPotion(Potion* potion);
    Potion* getPotion();
private:
    Potion* potion;
};

#endif	/* AlchemyBUTTON_H */