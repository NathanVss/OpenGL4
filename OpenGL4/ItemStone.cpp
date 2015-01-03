#include "ItemStone.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <SDL/SDL.h>

ItemStone::ItemStone(void)
{
}


ItemStone::~ItemStone(void)
{
}

void ItemStone::render(int x, int y) {
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x,y,0);
	glColor3ub(121,121,121);
	glBegin(GL_QUADS);
		glVertex2i(0,0);
		glVertex2i(50,0);
		glVertex2i(50,50);
		glVertex2i(0,50);
	glEnd();
	glPopMatrix();
}
