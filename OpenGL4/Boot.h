
#ifndef DEF_BOOT
#define DEF_BOOT

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <SDL/SDL.h>
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
//#include <cstdlib>
#include "FontRenderer.h"


class Boot {
	public:
		Boot();
		static int width;
		static int height;
		static int cameraX;
		static int cameraY;
		static int blocksIndex;
		static int mouseX;
		static int mouseY;

	private:

		void mainLoop();
		void initOpenGL();
		void draw();
};

#endif