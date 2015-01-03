#ifndef DEF_CAMERA
#define DEF_CAMERA
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <SDL/SDL.h>
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#include "Keyboard.h"
#include "Player.h"
#include "FontRenderer.h"
#include "Boot.h"
#include "Renderer.h"
#include "Updatable.h"

class Camera: public Renderer, public Updatable
{
public:
	Camera(void);
	void focus(int x, int y);
	void realFocus();
	void resetPos();
	virtual void update();
	virtual void render();
	void setFontRenderer(FontRenderer*);
	FontRenderer* fFontRenderer;

	static int getCurX();
	static int getCurY();

	static int curX;
	static int curY;
};

#endif