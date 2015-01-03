#include "LightNeon.h"
#include <Windows.h>
#include "Utils.h"
LightNeon::LightNeon(void):Light()
{
	this->direction = 2;
	this->width = 32*30;
	this->intensity = 1000;
}

float LightNeon::getColor(int x, int y) {


	float dist = pow((this->y - y ), 2) + pow((this->x - x), 2);
	//OutputDebugString((std::string("dist : ") + (double)dist + std::string("; inensity : ") + this->intensity*this->intensity).c_str());
	if(dist >= (this->intensity*this->intensity)) {
		
		return 0.0f;
	}

	return 1-dist/(this->intensity*this->intensity);
	
}

LightNeon::~LightNeon(void)
{
}

int LightNeon::getDirection() {
	return this->direction;
}
int LightNeon::getWidth() {
	return this->width;
}

std::string LightNeon::getType() {

	return std::string("neon");
}
