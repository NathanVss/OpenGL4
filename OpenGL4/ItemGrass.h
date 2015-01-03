#pragma once
#include "Item.h"
#include "ItemBlock.h"
#include "BlockGrass.h"
#include <memory>

class ItemGrass : public ItemBlock
{
public:
	ItemGrass(void);
	~ItemGrass(void);
	virtual void render(int x, int y);
	virtual Block* getNewBlock(int, int);
	
};

