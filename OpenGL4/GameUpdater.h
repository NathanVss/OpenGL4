#ifndef DEF_GAMUPDATER
#define DEF_GAMEUDATER
#pragma once

#include <vector>
#include "Updatable.h"
#include "Mouse.h"

class GameUpdater: public Updatable
{
public:
	GameUpdater(void);
	~GameUpdater(void);

	static void update();
	static void addUpdatable(Updatable*);
	static std::vector<Updatable*> Updatables;
};

#endif