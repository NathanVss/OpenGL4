#include "CircleLight.h"
#include <math.h>
#include "MovementsManager.h"
#include <memory>
#include "Block.h"
#include "World.h"

CircleLight::CircleLight(void):Light(){
	this->x = 0;
	this->y = 0;
	this->radius = 1000;
	this->miniRadius = 300;
}

std::string CircleLight::getType() {
	return std::string("circle");
}

float CircleLight::getColor(int x, int y) {

	double dist = (pow((this->x - x), 2) + pow((this->y - y), 2));
	if(dist < 0) {
		dist = -dist;
	}
	if(dist > this->radius*this->radius) {
		return 0.0;
	}
	return 1.0f*(1-(dist/(this->radius*this->radius)));

}

float CircleLight::getColorMiniRadius(int x, int y) {

	double dist = (pow((this->x - x), 2) + pow((this->y - y), 2));
	if(dist < 0) {
		dist = -dist;
	}
	if(dist > this->miniRadius*this->miniRadius) {
		return 0.0;
	}
	return 1.0f*(1-(dist/(this->miniRadius*this->miniRadius)));

}

void CircleLight::update() {
	//this->x+=4;
	//this->y++;
	//this->radius+=3;
}

void CircleLight::render() {
	glPushMatrix();

	glTranslatef(this->x, this->y, 0);

	glColor4f(1.0f,1.0f,1.0f, 1.0f);
	glBegin(GL_POINTS);

	for(int x=-this->radius+this->x;x<this->radius+this->x;x++) {
		for(int y= -this->radius+this->y;y<this->radius+this->y;y++) {
			double dist = sqrt(pow((this->x - x), 2) + pow((this->y - y), 2));
			glColor4f(1.0f,1.0f,1.0f,(float)(1.0f*(1-(dist/this->radius))));
			glVertex2i(x, y);
		}
	}

		

	glEnd();

	glPopMatrix();

	//this->x++;
}


CircleLight::~CircleLight(void)
{
}
