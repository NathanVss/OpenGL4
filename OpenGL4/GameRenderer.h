#ifndef DEF_GAMERENDERER
#define DEF_GAMERENDERER
#pragma once

#include "Renderer.h"
#include <vector>
#include "Mouse.h"

class GameRenderer : public Renderer
{
public:
	GameRenderer(void);
	~GameRenderer(void);
	static void render();
	static void addRenderer(Renderer* rRenderer);
	static void clear();

	static std::vector<Renderer*> Renderers;
};

#endif

