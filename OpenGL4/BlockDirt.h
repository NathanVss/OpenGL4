#ifndef DEF_BLOCKDIRT
#define DEF_BLOCKDIRT

#include "Block.h"
class BlockDirt : public Block
{
public:

	BlockDirt(int x, int y);
	BlockDirt();
	virtual ~BlockDirt();
	virtual void render();
};

#endif

