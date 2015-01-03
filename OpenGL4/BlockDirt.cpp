#include "BlockDirt.h"


BlockDirt::BlockDirt() :Block() {

}
BlockDirt::BlockDirt(int x, int y):Block(x,y){
	this->red = 147;
	this->green = 48;
	this->blue = 0;
	this->id = 2;
}
BlockDirt::~BlockDirt() {

}

void BlockDirt::render() {
	this->renderBase();

	if(!this->mustRender()) {
		return;
	}
	this->setRenderColor();
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