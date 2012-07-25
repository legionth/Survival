/* 
 * File:   Inventory.cpp
 * Author: legionth
 * 
 * Created on 23. Juli 2012, 13:12
 */

#include "Inventory.h"

Inventory::Inventory() : Menu(0,0,FRAME_WIDTH * 5, FRAME_HEIGHT * 5){
    shown = false;
}


Inventory::~Inventory() {
}


 bool Inventory::isShown(){
     return this->shown;
 }
 
 void Inventory::show(){
     this->shown = !shown;
 }
