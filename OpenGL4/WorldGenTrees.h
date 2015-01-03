#pragma once
#include "worldgen.h"

class World;

class WorldGenTrees : public WorldGen
{
public:
	WorldGenTrees();
	~WorldGenTrees(void);
	void generate(int x, int y);

protected:
	int height;

};

