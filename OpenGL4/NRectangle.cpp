#include "NRectangle.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include <windows.h>
#include <GL/GL.h>
#include <iostream>
#include <GL/GLU.h>

NRectangle::NRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->x4 = x4;
	this->y4 = y4;

	this->red = 0;
	this->green = 255;
	this->blue = 0;
}

void NRectangle::changePos(int x1, int y1) {
	this->x1 = x1;
	this->y1 = y1;
}

void NRectangle::setColor(int red, int green,int blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

NRectangle::NRectangle(int x1, int y1, int width, int height) {
	this->x1 = x1;
	this->y1 = y1;
	this->width = width;
	this->height = height;

	this->red = 0;
	this->green = 255;
	this->blue = 0;
}

void NRectangle::render() {
	glPopMatrix();

	
	glPushMatrix();

	glTranslatef((float)this->x1, (float)this->y1, 0.0f);
	glBegin(GL_QUADS);

		glColor3ub(this->red, this->green, this->blue);
		glVertex2i(0, 0);
		glVertex2i(width, 0);
		glVertex2i(width, height);
		glVertex2i(0, height);

	glEnd();

	glPopMatrix();
}

int NRectangle::getHeight() {
	return this->height;
}

int NRectangle::getWidth() {
	return this->width;
}

/*
[ RECT 1 ]
		  [ RECT 2 ]
*/
bool NRectangle::doesCollideTopLeftOf(NRectangle* Rect2) {
	if(this->x1 + this->width == Rect2->getX1() && this->y1 + this->height == Rect2->getY1()) {
		return true;
	}
	return false;
}


/*
[ RECT 2 ]
		  [ RECT 1 ]
*/
bool NRectangle::doesCollideBottomRightOf(NRectangle* Rect2) {
	if(Rect2->getX1() + Rect2->getWidth() == this->x1 && Rect2->getY1() + Rect2->getHeight() == this->y1) {
		return true;
	}
	return false;
}

/*
		  [ RECT 2 ]
[ RECT 1 ]
*/
bool NRectangle::doesCollideBottomLeftOf(NRectangle* Rect2) {
	if(Rect2->getX1() == this->x1 + this->width && this->y1 == Rect2->getY1() + Rect2->getHeight()) {
		return true;
	}
	return false;
}

/*
		  [ RECT 1 ]
[ RECT 2 ]

*/
bool NRectangle::doesCollideTopRightOf(NRectangle* Rect2)  {

	if(Rect2->getX1() + Rect2->getWidth() == this->x1 && Rect2->getY1() == this->y1 + this->height) {
		return true;
	}

	return false;
}

/*

[ RECT 2 ][ RECT 1 ]

*/
bool NRectangle::doesCollideRightOf(NRectangle* Rect2) {
	if(Rect2->getX1() + Rect2->getWidth() == this->x1) {

		if((this->y1 > Rect2->getY1() && this->y1 < Rect2->getY1() + Rect2->getHeight()) || 
			(this->y1 + this->height > Rect2->getY1() && this->y1 + this->height < Rect2->getY1() + Rect2->getHeight()) || 
			(Rect2->getY1() > this->y1 && Rect2->getY1() < this->y1 + this->height) || 
			(Rect2->getY1() + Rect2->getHeight() > this->y1 && Rect2->getY1() + Rect2->getHeight() < this->y1 + this->height) ||
			(this->y1 == Rect2->getY1() && this->y1 + this->height == Rect2->getY1() + Rect2->getHeight())) {
			//std::cout << " TOUCH RIGHT " << std::endl;
			return true;
		}

	}

	return false;
}

/*

[ RECT 1 ][ RECT 2 ]

*/
bool NRectangle::doesCollideLeftOf(NRectangle* Rect2) {

	if(this->x1 + this->width == Rect2->getX1()) {
		if((this->y1 > Rect2->getY1() && this->y1 < Rect2->getY1() + Rect2->getHeight()) || 
			(this->y1 + this->height > Rect2->getY1() && this->y1 + this->height < Rect2->getY1() + Rect2->getHeight()) || 
			(Rect2->getY1() > this->y1 && Rect2->getY1() < this->y1 + this->height) || 
			(Rect2->getY1() + Rect2->getHeight() > this->y1 && Rect2->getY1() + Rect2->getHeight() < this->y1 + this->height) ||
			(this->y1 == Rect2->getY1() && this->y1 + this->height == Rect2->getY1() + Rect2->getHeight())) {
			//std::cout << " TOUCH LEFT " << std::endl;
			return true;
		}

	}

	return false;
}

/*

[ RECT 2]
[ RECT 1]

*/
bool NRectangle::doesCollideBottomOf(NRectangle* Rect2) {
	if(Rect2->getY1()+Rect2->getHeight() == this->y1  ) {

		if ((Rect2->getX1() > this->x1 && Rect2->getX1() < this->x1 + this->width) || 
			(Rect2->getX1() + Rect2->getWidth() > this->x1 && Rect2->getX1() + Rect2->getWidth() < this->x1 + this->width) ||
			(this->x1 > Rect2->getX1() && this->x1 < Rect2->getX1() + Rect2->getWidth()) || 
			(this->x1 + this->width > Rect2->getX1() && this->x1 + this->width < Rect2->getX1() + Rect2->getWidth()) ||
			(this->x1 == Rect2->getX1() && this->x1 + this->width == Rect2->getX1() + Rect2->getWidth())) {

		//std::cout << "TOUCH BOTTOM" << std::endl;
		return true;
		}
	}
	return false;
}

/*

[ RECT 1]
[ RECT 2]

*/
bool NRectangle::doesCollideTopOf(NRectangle* Rect2) {

	if(this->y1 + this->height == Rect2->getY1()) {
		if ((Rect2->getX1() > this->x1 && Rect2->getX1() < this->x1 + this->width) || 
			(Rect2->getX1() + Rect2->getWidth() > this->x1 && Rect2->getX1() + Rect2->getWidth() < this->x1 + this->width) ||
			(this->x1 > Rect2->getX1() && this->x1 < Rect2->getX1() + Rect2->getWidth()) || 
			(this->x1 + this->width > Rect2->getX1() && this->x1 + this->width < Rect2->getX1() + Rect2->getWidth()) ||
			(this->x1 == Rect2->getX1() && this->x1 + this->width == Rect2->getX1() + Rect2->getWidth())) {

		//std::cout << "TOUCH TOP" << std::endl;
		return true;
		}
	}
	return false;
}

int NRectangle::getX1() {
	return this->x1;
}
int NRectangle::getX4() {
	return this->x4;
}
int NRectangle::getX3() {
	return this->x3;
}
int NRectangle::getX2() {
	return this->x2;
}
int NRectangle::getY1() {
	return this->y1;
}
int NRectangle::getY2() {
	return this->y2;
}

int NRectangle::getY3() {
	return this->y3;
}

int NRectangle::getY4() {
	return this->y4;
}


NRectangle::~NRectangle(void)
{
}
