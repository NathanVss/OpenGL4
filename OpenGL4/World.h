#ifndef DEF_WORLD
#define DEF_WORLD

#include <iostream>
#include <vector>

#include "Renderer.h"
#include "Block.h"
#include "Chunk.h"
#include "PerlinNoise.h"
#include "BlockAir.h"
#include "BlockStone.h"
#include "BlockDirt.h"
#include "BlockWood.h"
#include "BlockLeaf.h"
#include "BlockGrass.h"

#include "CircleLight.h"
#include "Object.h"
#include "Updatable.h"

class Player;

class World : public Renderer, public Object, public Updatable
{
public:
	World();
	~World();

	void init();
	void addBlock(Block*);

	void update();
	void updateActiveChunksRectangle();

	virtual void render();
	void deleteBlock(int x, int y);
	void emptyWorld();
	void generateWorld();

	std::vector<Chunk*>* getChunks();
	Block* getBlock(int x, int y);
	std::vector<Chunk*>* getActiveChunks();
	NRectangle* getActiveChunksRectangle();


	void addPlayerToRendering(Player *pPlayer);

private:
	std::vector<Chunk*> Chunks;
	std::vector<Chunk*> ActiveChunks;
	NRectangle* ActiveChunksRectangle;

	std::vector<Player*> PlayersForRendering;
	PerlinNoise *pPerlinNoise;

	int heightChunks;
	int widthChunks;

};

#endif