#pragma once
//#include "c:\users\niels\documents\github\survival\gameobject.h"
#include "GameObject.h"

class Building : public GameObject
{
public:
	Building(void);
	Building(char id, sf::Texture *t, int frameRect);
        Building(Building& orig);
	~Building(void);
	std::map<int,int> getRessources();
	char getIdentifier();
	void setIdentifier(char id);
private:
	char identifier;
	std::map<int,int> ressources;
};

