#pragma once

#include "Renderer.h"
#include "Boot.h"
#include "Updatable.h"
#include "Light.h"



class CircleLight: public Renderer, public Updatable, public Light
{
public:
	CircleLight(void);
	~CircleLight(void);
	void render();
	virtual float getColor(int, int);
	virtual float getColorMiniRadius(int, int);
	void update();
	virtual std::string getType();

};

