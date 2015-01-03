#ifndef DEF_BLOCKGRASS
#define DEF_BLOCKGRASS

#include "Block.h"
#include "Item.h"
#include "ItemGrass.h"

class BlockGrass : public Block
{
public:
	BlockGrass(int x, int y);
	BlockGrass();
	virtual ~BlockGrass();
	virtual void render();
	virtual Item* getItem();
};

#endif
