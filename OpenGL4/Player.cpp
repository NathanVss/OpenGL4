#include "Player.h"
#include "ItemBlock.h"
#include "Boot.h"

Player::Player(void):Entity()
{
	this->x = 0;
	this->y = 0;
	this->speed = 10;
	this->bBox = true;
	this->width = 30;
	this->height = 60;
	this->BoundingBox = std::shared_ptr<NRectangle>(new NRectangle(this->x-this->width/2, this->y-this->height/2, this->width, this->height));
	this->isJumping = false;
	this->jumpingState = 0;
	this->yVelocity = 1.0f;
	this->jumpQuantity = 80;
	this->jumpDivider = 15.0f;
	this->gravity = 1.06f;
	//this->gravity = 1.0f;
	this->isGodMode = false;

}

void Player::setName(std::string name) {
	this->name = name;
}

std::string Player::getName() {
	return this->name;
}

void Player::setGodMode(bool flag) {
	this->isGodMode = flag;
}
bool Player::getIsGodMode() {
	return this->isGodMode;
}

void Player::setPlayerInventory(PlayerInventory* pPlayerInventory) {
	this->pPlayerInventory = pPlayerInventory;

}

void Player::setKeyboard(Keyboard* k) {
	this->kKeyboard = k;
}

void Player::setWorld(World* wWorld) {

	this->wWorld = wWorld;
}

void Player::setRapidInventory(RapidInventory* rRapidInventory) {
	this->rRapidInventory = rRapidInventory;
}

void Player::teleport(int x, int y) {
	this->x = x;
	this->y = y;

}

int Player::getX() {
	return this->x;
}

int Player::getY() {
	return this->y;
}

void Player::update() {
	this->pPlayerInventory->update();
	this->rRapidInventory->update();
	std::vector<Chunk*>* Chunks = this->wWorld->getChunks();

	int cx = 0,cy = 0;
	if(this->isGodMode) {
		this->gravity = 1.0f;
		this->yVelocity = 0.0f;
	}
	if(this->isGodMode && this->kKeyboard->getKeyUp()) {

		cy = -this->speed;

	} else if(this->kKeyboard->getKeyUp() && !this->isJumping && this->collideOnBottom) {
		//cy = -this->speed-30;
		this->isJumping = true;
		this->jumpingState = 1;
	}
	if(this->kKeyboard->getKeyDown()) {

		cy = this->speed;
	}
	if(this->kKeyboard->getKeyLeft()) {
		cx = -this->speed;
	}
	if(this->kKeyboard->getKeyRight()) {
		cx = this->speed;
	}

	if(this->jumpingState > 0 && this->jumpingState <= this->jumpDivider) {
		cy = -this->speed-(this->jumpQuantity) / this->jumpDivider;
		this->jumpingState++;
	} else {
		if(this->isJumping) {
			this->jumpingState = 0;
		}
	}

	if(!this->collideOnBottom ) {
		if(this->yVelocity < 100) {
			this->yVelocity *= this->gravity;
		}
	} else {
		this->yVelocity = 1;
	}
	cy += this->yVelocity;

	if(this->isJumping) {
		if(this->collideOnBottom) {
			this->isJumping = false;
		}
	}


	Block* testBlock = this->wWorld->getBlock(floor(((Mouse::wX)/32.0f)),floor((Mouse::wY)/32.0f));
	if(testBlock) {
			//debug((double)testBlock->getX());
			if(testBlock->getIsObstrued()) {
				
				
				//OutputDebugString("\nObstrued");
			} else {
				//OutputDebugString("\nNOO");
			}

	}

	if(Mouse::leftClick || Mouse::rightClick) {

		bool canReplace = true;
		Block* bBlock = this->wWorld->getBlock(floor(((Mouse::wX)/32.0f)),floor((Mouse::wY)/32.0f));
		
		if(bBlock) {


			Block* NewBlock = nullptr;
			Item* droppedItem = nullptr;
			if(Mouse::leftClick) {
				if(bBlock->getId() == Block::AirId) {
					canReplace = false;
				} else  {
					NewBlock = new BlockAir((*bBlock).getX(), (*bBlock).getY());
					droppedItem = bBlock->getItem();
				}
			} else if(Mouse::rightClick) {
				if(bBlock->getId() == Block::AirId) {

					/*
					 * Si curItem alors l'item stack n'est pas vite
					 * On vérifie que l'item exemple est placable
					 * Si oui, on place le block qui lui correspond
					 * Puis on supprime l'item
					 */
					Item* curItem = this->rRapidInventory->getSelectedItemStack()->getItem();

					if(curItem) {
						
						if(curItem->isPlaceable()) {
							ItemBlock* curPlaceableItem = dynamic_cast<ItemBlock*>(curItem);
							NewBlock = curPlaceableItem->getNewBlock(bBlock->getX(), bBlock->getY());
							bool flag = this->rRapidInventory->consumeItemOfCurSlot(1);
							// Non utilisable .. à chercher : delete curItem;
						}

					}

				} else {
					canReplace = false;
				}
				
			}

			if(canReplace) {
				if(droppedItem) {
					bool addedRapid = this->rRapidInventory->addItem(droppedItem);
					if(!addedRapid)  {
						this->pPlayerInventory->addItem(droppedItem);
					}
				}

				if(NewBlock != nullptr) {
					this->wWorld->addBlock(NewBlock);
				}

			}
		}
	}

	this->checkCollisions(this->wWorld, Chunks, this->x + cx, this->y + cy);

}

void Player::render() {

	glPushMatrix();

	glTranslatef(this->x-(this->width/2), this->y-(this->height/2), 0);

	glBegin(GL_QUADS);

	glColor3ub(41, 128, 185);
	glVertex2i(0,0);
	glVertex2i(width, 0);
	glVertex2i(width, height);
	glVertex2i(0, height);

	glEnd();


	glPopMatrix();



	this->rRapidInventory->render();
	this->pPlayerInventory->render();

}

Player::~Player(void)
{
}
