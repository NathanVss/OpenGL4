#ifndef DEF_SPRITESHEET
#define DEF_SPRITESHEET
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <SDL/SDL.h>

#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <cstdlib>
#include <string>
#include "TextureLoader.h"

class Spritesheet
{
public:
	Spritesheet();
	Spritesheet(char* path, float size, TextureLoader *pTextureLoader);
	~Spritesheet(void);
	void setPath(std::string path);
	std::string getPath();
	float getSize();
	void setSize(float size);
	GLuint getTextureId();
	void setCurSprite(int curX, int curY);

	void bind();
	void setTopLeftTexCoord();
	void setTopRightTexCoord();
	void setBottomLeftTexCoord();
	void setBottomRightTexCoord();


private:
	std::string path;
	float size;
	glTexture GlTexture;

	int curX;
	int curY;
};

#endif
