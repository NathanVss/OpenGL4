#include "Light.h"

#include "World.h"

Light::Light(void)
{
	this->miniRadius = -1;
	this->radius = -1;
}


Light::~Light(void)
{
}


float Light::getColor(int x, int y) {
	return 1.0f;
}

float Light::getColorMiniRadius(int x, int y) {
	return 1.0f;
}

int Light::getRelX() {
	return this->relX;
}
int Light::getRelY() {
	return this->relY;
}
void Light::setRelX(int x) {
	this->relX = x;
}
void Light::setRelY(int y) {
	this->relY = y;
}
bool Light::getHasRadius() {
	if(this->radius > 0) {
		return true;
	}
	return false;
}
bool Light::getHasMiniRadius() {
	if(this->miniRadius > 0) {
		return true;
	}
	return false;
}
int Light::getMiniRadius() {
	return this->miniRadius;
}

int Light::getRadius() {
	return this->radius;
}

void Light::setX(int x) {
	this->x = x;
}
void Light::setY(int y) {
	this->y = y;
}

int Light::getX() {
	return this->x;

}
int Light::getY() {
	return this->y;
}

