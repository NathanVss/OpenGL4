#pragma once

#include <utility>

class Vector2D
{
public:
	Vector2D(void);
	~Vector2D(void);
	void setBase(float, float);
	void setEnd(float, float);
	float getDistance();
	std::pair<float, float> getCoordFromRadius(int);	

private:
	float x;
	float y;
	float ex;
	float ey;
	float coeff;
	bool vertical;
	int b;
};

