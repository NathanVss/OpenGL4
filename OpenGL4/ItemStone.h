#pragma once

#include "Item.h"
class ItemStone : public Item
{
public:
	ItemStone(void);
	~ItemStone(void);
	void render(int x, int y);

};

