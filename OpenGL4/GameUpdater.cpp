#include "GameUpdater.h"

std::vector<Updatable*> GameUpdater::Updatables;

GameUpdater::GameUpdater(void)
{
}


GameUpdater::~GameUpdater(void)
{
}

void GameUpdater::update() {
	Mouse::update();

	for(int i = 0; i<GameUpdater::Updatables.size();i++) {
		GameUpdater::Updatables[i]->update();
	}
}

void GameUpdater::addUpdatable(Updatable* uUpdatable) {
	GameUpdater::Updatables.push_back(uUpdatable);
}
