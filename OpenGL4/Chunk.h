#ifndef DEF_CHUNK
#define DEF_CHUNK

#include <vector>
#include "Block.h"
#include <memory>
#include "Object.h"

class World;

class Chunk: public Object
{
public:
	Chunk(int x, int y);
	virtual ~Chunk(void);
	void render();
	int getX();
	int getY();
	void emptyChunk();


	static int chunkHeight;
	static int chunkSize;
	void init();

	// TEST
	Block*** getBlocks();
	void addBlock(Block*);
	Block* getBlock(int x, int y);

private:
	int x;
	int y;

	Block*** Blocks;
};

#endif

