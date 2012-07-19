/* 
 * File:   StatusButton.h
 * Author: legionth
 *
 * Created on 19. Juli 2012, 23:04
 */

#ifndef STATUSBUTTON_H
#define	STATUSBUTTON_H

#include "Button.h"

class StatusButton : public Button{
public:
    StatusButton(int id);
    StatusButton(const StatusButton& orig);
    int getId();
    virtual ~StatusButton();
private:
    int id;

};

#endif	/* STATUSBUTTON_H */

