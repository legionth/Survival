/* 
 * File:   SlotButton.h
 * Author: legionth
 *
 * Created on 28. Juli 2012, 00:13
 */

#ifndef SLOTBUTTON_H
#define	SLOTBUTTON_H
#include "Tool.h"
#include "Button.h"

class SlotButton : public Button{
public:
    SlotButton(Tool* tool, sf::Texture* tex);
    SlotButton(const SlotButton& orig);
    void setTool(Tool* tool);
    Tool* getTool();
    virtual ~SlotButton();
private:
    Tool* tool;
};

#endif	/* SLOTBUTTON_H */

