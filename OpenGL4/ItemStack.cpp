#include "ItemStack.h"
#include <iostream>
#include "FontRenderer.h"
#include "Utils.h"

ItemStack::ItemStack(void) {
	this->stackLimit = 8;
	this->itemId = 0;
	std::cout << this->Items.size() << std::endl;
}

int ItemStack::getLimit() {
	return this->stackLimit;
}

int ItemStack::getSize() {
	return this->Items.size();
}

bool ItemStack::isEmpty() {
	if(this->Items.size() == 0) {
		return true;
	} else {
		return false;
	}
}


ItemStack::~ItemStack(void) {
}

int ItemStack::getItemId() {
	/*if(!this->isEmpty()) {
		return this->Items[0]->getId();
	}
	return false;*/
	return this->itemId;
}

void ItemStack::render(int x, int y) {
	if(!this->isEmpty()) {
		this->Items[0]->render(x,y);
		int size = this->Items.size();
		FontRenderer::srenderText(Utils::getString(size).c_str(), x+10, y+20, 2);
	}
}

bool ItemStack::isFull() {
	if(this->Items.size() >= this->stackLimit) {
		return true;
	} else {
		return false;
	}
}

Item* ItemStack::getItem() {
	if(!this->isEmpty()) {
		return this->Items[0];
	}
	return false;
}
bool ItemStack::isVirgin() {
	return this->itemId == 0;
}

bool ItemStack::doAcceptItem(Item* iItem) {
	if(this->isVirgin() || (!this->isFull() && this->itemId == iItem->getId())) {
		return true;
	}
	return false;
}

bool ItemStack::addItem(Item* iItem) {

	//std::cout << "ADDING ITEM IN ITEM STACK( " << this->itemId << ")[ " << this->Items.size() << " : " << iItem->getId() << std::endl;
	if(this->Items.size() > 0) {

		//std::cout << "SIZE > 0 : " << iItem->getId() << std::endl;
		if(this->itemId == iItem->getId()) {

			//std::cout << "SAME IDS : " << iItem->getId() << std::endl;
			this->Items.push_back(iItem);
			return true;
		}
		return false;

	} else {
		this->Items.push_back(iItem);
		this->itemId = iItem->getId();
		return true;
		//std::cout << "FIRST ITEM IN THIS ITEM STACK : " << iItem->getId() << std::endl;
	}
	
	
}

bool ItemStack::deleteLast() {
	if(this->Items.size() > 0) {
		this->Items.pop_back();
		return true;
	}
	return false;
}