#ifndef DEF_PLAYER
#define DEF_PLAYER
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <SDL/SDL.h>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "Entity.h"
#include "Keyboard.h"
#include "Chunk.h"

#include "RapidInventory.h"
#include "PlayerInventory.h"
#include "Renderer.h"
#include "Keyboard.h"
#include "ItemGrass.h"
#include "Mouse.h"
#include "BlockAir.h"
#include "BlockStone.h"
#include "Item.h"
#include "Keyboard.h"

#include "Updatable.h"

// Forward Declaration
#include "World.h"

class Player : public Entity, public Renderer, public Updatable
{
public:
	Player(void);
	~Player(void);

	int getX();
	int getY();

	void setWorld(World*);
	void setRapidInventory(RapidInventory*);
	void setPlayerInventory(PlayerInventory*);
	void setKeyboard(Keyboard*);

	void teleport(int x, int y);
	virtual void render();
	virtual void update();

	void setGodMode(bool);
	bool getIsGodMode();

	void setName(std::string);
	std::string getName();

protected:
	bool isJumping;
	int jumpingState;
	int jumpQuantity;
	float jumpDivider;
	float gravity;
	bool isGodMode;
	std::string name;

	World *wWorld;
	Keyboard* kKeyboard;
	RapidInventory* rRapidInventory;
	PlayerInventory* pPlayerInventory;

};

#endif