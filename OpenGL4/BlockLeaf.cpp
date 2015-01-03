#include "BlockLeaf.h"


BlockLeaf::BlockLeaf(int x, int y):Block(x,y){
	this->red = 20;
	this->green = 60;
	this->blue = 10;
	this->id = Block::LeafId;
}
BlockLeaf::BlockLeaf() : Block() {

}


BlockLeaf::~BlockLeaf(void)
{
}


Item* BlockLeaf::getItem() {
	return false;
}

void BlockLeaf::render() {
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