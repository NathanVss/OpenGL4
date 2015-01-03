#pragma once
#include <vector>
#include "Item.h"
class ItemStack
{
public:
	ItemStack(void);
	~ItemStack(void);
	bool addItem(Item *iItem);
	int getSize();
	void render(int x, int y);
	int getItemId();
	bool isFull();
	int getLimit();
	bool isEmpty();
	bool deleteLast();
	Item* getItem();
	bool isVirgin();
	bool doAcceptItem(Item*);

private:
	std::vector<Item*> Items;
	int itemId;
	int stackLimit;
	int stackType; // BLOCK: 1
};

