/* 
 * File:   Tool.cpp
 * Author: niels
 * 
 * Created on 25. Juli 2012, 08:36
 */

#include "Tool.h"

Tool::Tool(int id) {
    setId(id);
}

Tool::Tool(const Tool& orig) {
}

Tool::~Tool() {
}

void Tool::setId(int id){
    this->id = id;
}

int Tool::getId(){
   return this->id; 
}
