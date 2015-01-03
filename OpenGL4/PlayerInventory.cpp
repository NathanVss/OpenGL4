#include "PlayerInventory.h"
#include <iostream>

PlayerInventory::PlayerInventory(Keyboard* kKeyboard) {
	this->mustDisplay = false;
	this->kKeyboard = kKeyboard;
	this->lastDisplayTicks = 0;
	this->inventorySize = 24;
	this->initItemStacks();
	
}


PlayerInventory::~PlayerInventory(void) {
}


void PlayerInventory::update() {
	if(this->kKeyboard->getKeyI() && this->lastDisplayTicks > 30) {
		if(this->mustDisplay) {
			this->mustDisplay = false;
		} else {
			this->mustDisplay = true;
		}
		this->lastDisplayTicks = 0;
	}
	lastDisplayTicks++;
}

void PlayerInventory::setInventorySpritesheet(Spritesheet* InventorySpritesheet) {

	this->InventorySpritesheet = InventorySpritesheet;
}

void PlayerInventory::render() {
	
	if(!this->mustDisplay) {
		return;
	}

	int invX = 10;
	int invY = 200;

	int invW = 8;
	int invH = 4;

	int width = 50 * invW;
	int height = width/invW * invH;
	glPushMatrix();


	glLoadIdentity();
	glTranslatef(invX,invY,0);
	glColor3ub(255,255,255);
	glEnable(GL_TEXTURE_2D);

	this->InventorySpritesheet->bind();
	glBegin(GL_QUADS);
	
	glTexCoord2d(0,1/16.0f * invH);
	glVertex2i(0,0);

	glTexCoord2d(1/16.0f * invW, 1/16.0f * invH);
	glVertex2i(width, 0);

	glTexCoord2d(1/16.0f * invW,0);
	glVertex2i(width, height);

	glTexCoord2d(0,0);
	glVertex2i(0, height);

	glEnd();

	glDisable(GL_TEXTURE_2D);

	int sizeOfASlot = 50;
	int line = 0;

	int curAbsc = 0;
	if(!this->ItemStacks.empty()) {
		for(int i = 0; i < this->inventorySize; i++) {
			
			if(i >= 0 && i < 8 ) {
				line = 1;
			} else if(i >= 8 && i < 16 ) {
				line = 2;
			} else if(i >= 16 && i < 24) {
				line = 3;
			}
			line = i/(this->inventorySize/3);

			if(i < this->ItemStacks.size()) {
				
				if(!this->ItemStacks[i]->isEmpty()) {

					if(i == 0 ||i == 8 || i == 16) {
						curAbsc = 0;
					} else {
						curAbsc += sizeOfASlot;
					}
					this->ItemStacks[i]->render(invX + curAbsc, (invY+sizeOfASlot) + sizeOfASlot*line);
				}
			}
		}
	}

	glPopMatrix();
}