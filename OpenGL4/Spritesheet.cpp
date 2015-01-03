#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <SDL/SDL.h>

#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <cstdlib>

#include "Spritesheet.h"
#include <string>



Spritesheet::Spritesheet(char* path, float size, TextureLoader *pTextureLoader){

	this->path = path;
	this->size = size;
	(*pTextureLoader).LoadTextureFromDisk(path, &this->GlTexture);
	//this->textureId = loadTexture("textures/font.png");
}

Spritesheet::Spritesheet() {

}

void Spritesheet::bind() {
	glBindTexture(GL_TEXTURE_2D, this->GlTexture.TextureID);
}

void Spritesheet::setBottomLeftTexCoord() {
	glTexCoord2d(0+this->curX*(1.0f/this->size), 0+this->curY*(1.0f/this->size));
}

void Spritesheet::setBottomRightTexCoord() {
	glTexCoord2d(0+(this->curX+1)*(1.0f/this->size), 0+this->curY*(1.0f/this->size));
}

void Spritesheet::setTopLeftTexCoord() {
	glTexCoord2d(0+(this->curX)*(1.0f/this->size), 0+(this->curY+1)*(1.0f/this->size));
}

void Spritesheet::setTopRightTexCoord() {
	glTexCoord2d(0+(this->curX+1)*(1.0f/this->size), 0+(this->curY+1)*(1.0f/this->size));
}

void Spritesheet::setCurSprite(int curX, int curY) {
	this->curX = curX;
	this->curY = curY;
}


void Spritesheet::setPath(std::string path) {
	this->path = path;
}

std::string Spritesheet::getPath() {
	return this->path;
}

void Spritesheet::setSize(float size) {
	this->size = size;
}

float Spritesheet::getSize() {
	return this->size;
}

Spritesheet::~Spritesheet(void){
}
