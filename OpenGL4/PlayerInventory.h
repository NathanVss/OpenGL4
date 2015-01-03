#pragma once
#include "Spritesheet.h"
#include "Keyboard.h"
#include "ItemStack.h"
#include "Item.h"
#include <vector>
#include "Inventory.h"

class PlayerInventory : public Inventory
{
public:
	PlayerInventory(Keyboard* kKeyboard);
	~PlayerInventory(void);
	void render();
	virtual void update();

	void setInventorySpritesheet(Spritesheet* InventorySpritesheet);


private:
	bool mustDisplay;
	int lastDisplayTicks;
	Keyboard* kKeyboard;
	Spritesheet* InventorySpritesheet;

};

