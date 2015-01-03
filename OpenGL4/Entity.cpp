#include "Entity.h"
#include "Chunk.h"
#include <vector>
#include "Block.h"
#include "NRectangle.h"
#include <iostream>
#include <utility>

#include "Boot.h"
#include "MovementsManager.h"
#include "World.h"

Entity::Entity(void) {
	this->collideOnBottom = false;
	this->collideOnLeft = false;
	this->collideOnRight = false;
	this->collideOnTop = false;
	this->yVelocity = 0;
}


Entity::~Entity(void)
{
}



void Entity::checkCollisions(World* wWorld, std::vector<Chunk*>* Chunks, int nextX, int nextY) {

	bool verticalToTopMov = false;
	bool verticalToBottomMov = false;
	bool transvToLeftMov = false;
	bool transvToRightMov = false;
	bool diagToTopRightMov = false;
	bool diagToTopLeftMov = false;
	bool diagToBottomLeftMov = false;
	bool diagToBottomRightMov = false;
	bool idleMov = false;



	bool canPass = false;
	//std::cout << "[" << this->x << ";" << this->y << "] to [" << nextX << ";" << nextY << "]" << std::endl;
	while(canPass == false) {
		verticalToTopMov = false;
		verticalToBottomMov = false;
		transvToLeftMov = false;
		transvToRightMov = false;
		diagToTopRightMov = false;
		diagToTopLeftMov = false;
		diagToBottomLeftMov = false;
		diagToBottomRightMov = false;
		idleMov = false;


		if(this->x > nextX && nextY < this->y) {
			diagToTopLeftMov = true;
		}
		if(this->x < nextX && this->y > nextY) {
			diagToTopRightMov = true;
		}
		if(this->x > nextX && nextY > this->y) {
			diagToBottomLeftMov = true;
		}
		if(this->x < nextX && nextY > this->y) {
			diagToBottomRightMov = true;
		}
		if(this->x == nextX && nextY > this->y) {
			verticalToBottomMov = true;
		}
		if(this->x == nextX && nextY < this->y) {
			verticalToTopMov = true;
		}
		if(nextY == this->y && this->x < nextX) {
			transvToRightMov = true;
		}
		if(nextY == this->y && this->x > nextX) {
			transvToLeftMov = true;
		}
		if(nextY == this->y && this->x == nextX) {
			idleMov = true;
		}

		if(diagToBottomLeftMov && this->collideOnBottom) {
			nextY = this->y;
		} else if(diagToBottomRightMov && this->collideOnBottom) {
			nextY = this->y;
		} else if(diagToTopLeftMov && this->collideOnTop) {
			nextY = this->y;
		} else if(diagToTopRightMov && this->collideOnTop) {
			nextY = this->y;
		} else if (diagToBottomLeftMov && this->collideOnLeft) {
			nextX = this->x;
		} else if (diagToBottomRightMov && this->collideOnRight) {
			nextX = this->x;
		} else if (diagToTopRightMov && this->collideOnRight) {
			nextX = this->x;
		} else if (diagToTopLeftMov && this->collideOnLeft) {
			nextX = this->x;
		} else {
			canPass = true;
		}
	}
	/*
	if(verticalToTopMov) {
		std::cout << " VERT TO TOP " << std::endl;
	}
	if(verticalToBottomMov) {
		std::cout << " VERT TO BOTTOM " << std::endl;
	}
	if(transvToLeftMov) {
		std::cout << " TRANSV TO LEFT " << std::endl;
	}
	if(transvToRightMov) {
		std::cout << " TRANSV TO RIGHT " << std::endl;
	}
	if(diagToTopRightMov) {
		std::cout << " DIAG TO TOP RIGHT " << std::endl;
	}
	if(diagToTopLeftMov) {
		std::cout << " DIAG TO TOP LEFT " << std::endl;
	}
	if(diagToBottomLeftMov) {
		std::cout << " DIAG TO BOTTOM LEFT " << std::endl;
	}
	if(diagToBottomRightMov) {
		std::cout << " DIAG TO BOTTOM RIGHT " << std::endl;
	}
	if(idleMov) {
		std::cout << " IDLE MOV " << std::endl;
	}
	std::cout << "[" << this->x << ";" << this->y << "] to [" << nextX << ";" << nextY << "]" << std::endl;*/


	std::vector<std::pair<int, int>> orderer = MovementsManager::getTrajCoords(this->x, this->y, nextX, nextY);
	//std::vector<std::pair<int, int>> orderer = this->getOrderers(nextX, nextY);
	if(orderer.size() == 0) {
		return;
	}

	std::vector<Block*> blocksToCompair;
	for(int i=0; i<orderer.size(); i++) {
		std::pair<int, int> couple = orderer[i];

		if(i==0) {
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first-32)/32.0f), floor((couple.second)/32.0f)));
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first-32)/32.0f), floor((couple.second+1*32)/32.0f)));
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first-32)/32.0f), floor((couple.second-1*32)/32.0f)));
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first-32)/32.0f), floor((couple.second-2*32)/32.0f)));
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first-32)/32.0f), floor((couple.second+2*32)/32.0f)));
		}
		if(i==orderer.size() - 1) {
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first+32)/32.0f), floor((couple.second)/32.0f)));
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first+32)/32.0f), floor((couple.second+1*32)/32.0f)));
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first+32)/32.0f), floor((couple.second-1*32)/32.0f)));
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first+32)/32.0f), floor((couple.second-2*32)/32.0f)));
			blocksToCompair.push_back((*wWorld).getBlock(floor((couple.first+32)/32.0f), floor((couple.second+2*32)/32.0f)));
		}

		
		blocksToCompair.push_back((*wWorld).getBlock(floor(couple.first/32.0f), floor(couple.second/32.0f)));

		blocksToCompair.push_back((*wWorld).getBlock(floor(couple.first/32.0f), floor((couple.second-1*32)/32.0f)));
		blocksToCompair.push_back((*wWorld).getBlock(floor(couple.first/32.0f), floor((couple.second+1*32)/32.0f)));

		blocksToCompair.push_back((*wWorld).getBlock(floor(couple.first/32.0f), floor((couple.second-2*32)/32.0f)));
		blocksToCompair.push_back((*wWorld).getBlock(floor(couple.first/32.0f), floor((couple.second+2*32)/32.0f)));

		blocksToCompair.push_back((*wWorld).getBlock(floor(couple.first/32.0f), floor((couple.second-3*32)/32.0f)));
		blocksToCompair.push_back((*wWorld).getBlock(floor(couple.first/32.0f), floor((couple.second+3*32)/32.0f)));
	}

	for(int i=0; i<blocksToCompair.size();i++) {
		Block* CurBlock = blocksToCompair[i];
		if(!CurBlock) {
			continue;
		}
		//CurBlock->setRed(255);
	}


	this->collideOnRight = false;
	this->collideOnTop = false;
	this->collideOnBottom = false;
	this->collideOnLeft = false;
	this->collideOnTopLeft = false;
	this->collideOnTopRight = false;
	this->collideOnBottomLeft = false;
	this->collideOnBottomRight = false;

	std::vector<NRectangle*> rects;
	for(int iOrd = 0; iOrd<orderer.size(); iOrd++) {
		std::pair<int, int> couple = orderer[iOrd];

		this->BoundingBox->changePos(couple.first-this->width/2, couple.second-this->height/2);

		for(int b=0;b<blocksToCompair.size();b++) {
			
			Boot::blocksIndex += 1;
			Block* CurBlock = blocksToCompair[b];

			if(!CurBlock) {
				continue;
			}
			if((*CurBlock).hasBBox()) {

				NRectangle* CurBoundingBox = CurBlock->getBoundingBox();

				/* 
				[ ME ]
				[ BLOCK ]
				*/
				if(this->BoundingBox->doesCollideTopOf(CurBoundingBox)) {
					this->collideOnBottom = true;
					rects.push_back(CurBoundingBox);
					//std::cout << "----BOTTOM" << std::endl;
					//std::cout << "BOTTOM" << std::endl;
				}

				/*
				[ BLOCK ]
				[ ME ]
				*/
				if(this->BoundingBox->doesCollideBottomOf(CurBoundingBox)) {
					this->collideOnTop = true;
					//std::cout << "TOP" << std::endl;
				}

				/*
				[ BLOCK ][ ME ]
				*/
				if(this->BoundingBox->doesCollideRightOf(CurBoundingBox)) {
					this->collideOnLeft = true;
						
					//std::cout << "LEFT" << std::endl;
				}

				/*
				[ ME ][ BLOCK ]
				*/
				if(this->BoundingBox->doesCollideLeftOf(CurBoundingBox)) {
					this->collideOnRight = true;
					//std::cout << "RIGHT" << std::endl
						
				}

				/*
				[ ME ] <-
						[ BLOCK ]
				*/
				if(this->BoundingBox->doesCollideTopLeftOf(CurBoundingBox)) {
					this->collideOnBottomRight = true;
				}

				/*
							[ ME ] <-
				[ BLOCK ]
				*/
				if(this->BoundingBox->doesCollideTopRightOf(CurBoundingBox)) {
					this->collideOnBottomLeft = true;
				}

				/*
						[ BLOCK ]
				[ ME ] <-
				*/
				if(this->BoundingBox->doesCollideBottomLeftOf(CurBoundingBox)) {
					this->collideOnTopRight = true;
				}
					
				/*
				[ BLOCK ]
							[ ME ] <-
				*/
				if(this->BoundingBox->doesCollideBottomRightOf(CurBoundingBox)) {
					this->collideOnTopLeft = true;
				}

			}
		}

		if(transvToLeftMov && this->collideOnLeft){
			this->x = couple.first;
			this->y = couple.second;
			return;
		}
		if(transvToRightMov && this->collideOnRight){
			this->x = couple.first;
			this->y = couple.second;
			return;
		}
		if(verticalToBottomMov && this->collideOnBottom) {
			this->x = couple.first;
			this->y = couple.second;
			return;
		}
		if(verticalToTopMov && this->collideOnTop) {
			this->x = couple.first;
			this->y = couple.second;
			return;
		}
		if(diagToTopLeftMov && (this->collideOnLeft || this->collideOnTop || this->collideOnTopLeft)) {
			this->x = couple.first;
			this->y = couple.second;
			return;
		}
		if(diagToTopRightMov && (this->collideOnRight || this->collideOnTop || this->collideOnTopRight)) {
			this->x = couple.first;
			this->y = couple.second;
			return;
		}
		if(diagToBottomLeftMov && (this->collideOnLeft || this->collideOnBottom || this->collideOnBottomLeft)) {
			this->x = couple.first;
			this->y = couple.second;
			return;
		}
		if(diagToBottomRightMov && (this->collideOnRight || this->collideOnBottom || this->collideOnBottomRight)) {
			this->x = couple.first;
			this->y = couple.second;
			return;
		}
	}

	std::pair<int, int> finalCouple = orderer[orderer.size()-1];

	this->x = finalCouple.first;
	this->y = finalCouple.second;
}

std::shared_ptr<NRectangle> Entity::getBoundingBox() {
	return this->BoundingBox;
}

bool Entity::hasBBox() {
	return this->bBox;
}