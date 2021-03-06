/* 
 * File:   Button.h
 * Author: niels
 *
 * Created on 21. Juni 2012, 07:55
 */

#ifndef BUTTON_H
#define	BUTTON_H
#include "GameObject.h"
#include "Ressource.h"
#include "Potion.h"

class Button : public GameObject {
public:
    Button();
    Button(int frameRect,sf::Texture* tex,std::string buttonName);
    Button(int frameRect,sf::Texture* tex,int id);
    Button(int frameRect,sf::Texture* tex);
    Button(int frameRect,sf::Texture* tex,std::string buttonName,int sizeX,int sizeY);
    Button(std::string buttenName);
    Button(const Button& orig);
    virtual ~Button();
    void press();
    void setName(std::string name);
    std::string getName();
    bool isPressed();
    void setPressed(bool press);
    // Visible or not visible
    void setVisible(bool vis);    
    bool isVisible();
    int getId();
    void setId(int i);
    
    void setRessource(Ressource* res);
    void setRessource(Potion* res);
    void setRessource(Ressource* res,bool setSprite);
    Ressource* getRessource();
private:
    std::string name;
    bool pressed;
    bool visible;       // standard: TRUE
    int id;
    
    Ressource* ressource;
};

#endif	/* BUTTON_H */

