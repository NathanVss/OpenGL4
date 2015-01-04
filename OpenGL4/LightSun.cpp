#include "LightSun.h"


LightSun::LightSun(void)
{
	this->seconds = 0;
}


LightSun::~LightSun(void)
{
}

void LightSun::setSeconds(int s) {
	if(s >= 24*3600) {
		s = s%(24*3600); 
	}
	this->seconds = s;
}

int LightSun::getSeconds() {
	return this->seconds;
}

float LightSun::getIndice() {
	if(seconds >= 6*3600 && seconds <= 9*3600) {
		return 0.5f;
	} else if(seconds >= 22*3600 && seconds <= 24 * 3600) {
		return 0.3f;
	} else if(seconds > 0 && seconds < 6*3600) {
		return 0.05f;
	} else if(seconds > 9*3600 && seconds < 22*3600) {
		return 1.0f;
	}
}