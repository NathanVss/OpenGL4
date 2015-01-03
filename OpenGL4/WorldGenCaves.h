#pragma once
#include "worldgen.h"
class WorldGenCaves : public WorldGen
{

public:
	WorldGenCaves(void);
	~WorldGenCaves(void);
	virtual void generate(int width, int deep);
};

