#include "Inventory.h"


Inventory::Inventory(void)
{
}


Inventory::~Inventory(void)
{
}

void Inventory::update() { }


ItemStack* Inventory::getSelectedItemStack() {
	return this->ItemStacks[this->selectedSlot];
}

void Inventory::initItemStacks() {
	for(int i = 0; i< this->inventorySize; i++) {
		ItemStack* newItemStack = new ItemStack();
		this->ItemStacks.push_back(newItemStack);
	}
}

ItemStack* Inventory::getItemStack(int pos) {
	return this->ItemStacks[pos];
}

bool Inventory::consumeItemOfCurSlot(int quantity) {
	return this->consumeItem(this->selectedSlot, quantity);
}

bool Inventory::consumeItem(int slot, int quantity) {
	if(slot >= this->inventorySize) {
		return false;
	}
	
	if(this->ItemStacks[slot]->getSize() < quantity) {
		return false;
	}

	for(int i=0; i <quantity; i++) {
		this->ItemStacks[slot]->deleteLast();
	}
	if(this->ItemStacks[slot]->isEmpty()) {
		std::cout << "EMPTY" << std::endl;

		delete this->ItemStacks[slot];
		this->ItemStacks[slot] = new ItemStack();
	}
	return true;
}

bool Inventory::addItem(Item* iItem) {

	for(int i=0;i<this->ItemStacks.size();i++) {
		if(this->ItemStacks[i]->doAcceptItem(iItem)) {

			return this->ItemStacks[i]->addItem(iItem);
		}
	}
	return false;
}