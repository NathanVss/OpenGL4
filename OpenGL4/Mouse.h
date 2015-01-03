#ifndef DEF_MOUSE
#define DEF_MOUSE

#include <SDL\SDL.h>
#include <iostream>

#include "Utils.h"
#include "FontRenderer.h"
#include "Camera.h"
#include "Boot.h"

class Mouse{

public:
	Mouse(void);
	~Mouse(void);
	static void checkInputs(SDL_Event *SdlEvent);
	static void update();
	static bool leftClick;
	static bool rightClick;
	static int relX;
	static int relY;
	static int wX;
	static int wY;
	static FontRenderer* fFontRenderer;
	static void render();
	static void setFontRenderer(FontRenderer*);
	

};


#endif
