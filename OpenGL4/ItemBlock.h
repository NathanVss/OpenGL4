#ifndef DEF_ITEMBLOCK
#define DEF_ITEMBLOCK
#pragma once

#include "Block.h"
#include "Item.h"
#include <memory>

class ItemBlock : public Item
{
public:
	ItemBlock(void);
	~ItemBlock(void);
	virtual Block* getNewBlock(int, int) = 0;
};

#endif