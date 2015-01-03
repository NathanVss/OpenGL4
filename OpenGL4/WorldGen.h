#pragma once

#include "World.h"

class WorldGen
{
public:
	WorldGen();
	~WorldGen(void);
	virtual void setWorld(World*);
	virtual void generate(int x, int y);

protected:
	World* wWorld;
};

