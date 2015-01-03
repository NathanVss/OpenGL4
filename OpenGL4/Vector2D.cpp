#include "Vector2D.h"
#include <windows.h>
#include <string>
#include "Boot.h"
Vector2D::Vector2D(void)
{
	this->vertical = false;
}


Vector2D::~Vector2D(void)
{
}

void Vector2D::setBase(float x,float y) {
	this->x = x;
	this->y = y;
}
void Vector2D::setEnd(float x,float y) {
	this->ex = x;
	this->ey = y;
	if(this->x == this->ex) {
		this->vertical = true;
	} else {
		//float divizor = ( this->ex - this->x);
		//if(divizor == 0) {
		//	divizor = 1;
		//}
		//this->coeff = (this->ey - this->y) / divizor;
		//this->b = this->ey - this->ex * this->coeff;
	}

}

float Vector2D::getDistance() {
	return sqrt(pow((this->ex - this->x),2) + pow(( this->ey - this->y),2));
}

std::pair<float, float> Vector2D::getCoordFromRadius(int radius) {

	//std::pair<int, int> coordss;
	//coordss.first = 0;
	//coordss.second = 0;
	//return coordss;
	//
	float dist = pow((this->ex - this->x),2) + pow(( this->ey - this->y),2);
	dist = sqrt(dist);
	

	float baseDX = this->ex - this->x;
	float baseDY = this->ey - this->y;

	float unitDX = (baseDX / dist);
	float unitDY = (baseDY / dist);

	float newDX = unitDX*radius;
	float newDY = unitDY*radius;

	//std::pair<int, int> coordss;
	//coordss.first = 1;
	//coordss.second = 1;
	//return coordss;

	std::pair<float, float> coords;
	coords.first = this->x + newDX;
	coords.second = this->y + newDY;
	return coords;

}

