#pragma once

#include "Object.h"
#include <string>

class World;

class Light : public Object
{
public:
	Light(void);
	~Light(void);
	virtual float getColor(int x, int y);
	virtual float getColorMiniRadius(int, int);
	virtual void setX(int);
	virtual void setY(int);
	virtual int getX();
	virtual int getY();

	virtual void setRelX(int);
	virtual void setRelY(int);

	virtual int getRelX();
	virtual int getRelY();
	virtual int getRadius();
	virtual bool getHasRadius();
	virtual bool getHasMiniRadius();
	virtual int getMiniRadius();

	virtual std::string getType() = 0;
protected:
	int x;
	int radius;
	int y;
	int relX;
	int relY;
	int miniRadius;
};

