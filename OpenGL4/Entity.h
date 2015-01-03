#ifndef DEF_ENTITY
#define DEF_ENTITY

#include "NRectangle.h"
#include <vector>
#include "Chunk.h"
#include <string>
#include "World.h"

class Entity
{
public:
	Entity(void);
	~Entity(void);
	bool hasBBox();	
	std::shared_ptr<NRectangle> getBoundingBox();
	void checkCollisions(World* wWorld, std::vector<Chunk*>*, int nextX, int nextY);

protected:
	int x;
	int y;

	float yVelocity;

	int height;
	int width;	
	bool bBox;
	int speed;
	std::shared_ptr<NRectangle> BoundingBox;
	bool collideOnLeft;
	bool collideOnRight;
	bool collideOnTop;
	bool collideOnBottom;
	bool collideOnTopLeft;
	bool collideOnTopRight;
	bool collideOnBottomLeft;
	bool collideOnBottomRight;
};

#endif