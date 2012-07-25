/* 
 * File:   Tool.h
 * Author: niels
 *
 * Created on 25. Juli 2012, 08:36
 */

#ifndef TOOL_H
#define	TOOL_H
#include "GameObject.h"

class Tool : public GameObject{
public:
    Tool(int id);
    Tool(const Tool& orig);
    virtual ~Tool();
    int getId();
    void setId(int id);
private:
    int id;
};

#endif	/* TOOL_H */

