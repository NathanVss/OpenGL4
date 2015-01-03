#include "Block.h"
#include <iostream>
#include "TextureLoader.h"
#include "Boot.h"
#include "Light.h"
#include "Vector2D.h"
#include "World.h"
#include "Chunk.h"

int Block::AirId = 1;
int Block::DirtId = 2;
int Block::GrassId = 3;
int Block::StoneId = 4;
int Block::LeafId = 5;
int Block::WoodId = 6;

Block::Block(int x, int y){
	this->x = x;
	this->y = y;
	this->size = 32;
	this->BoundingBox = new NRectangle(this->x * this->size, this->y * this->size, this->size, this->size);
	this->bBox = true;
	this->isObstrued = false;

	this->isTransparent = false;
	this->lightIndice = 1.0f;
	this->lightIndiceTicks = 0;
}
Block::Block() {
	this->BoundingBox = nullptr;
}
Block::~Block() {

	if(this->BoundingBox) {
		delete this->BoundingBox;
	}
}
float Block::getLightIndice() {
	return this->lightIndice;
}


void Block::setParentChunk(Chunk* c)  {
	this->ParentChunk = c;
}

float Block::getColorIndice() {
	//if(this->isTransparent) {
	//	return 1.0f;
	//}
	//float colorIndice = this->lLighManager->getColor(this->x*this->size, this->y*this->size);
	return this->lightIndice;
	//return this->lLighManager->getColor(this->x*this->size, this->y*this->size);
}

void Block::setRenderColor() {
	float colorIndice = this->getColorIndice();
	glColor4f(colorIndice*(this->red/255.0f), colorIndice*(this->green/255.0f), colorIndice*(this->blue/255.0f), 1.0f);
}

bool Block::getIsTransparent() {
	return this->isTransparent;
}

//void Block::setTestSun(CircleLight* c) {
//	this->TestSun = c;
//}

Item* Block::getItem() {
	return false;
}

int Block::getId() {
	return this->id;
}

void Block::setRed(int red) {
	this->red = red;
}



NRectangle* Block::getBoundingBox() {
	return this->BoundingBox;
}

bool Block::hasBBox() {
	return this->bBox;
}





bool Block::mustRender() {
	return true;
}

void Block::setLightIndice(float f) {
	this->lightIndice = f;
}

bool Block::getIsObstrued() {
	return this->isObstrued;
}

void Block::renderBase() {
	int mapX = this->x - this->container->getWorld()->getActiveChunksRectangle()->getX1();
	int mapY = this->y - this->container->getWorld()->getActiveChunksRectangle()->getY1();
	
	auto FinalShadowMap = this->container->getLightManager()->getFinalShadowMap();

	if(FinalShadowMap) {
		float lightIndice = FinalShadowMap->getScale(mapX, mapY)/255.0f;
		if(lightIndice != -1) {
			this->lightIndice = lightIndice;
		}

	}



	//if(this->lightIndiceTicks > 10000000) {
	//	this->lightIndiceTicks = 0;
	//	

	//	std::shared_ptr<Light> lLight= this->container->getLightManager()->getLight(0);
	//	std::shared_ptr<Vector2D> vector(new Vector2D());
	//	vector->setBase(this->x*this->size, this->y*this->size);
	//	vector->setEnd(lLight->getX(), lLight->getY());
	//	std::pair<int, int> neightboorCoords = vector->getCoordFromRadius(32);
	//
	//	std::shared_ptr<Block> neightboor = this->container->getWorld()->getBlock(round(neightboorCoords.first/32.0f), round(neightboorCoords.second/32.0f));


	//	double dist = sqrt((pow((this->x - lLight->getX()/32.0f), 2) + pow((this->y - lLight->getY()/32.0f), 2)));
	//	
	//	if(dist > 2) {
	//		if(neightboor && !neightboor->getIsObstrued()) {
	//			this->isObstrued = false;
	//		}
	//		if(neightboor && !neightboor->getIsTransparent()) {
	//			//OutputDebugString("HERE\n");
	//			this->isObstrued = true;
	//		}
	//		if(neightboor && neightboor->getIsObstrued()){
	//			this->isObstrued = true;
	//		}


	//		if(this->isObstrued && neightboor) {
	//			this->lightIndice = neightboor->getLightIndice() * ((1-dist/30.0f));
	//		} else {
	//			this->lightIndice = this->container->getLightManager()->getColor(this->x*this->size, this->y*this->size);
	//		} 


	//		//if((neightboor && !neightboor->getIsTransparent()) || (this->isTransparent && (neightboor && neightboor->getIsObstrued() ))) {
	//		//	this->lightIndice = neightboor->getLightIndice() * 0.6f;
	//		//} else {
	//		//	this->lightIndice = this->container->getLightManager()->getColor(this->x*this->size, this->y*this->size);
	//		//} 

	//	} else {
	//		//debug(dist);
	//		this->isObstrued = false;
	//		this->lightIndice = this->container->getLightManager()->getColor(this->x*this->size, this->y*this->size);
	//	}
	//}
	//this->lightIndice = this->container->getLightManager()->getColor(this->x*this->size, this->y*this->size);
	this->lightIndiceTicks++;
}

int Block::getX() {
	return this->x;
}

int Block::getY() {
	return this->y;
}