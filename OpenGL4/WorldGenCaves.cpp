#include "WorldGenCaves.h"


WorldGenCaves::WorldGenCaves(void)
{
}


WorldGenCaves::~WorldGenCaves(void)
{
}

void WorldGenCaves::generate(int width, int deep) {
	int caveHeight = 10;
	int maxSurface = 15;
	// Deep : MAX > Deep > 20
	// y = deep > y > 20
	// y * ([deep-20;20])
	std::unique_ptr<PerlinNoise> pPerlin(new PerlinNoise());
	pPerlin->init(width, 20, 1);

	for(int x = 0; x < width; x++) {
		int y = (int)(pPerlin->coherentNoise(x, 0.1)*(deep-20));
		y += maxSurface;

		BlockAir* bBlockAir = new BlockAir(x, y);
		this->wWorld->addBlock(bBlockAir);
		for(int yy = y +1; yy < y + caveHeight; yy++) {
			BlockAir* bBlockAir= new BlockAir(x, yy);
			this->wWorld->addBlock(bBlockAir);
		}

		
		
	}

}