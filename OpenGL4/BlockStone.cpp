#include "BlockStone.h"


BlockStone::BlockStone(int x, int y):Block(x,y){
	this->red = 121;
	this->green = 121;
	this->blue = 121;
	this->id = Block::StoneId;
}
BlockStone::BlockStone() :Block() {

}
BlockStone::~BlockStone() {
}

Item* BlockStone::getItem() {
	return new ItemStone();
}

void BlockStone::render() {
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