#ifndef DEF_INVENTORY
#define DEF_INVENTORY
#pragma once

#include "Updatable.h"
#include "ItemStack.h"
#include "Item.h"
#include <vector>
#include <iostream>

class Inventory : public Updatable
{
public:
	Inventory(void);
	~Inventory(void);
	ItemStack* getItemStack(int);
	/* A condition d'avoir défini inventorySize avant */
	void initItemStacks();
	bool addItem(Item*);
	bool consumeItem(int slot, int quantity);
	bool consumeItemOfCurSlot(int quantity);
	ItemStack* getSelectedItemStack();

	virtual void update();

protected:
	int inventorySize;
	int selectedSlot;
	std::vector<ItemStack*> ItemStacks;

};

#endif