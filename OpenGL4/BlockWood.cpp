#include "BlockWood.h"


BlockWood::BlockWood(int x, int y):Block(x,y){
	this->red = 73;
	this->green = 35;
	this->blue = 7;
	this->id = Block::WoodId;
}
BlockWood::BlockWood(): Block() {

}


BlockWood::~BlockWood(void)
{
}


Item* BlockWood::getItem() {
	return false;
}

void BlockWood::render() {
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

	glPopMatrix();

}