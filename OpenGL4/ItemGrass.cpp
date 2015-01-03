#include "ItemGrass.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <SDL/SDL.h>

ItemGrass::ItemGrass(void):ItemBlock() {
	this->id = 1;
	this->placeable = true;
}


ItemGrass::~ItemGrass(void) {
}

Block* ItemGrass::getNewBlock(int x, int y) {
	return new BlockGrass(x, y);
}

void ItemGrass::render(int x, int y) {
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x,y,0);
	glColor3ub(0,113,0);
	glBegin(GL_QUADS);
		glVertex2i(0,0);
		glVertex2i(50,0);
		glVertex2i(50,50);
		glVertex2i(0,50);
	glEnd();
	glPopMatrix();
}
