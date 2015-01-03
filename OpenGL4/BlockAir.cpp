#include "BlockAir.h"
#include <iostream>
#include "Boot.h"

BlockAir::BlockAir(int x, int y):Block(x,y){

	this->red = 119;
	this->green = 181;
	this->blue = 254;
	this->bBox = false;
	this->isTransparent = true;
	this->id = 1;

}
BlockAir::BlockAir():Block() {

}
BlockAir::~BlockAir() {
}

void BlockAir::render() {

	/*int wWidth =200;
	int wHeight = 200;
	//int wWidth = Boot::width;
	//int wHeight = Boot::height;

	glPushMatrix();
		
	glTranslatef(Boot::cameraX-wWidth/2, Boot::cameraY-wHeight/2, 0);

	glBegin(GL_LINES);
		glColor3ub(255,0,255);
		glVertex2i(0,0);
		glVertex2i(wWidth,0);

		glVertex2i(wWidth,0);
		glVertex2i(wWidth,wHeight);

		glVertex2i(wWidth, wHeight);
		glVertex2i(0, wHeight);

		glVertex2i(0, wHeight);
		glVertex2i(0,0);
	glEnd();*/
	this->renderBase();
	glPopMatrix();

	if(!this->mustRender()) {
		return;
	}
	//OutputDebugString("RENDER\n");
	//float colorIndice = this->getColorIndice();

	this->setRenderColor();
	//glColor4f(colorIndice*(this->red/255.0f), colorIndice*(this->green/255.0f), colorIndice*(this->blue/255.0f), 1.0f);
	//glColor3ub(this->red,this->green,this->blue);
	glPushMatrix();

	glTranslatef((float)this->x*this->size, (float)this->y*this->size, 0.0f);
	glBegin(GL_QUADS);

		glVertex2i(0, 0);
		glVertex2i(this->size, 0);
		glVertex2i(this->size, this->size);
		glVertex2i(0, this->size);

	glEnd();

	/*glBegin(GL_LINES);
		glColor3ub(0,255,0);
		glVertex2i(0,0);
		glVertex2i(this->size, 0);

		glVertex2i(this->size, 0);
		glVertex2i(this->size, this->size);

		glVertex2i(this->size, this->size);
		glVertex2i(0, this->size);

		glVertex2i(0, this->size);
		glVertex2i(0,0);
	glEnd();*/
	glPopMatrix();
}