#include "MovementsManager.h"


MovementsManager::MovementsManager(void)
{
}


MovementsManager::~MovementsManager(void)
{
}

std::vector<std::pair<int, int>> MovementsManager::getTrajCoordsSimple(int startX, int startY, int endX, int endY) {
	std::vector<std::pair<int, int>> orderer;
	if( endX != startX) {
		float divizor = (endX - startX);
		if(divizor == 0) {
			divizor = 1;
		}
		float coefDir = (endY - startY) / divizor;
		float b = endY - endX * coefDir;
		
		int lastY = 0;

		if(startX < endX) {
			for(int curX = startX;curX <= endX;curX+=32) {
				int ordY = coefDir*curX + b;

				if(curX == startX) {
					lastY = ordY;
				}

				std::pair<int, int> couple(curX, ordY);
				orderer.push_back(couple);
				lastY = ordY;
			}
		} else {
			for(int curX = startX; curX >= endX; curX-=32) {
				int ordY = coefDir*curX + b;

				if(curX == startX) {
					lastY = ordY;
				}

				std::pair<int, int> couple(curX, ordY);
				orderer.push_back(couple);
				lastY = ordY;
			}
		}

	} else {
		if(startY != endY) {
			
		
			if(startY < endY) {
				for(int vertY = startY; vertY <= endY;vertY+=32) {
					std::pair<int, int> couple(startX, vertY);
					orderer.push_back(couple);
				}
			} else {
				for(int vertY = startY; vertY >= endY; vertY-=32) {
					std::pair<int, int> couple(startX, vertY);
					orderer.push_back(couple);
				}
			}

		}
	}
	return orderer;
}

std::vector<std::pair<int, int>> MovementsManager::getTrajCoords(int startX, int startY, int endX, int endY) {

	std::vector<std::pair<int, int>> orderer;
	if( endX != startX) {
		float divizor = (endX - startX);
		if(divizor == 0) {
			divizor = 1;
		}
		float coefDir = (endY - startY) / divizor;
		float b = endY - endX * coefDir;
		
		int lastY = 0;

		if(startX < endX) {
			for(int curX = startX;curX <= endX;curX++) {
				int ordY = coefDir*curX + b;

				if(curX == startX) {
					lastY = ordY;
				}

				if(ordY - lastY > 1 || ordY - lastY < -1) {
					if(ordY < lastY) {
						for(int vertY = lastY;vertY > ordY;vertY--) {
							std::pair<int, int> couple(curX, vertY);
							orderer.push_back(couple);
						}
					} else {
						for(int vertY = lastY;vertY < ordY;vertY++) {
							std::pair<int, int> couple(curX, vertY);
							orderer.push_back(couple);
						}
					}
				}
				std::pair<int, int> couple(curX, ordY);
				orderer.push_back(couple);
				lastY = ordY;
			}
		} else {
			for(int curX = startX; curX >= endX; curX--) {
				int ordY = coefDir*curX + b;

				if(curX == startX) {
					lastY = ordY;
				}

				if(ordY - lastY > 1 || ordY - lastY < -1) {
					if(ordY < lastY) {
						for(int vertY = lastY;vertY > ordY;vertY--) {
							std::pair<int, int> couple(curX, vertY);
							orderer.push_back(couple);
						}
					} else {
						for(int vertY = lastY;vertY < ordY;vertY++) {
							std::pair<int, int> couple(curX, vertY);
							orderer.push_back(couple);
						}
					}
				}

				std::pair<int, int> couple(curX, ordY);
				orderer.push_back(couple);
				lastY = ordY;
			}
		}

	} else {
		if(startY != endY) {
			
			
			//std::cout << "VERTICAL MOVE : " << startY << " TO " << endY << std::endl;
			if(startY < endY) {
				for(int vertY = startY; vertY <= endY;vertY++) {
					std::pair<int, int> couple(startX, vertY);
					orderer.push_back(couple);
				}
			} else {
				for(int vertY = startY; vertY >= endY; vertY--) {
					std::pair<int, int> couple(startX, vertY);
					orderer.push_back(couple);
				}
			}

		}
	}
	return orderer;
}