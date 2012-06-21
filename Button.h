/* 
 * File:   Button.h
 * Author: niels
 *
 * Created on 21. Juni 2012, 07:55
 */

#ifndef BUTTON_H
#define	BUTTON_H
#include "GameObject.h"

class Button : public GameObject {
public:
    Button();
    Button(std::string buttenName);
    Button(const Button& orig);
    virtual ~Button();
    void press();
    void setName(std::string name);
    std::string getName();
    bool isPressed();
private:
    std::string name;
    bool pressed;
};

#endif	/* BUTTON_H */

