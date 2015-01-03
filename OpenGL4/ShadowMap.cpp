#include "ShadowMap.h"


ShadowMap::ShadowMap(int w, int h){
	this->width =w;
	this->height = h;
	unsigned char** ary = new unsigned char*[w];
	for(int i = 0; i<w; i++) {
		ary[i] = new unsigned char[h];
	}
	this->scale = ary;

}

int ShadowMap::getWidth() {
	return this->width;
}
int ShadowMap::getHeight() {
	return this->height;
}

bool ShadowMap::setScale(int x, int y, int s) {
	if(x > this->width - 1 || x < 0) {
		return false;
	}
	if(y > this->height - 1 || y < 0) {
		return false;
	}
	this->scale[x][y] =s;
	return true;
}
unsigned char*** ShadowMap::getScale() {
	return &this->scale;
}

int ShadowMap::getScale(int x, int y) {
	if(x > this->width-1 || x < 0) {
		return -1;
	}
	if(y > this->height-1 || y < 0) {
		return -1;
	}
	return this->scale[x][y];
}


ShadowMap::~ShadowMap(void)
{
	//this->width = 0;
	//this->height = 0;
	for(int w=0; w <this->width; w++) {
		if(this->scale[w]) {
			delete this->scale[w];

		}
	}
	delete this->scale;
}
