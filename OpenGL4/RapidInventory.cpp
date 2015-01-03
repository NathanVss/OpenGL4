#include "RapidInventory.h"
#include <iostream>

RapidInventory::RapidInventory() {
	this->selectedSlot = 0;
	this->inventorySize = 10;
	this->initItemStacks();
}


RapidInventory::~RapidInventory(void) {
}

void RapidInventory::update() {

	if(this->kKeyboard->getKey1()) {
		this->selectedSlot = 0;
	} else if(this->kKeyboard->getKey2()) {
		this->selectedSlot = 1;
	} else if(this->kKeyboard->getKey3()) {
		this->selectedSlot = 2;
	} else if(this->kKeyboard->getKey4()) {
		this->selectedSlot = 3;
	} else if(this->kKeyboard->getKey5()) {
		this->selectedSlot = 4;
	} else if(this->kKeyboard->getKey6()) {
		this->selectedSlot = 5;
	} else if(this->kKeyboard->getKey7()) {
		this->selectedSlot = 6;
	} else if(this->kKeyboard->getKey8()) {
		this->selectedSlot = 7;
	} else if(this->kKeyboard->getKey9()) {
		this->selectedSlot = 8;
	} else if(this->kKeyboard->getKey0()) {
		this->selectedSlot = 9;
	}

}

void RapidInventory::render() {

	int sizeOfASlot = 50;
	int slots = 10;

	int curSlot;

	glPushMatrix();

		glColor3ub(255,255,255);
	glEnable(GL_TEXTURE_2D);

	this->MiscSpritesheet->bind();
	this->MiscSpritesheet->setCurSprite(0,0);

	for(curSlot = 0; curSlot < slots; curSlot++) {
		glLoadIdentity();
		glTranslatef(curSlot*sizeOfASlot,720-sizeOfASlot, 0);
		glBegin(GL_QUADS);

		this->MiscSpritesheet->setTopLeftTexCoord();
		glVertex2i(0,0);

		this->MiscSpritesheet->setTopRightTexCoord();
		glVertex2i(sizeOfASlot,0);


		this->MiscSpritesheet->setBottomRightTexCoord();
		glVertex2i(sizeOfASlot,sizeOfASlot);

		this->MiscSpritesheet->setBottomLeftTexCoord();
		glVertex2i(0,sizeOfASlot);

		glEnd();
	}
	glDisable(GL_TEXTURE_2D);


	glLoadIdentity();
	glTranslatef(0, 720-sizeOfASlot, 0);
	for(int i = 0; i < this->inventorySize; i++) {
		
		glTranslatef(i*sizeOfASlot,0,0);
		if(this->ItemStacks[i]) {
			this->ItemStacks[i]->render(i*sizeOfASlot, 720-sizeOfASlot);
		}
	}

	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	//std::cout << this->selectedSlot << std::endl;
	this->MiscSpritesheet->bind();
	glTranslatef(this->selectedSlot*sizeOfASlot, 720-sizeOfASlot, 0);
	this->MiscSpritesheet->setCurSprite(1,0);
	
	glBegin(GL_QUADS);

		glColor3ub(255,255,255);
		this->MiscSpritesheet->setTopLeftTexCoord();
		glVertex2i(0,0);
		this->MiscSpritesheet->setTopRightTexCoord();
		glVertex2i(sizeOfASlot,0);
		this->MiscSpritesheet->setBottomRightTexCoord();
		glVertex2i(sizeOfASlot,sizeOfASlot);
		this->MiscSpritesheet->setBottomLeftTexCoord();
		glVertex2i(0,sizeOfASlot);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void RapidInventory::setMiscSpritesheet(Spritesheet* MiscSpritesheet) {

	this->MiscSpritesheet = MiscSpritesheet;

}
