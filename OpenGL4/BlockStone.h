#pragma once

#include "Block.h"
#include "Item.h"
#include "ItemStone.h"

class BlockStone : public Block
{
public:
	BlockStone(int x, int y);
	BlockStone();
	virtual ~BlockStone(void);
	virtual void render();
	virtual Item* getItem();
};

