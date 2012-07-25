/* 
 * File:   Inventory.h
 * Author: legionth
 *
 * Created on 23. Juli 2012, 13:12
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

#include "Menu.h"

class Inventory : public Menu {
public:
    Inventory();
    virtual ~Inventory();
    bool isShown();
    void show(); 
private:
    bool shown;
};

#endif	/* INVENTORY_H */

