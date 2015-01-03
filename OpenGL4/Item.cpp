#include "Item.h"


Item::Item(void) {
	this->placeable = false;
}


Item::~Item(void) {
}

bool Item::isPlaceable() {
	return this->placeable;
}

int Item::getId() {
	return this->id;
}