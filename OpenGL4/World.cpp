#include "World.h"
#include "Player.h"
#include "WorldGenTrees.h"
#include "WorldGenCaves.h"
#include "Block.h"
#include <memory>

World::World() {

	this->heightChunks = 4;
	this->widthChunks = 6;
	
	this->ActiveChunksRectangle = nullptr;
	PerlinNoise *pPerlinNoise = new PerlinNoise();
	this->pPerlinNoise = pPerlinNoise;


}

//std::vector<std::shared_ptr<Block>> World::getBlocks() {
//	std::vector<std::shared_ptr<Block>> Blocks;
//	return Blocks;
	//for(int x=0; x<this->Chunks.size(); x++) {
	//	//std::shared_ptr<Chunk> CurChunk = this->Chunks[x];
	//	std::vector<std::shared_ptr<Block>> bBlocks = this->Chunks[x]->getBlocks();	
	//	for(int i=0; i<bBlocks.size(); i++) {
	//		Blocks.push_back(bBlocks[i]);
	//	}
	//}
	//return Blocks;
//}

std::vector<Chunk*>* World::getActiveChunks() {
	return &this->ActiveChunks;
}

void World::init() {
	for(int x = 0;x < widthChunks; x++) {
		for(int y = 0; y < this->heightChunks; y++) {
			Chunk* CurChunk(new Chunk(x*16, y*16));
			CurChunk->setContainer(this->container);
			CurChunk->init();
			this->Chunks.push_back(CurChunk);

		}
	}
}
Block* World::getBlock(int x, int y) {
	for(int i = 0; i < this->Chunks.size(); i++) {

		if(this->Chunks[i]->getX() <= x && this->Chunks[i]->getX() + 16 > x) {
			if(this->Chunks[i]->getY() <= y && this->Chunks[i]->getY() + 16 > y) {
				return this->Chunks[i]->getBlock(x, y);
			}

		}
	}
	return false;
}

void World::emptyWorld() {
	for(int i = 0; i < this->Chunks.size(); i++) {

		this->Chunks[i]->emptyChunk();
	}
}

std::vector<Chunk*>* World::getChunks() {
	return &this->Chunks;
}

void World::generateWorld() {
	this->emptyWorld();
	this->pPerlinNoise->init(1280, 30, 1);

	int stoneSurface = 5;

	for(int x = 0; x < 1280; x++) {
		int y = (int)(this->pPerlinNoise->coherentNoise(x, 0.99)*32);
		BlockGrass* grassBlock = new BlockGrass(x, y);
		this->addBlock(grassBlock);


		for(int yy = y+1; yy < y + stoneSurface+6; yy++) {
			BlockDirt* fillDirtBlock = new BlockDirt(x, yy);
			this->addBlock(fillDirtBlock);
		}

		int curStoneSurface = stoneSurface + ( rand() % 3 );
		for(int yy = y + curStoneSurface; yy < this->heightChunks*Chunk::chunkHeight; yy++) {
			BlockStone* fillStoneBlock = new BlockStone(x, yy);
			this->addBlock(fillStoneBlock);
		}

		int randNbr = rand();
		randNbr = (randNbr % 100) + 1;

		if(randNbr < 50 && randNbr > 40) {
			std::shared_ptr<WorldGenTrees> wGenTrees(new WorldGenTrees());
			//WorldGenTrees* wGenTrees = new WorldGenTrees();
			wGenTrees->setWorld(this);
			wGenTrees->generate(x, y);
		}
	}
	std::shared_ptr<WorldGenCaves> wGenCaves(new WorldGenCaves());
	wGenCaves->setWorld(this);
	wGenCaves->generate(1280, this->heightChunks*Chunk::chunkHeight);


}

NRectangle* World::getActiveChunksRectangle() {
	return this->ActiveChunksRectangle;
}

void World::update() {
	int radius = 32;
	this->ActiveChunks.clear();


	// Si plusieurs joueur, plusieurs fois même chunk dans actives ?
	for(int i=0; i<this->PlayersForRendering.size(); i++) {

		int px = this->PlayersForRendering[i]->getX()/32.0f;
		int py = this->PlayersForRendering[i]->getY()/32.0f;
		int topLeftXBox = px-radius;
		int topLeftYBox = py-radius;
		int boxWidth = radius*2;
		for(int j = 0; j < this->Chunks.size(); j++) {

			int cx = this->Chunks[j]->getX()+8;
			int cy = this->Chunks[j]->getY()+8;


			if(cx >= topLeftXBox && cx <= topLeftXBox + boxWidth && cy >= topLeftYBox && cy <= topLeftYBox + boxWidth) {
				this->ActiveChunks.push_back(this->Chunks[j]);
			}
		}
	}
	this->updateActiveChunksRectangle();


	//debug((int)this->ActiveChunks.size());
}

void World::updateActiveChunksRectangle() {
	if(this->ActiveChunksRectangle) {
		delete this->ActiveChunksRectangle;
		this->ActiveChunksRectangle = nullptr;
	}
	int topLeftX = 0;
	int topLeftY = 0;
	int bottomRightX = 0;
	int bottomRightY = 0;
	for(int i=0;i<this->ActiveChunks.size();i++) {


		int chunkX = ActiveChunks[i]->getX();
		int chunkY = ActiveChunks[i]->getY();
		if(i==0) {
			topLeftX = chunkX;
			topLeftY = chunkY;
		}

		if(chunkX <= topLeftX ) {
			topLeftX = chunkX;
		}
		if(chunkX >= bottomRightX ) {
			bottomRightX = chunkX;
		}

		
		if(chunkY <= topLeftY ) {
			topLeftY = chunkY;
		}
		if(chunkY >= bottomRightY ) {
			bottomRightY = chunkY;
		}
	}
	bottomRightX += 16;
	bottomRightY += 16;
	this->ActiveChunksRectangle = new NRectangle(topLeftX, topLeftY, bottomRightX-topLeftX, bottomRightY-topLeftY);
}

World::~World() {
	for(int i=0;i<this->Chunks.size();i++) {

		if(this->Chunks[i]) {
			delete this->Chunks[i];
		}

	}
}

void World::addBlock(Block* Block) {

	for(int i=0; i<this->Chunks.size(); i++) {
		Chunk* CurChunk = this->Chunks[i];
		if(Block->getX() >= CurChunk->getX() && Block->getX() < CurChunk->getX()+16 && Block->getY() >= CurChunk->getY() && Block->getY() < CurChunk->getY() + 16) {
			CurChunk->addBlock(Block);
		}
	}
	
}

void World::addPlayerToRendering(Player *pPlayer) {
	this->PlayersForRendering.push_back(pPlayer);
}

void World::render()  {


	for(int i=0; i<this->PlayersForRendering.size(); i++) {
		Player* CurPlayer = this->PlayersForRendering[i];

		for(int j = 0; j < (int)this->ActiveChunks.size(); j++) {

			this->ActiveChunks[j]->render();
		
			//Chunk* CurChunk = this->ActiveChunks[i];
			////if(CurPlayer->getX()/32.0f + radius > CurChunk->getX() && CurPlayer->getX()/32.0f - radius < CurChunk->getX() && CurPlayer->getY() / 32.0f - radius < CurChunk->getY() && CurPlayer->getY()/ 32.0f + radius > CurChunk->getY()) {
			////	(*CurChunk).render();
			////}
			//CurChunk->render();
		
		}

	}


}
