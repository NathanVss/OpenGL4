#pragma once

#include "Spritesheet.h"
#include "Keyboard.h"
#include "Item.h"
#include "ItemStack.h"
#include "Keyboardable.h"

#include "Inventory.h"

class RapidInventory : public Keyboardable, public Inventory
{
public:
	RapidInventory(void);
	~RapidInventory(void);
	virtual void update();
	
	void setMiscSpritesheet(Spritesheet* MiscSpritesheet);
	void render();

private:
	//int selectedSlot;
	//ItemStack* ItemStacks[10];
	Spritesheet* MiscSpritesheet;
};

