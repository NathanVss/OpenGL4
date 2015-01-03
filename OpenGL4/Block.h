#ifndef DEF_BLOCK
#define DEF_BLOCK
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <SDL/SDL.h>

#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <cstdlib>
#include <memory>

#include "Spritesheet.h"
#include "Item.h"
#include "NRectangle.h"
#include "CircleLight.h"
#include "Lightable.h"
#include "Object.h"

class Chunk;

class Block : public Object
{
protected:
	int x;
	int y;
	int texX;
	int texY;
	int size;
	int red;
	int green;
	int blue;
	int id;
	bool isObstrued;
	float lightIndice;
	int lightIndiceTicks;
	bool isTransparent;
	bool mustLightUpdate;
	bool bBox;
	NRectangle* BoundingBox;
	Chunk* ParentChunk;

	float getColorIndice();
	void setRenderColor();
	bool mustRender();
	
	

public:
	virtual bool getIsObstrued();
	virtual bool getIsTransparent();
	Block(int x, int y);
	Block();

	virtual void setParentChunk(Chunk*);
	virtual ~Block();
	virtual Item* getItem();
	void setX();
	void setY();
	void setRed(int red);
	int getX();
	int getY();
	NRectangle* getBoundingBox();
	virtual void renderBase();
	virtual void render() = 0;
	bool hasBBox();
	static int AirId;
	static int DirtId;
	static int GrassId;
	static int StoneId;
	static int LeafId;
	static int WoodId;
	virtual int getId();
	virtual float getLightIndice();
	virtual void setLightIndice(float);
};

#endif
