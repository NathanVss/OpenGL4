#include "Chunk.h"
#include "Block.h"
#include "BlockAir.h"
#include "BlockDirt.h"
#include <iostream>
#include <vector>
#include "World.h"

int Chunk::chunkHeight = 16;
int Chunk::chunkSize = 16;

Chunk::Chunk(int cx, int cy) {
	this->x = cx;
	this->y = cy;

	// TEST
	int w = 16;
	int h = 16;
	Block*** Blocks = new Block**[w];
	for(int x=0;x<w;x++) {
		
		Blocks[x] = new Block*[h];
		for(int y=0;y<h;y++) {
			Blocks[x][y] = nullptr;
		}

	}
	this->Blocks = Blocks;
}

Block*** Chunk::getBlocks() {
	return this->Blocks;
}

void Chunk::init() {
	this->emptyChunk();
}

void Chunk::addBlock(Block* b) {
	if(this->Blocks[b->getX()-this->x][b->getY()-this->y]) {
		delete this->Blocks[b->getX()-this->x][b->getY()-this->y];
	}

	b->setParentChunk(this);
	b->setContainer(this->container);
	this->Blocks[b->getX()-this->x][b->getY()-this->y] = b;
}

Block* Chunk::getBlock(int x, int y) {
	if(this->Blocks[x-this->x][y-this->y]) {
		return this->Blocks[x-this->x][y-this->y];
	}
	return nullptr;
}

void Chunk::emptyChunk() {

	 //TEST
	for(int x=0;x<16;x++) {
		for(int y=0;y<16;y++) {

			this->addBlock(new BlockAir(this->x+x, this->y+y));

		}

	}

}


int Chunk::getX() {
	return this->x;
}

int Chunk::getY() {
	return this->y;
}

void Chunk::render() {

	for(int x=0;x<16;x++) {
		for(int y=0;y<16;y++) {
			this->Blocks[x][y]->render();
		}

	}


	glPushMatrix();

	glTranslatef(this->x*32, this->y*32, 0);

	glBegin(GL_LINES);
		glColor3ub(255,0,0);
		glVertex2i(0,0);
		glVertex2i(16*32,0);

		glVertex2i(16*32,0);
		glVertex2i(16*32,16*32);


		glVertex2i(16*32,16*32);
		glVertex2i(0,16*32);

		glVertex2i(0,16*32);
		glVertex2i(0,0);
	glEnd();

	glPopMatrix();
}



Chunk::~Chunk(void)
{
	
	for(int x=0;x<16;x++) {
		for(int y=0;y<16;y++) {
			if(this->Blocks[x][y]) {
				OutputDebugString("\nDELETE\n");
				delete this->Blocks[x][y];
			}


		}


	}
	
	for(int i=0;i<16;i++) {
		if(this->Blocks[i]) {
			delete this->Blocks[i];
		}
	}

	if(this->Blocks) {
		delete this->Blocks;
	}
}