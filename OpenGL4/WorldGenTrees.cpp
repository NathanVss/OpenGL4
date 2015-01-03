#include "WorldGenTrees.h"
#include "BlockStone.h"
#include "BlockWood.h"
#include "BlockLeaf.h"
#include <random>


WorldGenTrees::WorldGenTrees() {
	this->height = rand() % 6 + 1;
}

void WorldGenTrees::generate(int x, int y) {
	for(int h=0;h<this->height;h++) {
		wWorld->addBlock(new BlockWood(x,y-1-h));
	}
	for(int w=-2;w<=2;w++) {
		wWorld->addBlock(new BlockLeaf(x+w,y-this->height-1));
	}
	for(int w=-1;w<=1;w++) {
		wWorld->addBlock(new BlockLeaf(x+w,y-this->height-2));
	}
}




WorldGenTrees::~WorldGenTrees(void) {
}
