#ifndef DEF_FONTRENDERER
#define DEF_FONTRENDERER

#include <string>
#include "TextureLoader.h"
#include "Spritesheet.h"


class FontRenderer
{
public:
	//FontRenderer(Spritesheet FontSpritesheet);
	FontRenderer(void);
	~FontRenderer(void);
	void setFontSpriteSheet(Spritesheet* FontSpriteSheet);
	void renderText(const char* text, int x, int y, int size);
	void renderText(const char* text, int x, int y, int size, float opacity);

	static void srenderText(const char* text, int x, int y, int size);
	static Spritesheet* fFontSpritesheet;
	static int letterSize;

private:
	Spritesheet* FontSpritesheet;
	
};

#endif
