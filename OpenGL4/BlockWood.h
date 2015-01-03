#pragma once
#include "Block.h"
#include "Item.h"

class BlockWood : public Block
{
public:
	BlockWood(int x, int y);
	BlockWood();
	virtual ~BlockWood(void);
	virtual void render();
	virtual Item* getItem();
};

