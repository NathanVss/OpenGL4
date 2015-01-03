#ifndef DEF_BLOCKAIR
#define DEF_BLOCKAIR

#include "Block.h"

class BlockAir: public Block {

public:
	BlockAir();
	BlockAir(int x, int y);
	virtual ~BlockAir();
	virtual void render();

};

#endif
