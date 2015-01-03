#pragma once
#include "Block.h"


class BlockLeaf : public Block
{
public:
	BlockLeaf(int x, int y);
	BlockLeaf();
	virtual ~BlockLeaf(void);
	virtual void render();
	virtual Item* getItem();
};

