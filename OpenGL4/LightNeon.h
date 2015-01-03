#pragma once

#include "Light.h"

class LightNeon: public Light
{
public:
	LightNeon(void);
	~LightNeon(void);
	std::string getType();
	int getDirection();
	int getWidth();
	int getIntensity();
	float getColor(int x, int y);

private:
	// 0 : top | 1 : right | 2 : bottom | 3 : left
	int direction;
	int width;
	int intensity;
};

