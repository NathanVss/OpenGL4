#include "FontRenderer.h"
#include <iostream>
#include "TextureLoader.h"
#include <string>
#include "Spritesheet.h"

int FontRenderer::letterSize = 8;

Spritesheet* FontRenderer::fFontSpritesheet = new Spritesheet();
/*FontRenderer::FontRenderer(Spritesheet FontSpritesheet){
	this->FontSpritesheet = FontSpritesheet;
}*/

FontRenderer::FontRenderer() {

}

void FontRenderer::setFontSpriteSheet(Spritesheet* FontSpritesheet) {
	this->FontSpritesheet = FontSpritesheet;
}

FontRenderer::~FontRenderer(void) {

}

void FontRenderer::srenderText(const char* text, int x, int y, int size) {
	int lenght= strlen(text);
	int letterWidth = 8*size;


	glPushMatrix();

	glLoadIdentity();
	glTranslatef(x, y, 0);

	
		
	//glColor4f(1.0f,0.0f,0.0f,0.5f);
	glColor3ub(255,255,255);
	glEnable(GL_TEXTURE_2D); 
	
	
	FontRenderer::fFontSpritesheet->bind();
	for(int i=0;i<lenght;i++) {

		if(text[i] == 'A') {
			FontRenderer::fFontSpritesheet->setCurSprite(0, 7);
		} else if(text[i] == 'B') {
			FontRenderer::fFontSpritesheet->setCurSprite(1, 7);
		} else if(text[i] == 'C') {
			FontRenderer::fFontSpritesheet->setCurSprite(2, 7);
		} else if(text[i] == 'D') {
			FontRenderer::fFontSpritesheet->setCurSprite(3, 7);
		} else if(text[i] == 'E') {
			FontRenderer::fFontSpritesheet->setCurSprite(4, 7);
		} else if(text[i] == 'F') {
			FontRenderer::fFontSpritesheet->setCurSprite(5, 7);
		} else if(text[i] == 'G') {
			FontRenderer::fFontSpritesheet->setCurSprite(6, 7);
		} else if(text[i] == 'H') {
			FontRenderer::fFontSpritesheet->setCurSprite(7, 7);
		} else if(text[i] == ' ') {
			FontRenderer::fFontSpritesheet->setCurSprite(0, 6);
		} else if(text[i] == 'I') {
			FontRenderer::fFontSpritesheet->setCurSprite(1, 6);
		} else if(text[i] == 'J') {
			FontRenderer::fFontSpritesheet->setCurSprite(2, 6);
		} else if(text[i] == 'K') {
			FontRenderer::fFontSpritesheet->setCurSprite(3, 6);
		} else if(text[i] == 'L') {
			FontRenderer::fFontSpritesheet->setCurSprite(4, 6);
		} else if(text[i] == 'M') {
			FontRenderer::fFontSpritesheet->setCurSprite(5, 6);
		} else if(text[i] == 'N') {
			FontRenderer::fFontSpritesheet->setCurSprite(6, 6);
		} else if(text[i] == 'O') {
			FontRenderer::fFontSpritesheet->setCurSprite(7, 6);
		} else if(text[i] == 'P') {
			FontRenderer::fFontSpritesheet->setCurSprite(0, 5);
		} else if(text[i] == 'Q') {
			FontRenderer::fFontSpritesheet->setCurSprite(1, 5);
		} else if(text[i] == 'R') {
			FontRenderer::fFontSpritesheet->setCurSprite(2, 5);
		} else if(text[i] == 'S') {
			FontRenderer::fFontSpritesheet->setCurSprite(3, 5);
		} else if(text[i] == 'T') {
			FontRenderer::fFontSpritesheet->setCurSprite(4, 5);
		} else if(text[i] == 'U') {
			FontRenderer::fFontSpritesheet->setCurSprite(5, 5);
		} else if(text[i] == 'V') {
			FontRenderer::fFontSpritesheet->setCurSprite(6, 5);
		} else if(text[i] == 'X') {
			FontRenderer::fFontSpritesheet->setCurSprite(7, 5);
		} else if(text[i] == 'Y') {
			FontRenderer::fFontSpritesheet->setCurSprite(0, 4);
		} else if(text[i] == 'Z') {
			FontRenderer::fFontSpritesheet->setCurSprite(1, 4);
		} else if(text[i] == 'a') {
			FontRenderer::fFontSpritesheet->setCurSprite(2, 4);
		} else if(text[i] == 'b') {
			FontRenderer::fFontSpritesheet->setCurSprite(3, 4);
		} else if(text[i] == 'c') {
			FontRenderer::fFontSpritesheet->setCurSprite(4, 4);
		} else if(text[i] == 'd') {
			FontRenderer::fFontSpritesheet->setCurSprite(5, 4);
		} else if(text[i] == 'e') {
			FontRenderer::fFontSpritesheet->setCurSprite(6, 4);
		} else if(text[i] == 'f') {
			FontRenderer::fFontSpritesheet->setCurSprite(7, 4);
		} else if(text[i] == 'g') {
			FontRenderer::fFontSpritesheet->setCurSprite(0, 3);
		} else if(text[i] == 'h') {
			FontRenderer::fFontSpritesheet->setCurSprite(1, 3);
		} else if(text[i] == 'i') {
			FontRenderer::fFontSpritesheet->setCurSprite(2, 3);
		} else if(text[i] == 'j') {
			FontRenderer::fFontSpritesheet->setCurSprite(3, 3);
		} else if(text[i] == 'k') {
			FontRenderer::fFontSpritesheet->setCurSprite(4, 3);
		} else if(text[i] == 'l') {
			FontRenderer::fFontSpritesheet->setCurSprite(5, 3);
		} else if(text[i] == 'm') {
			FontRenderer::fFontSpritesheet->setCurSprite(6, 3);
		} else if(text[i] == 'n') {
			FontRenderer::fFontSpritesheet->setCurSprite(7, 3);
		} else if(text[i] == 'o') {
			FontRenderer::fFontSpritesheet->setCurSprite(0, 2);
		} else if(text[i] == 'p') {
			FontRenderer::fFontSpritesheet->setCurSprite(1, 2);
		} else if(text[i] == 'q') {
			FontRenderer::fFontSpritesheet->setCurSprite(2, 2);
		} else if(text[i] == 'r') {
			FontRenderer::fFontSpritesheet->setCurSprite(3, 2);
		} else if(text[i] == 's') {
			FontRenderer::fFontSpritesheet->setCurSprite(4, 2);
		} else if(text[i] == 't') {
			FontRenderer::fFontSpritesheet->setCurSprite(5, 2);
		} else if(text[i] == 'u') {
			FontRenderer::fFontSpritesheet->setCurSprite(6, 2);
		} else if(text[i] == 'v') {
			FontRenderer::fFontSpritesheet->setCurSprite(7, 2);
		} else if(text[i] == 'w') {
			FontRenderer::fFontSpritesheet->setCurSprite(0, 1);
		} else if(text[i] == 'x') {
			FontRenderer::fFontSpritesheet->setCurSprite(1, 1);
		} else if(text[i] == 'y') {
			FontRenderer::fFontSpritesheet->setCurSprite(2, 1);
		} else if(text[i] == 'z') {
			FontRenderer::fFontSpritesheet->setCurSprite(3, 1);
		} else if(text[i] == '0') {
			FontRenderer::fFontSpritesheet->setCurSprite(4, 1);
		} else if(text[i] == '1') {
			FontRenderer::fFontSpritesheet->setCurSprite(5, 1);
		} else if(text[i] == '2') {
			FontRenderer::fFontSpritesheet->setCurSprite(6, 1);
		} else if(text[i] == '3') {
			FontRenderer::fFontSpritesheet->setCurSprite(7, 1);
		} else if(text[i] == '4') {
			FontRenderer::fFontSpritesheet->setCurSprite(0, 0);
		} else if(text[i] == '5') {
			FontRenderer::fFontSpritesheet->setCurSprite(1, 0);
		} else if(text[i] == '6') {
			FontRenderer::fFontSpritesheet->setCurSprite(2, 0);
		} else if(text[i] == '7') {
			FontRenderer::fFontSpritesheet->setCurSprite(3, 0);
		} else if(text[i] == '8') {
			FontRenderer::fFontSpritesheet->setCurSprite(4, 0);
		} else if(text[i] == '9') {
			FontRenderer::fFontSpritesheet->setCurSprite(5, 0);
		} else if(text[i] == '-') {
			FontRenderer::fFontSpritesheet->setCurSprite(6, 0);
		} else if(text[i] == ':') {
			FontRenderer::fFontSpritesheet->setCurSprite(7, 0);
		} else if(text[i] == ';') {
			FontRenderer::fFontSpritesheet->setCurSprite(8, 0);
		} else if(text[i] == 'W') {
			FontRenderer::fFontSpritesheet->setCurSprite(8, 5);
		} else if(text[i] == '[') {
			FontRenderer::fFontSpritesheet->setCurSprite(9, 0);
		} else if(text[i] == ']') {
			FontRenderer::fFontSpritesheet->setCurSprite(10, 0);
		} else if(text[i] == '_') {
			FontRenderer::fFontSpritesheet->setCurSprite(11, 0);
		} else if(text[i] == '(') {
			FontRenderer::fFontSpritesheet->setCurSprite(12, 0);
		} else if(text[i] == ')') {
			FontRenderer::fFontSpritesheet->setCurSprite(13, 0);
		} else if(text[i] == '\'') {
			FontRenderer::fFontSpritesheet->setCurSprite(14, 0);
		} else if(text[i] == '"') {
			FontRenderer::fFontSpritesheet->setCurSprite(15, 0);
		} else if(text[i] == '+') {
			FontRenderer::fFontSpritesheet->setCurSprite(8, 1);
		} else if(text[i] == '#') {
			FontRenderer::fFontSpritesheet->setCurSprite(9, 1);
		} else if(text[i] == '\\') {
			FontRenderer::fFontSpritesheet->setCurSprite(10, 1);
		} else if(text[i] == '/') {
			FontRenderer::fFontSpritesheet->setCurSprite(11, 1);
		} else if(text[i] == '.') {
			FontRenderer::fFontSpritesheet->setCurSprite(12, 1);
		} else if(text[i] == '?') {
			FontRenderer::fFontSpritesheet->setCurSprite(13, 1);
		} else if(text[i] == '!') {
			FontRenderer::fFontSpritesheet->setCurSprite(14, 1);
		} else if(text[i] == ',') {
			FontRenderer::fFontSpritesheet->setCurSprite(15, 1);
		} else if(text[i] == '=') {
			FontRenderer::fFontSpritesheet->setCurSprite(8, 2);
		} else if(text[i] == '*') {
			FontRenderer::fFontSpritesheet->setCurSprite(9, 2);
		} else if(text[i] == '$') {
			FontRenderer::fFontSpritesheet->setCurSprite(10, 2);
		} else if(text[i] == '£') {
			FontRenderer::fFontSpritesheet->setCurSprite(11, 2);
		} else if(text[i] == 'é') {
			FontRenderer::fFontSpritesheet->setCurSprite(8, 4);
		} else if(text[i] == 'è') {
			FontRenderer::fFontSpritesheet->setCurSprite(9, 4);
		} else if(text[i] == 'ù') {
			FontRenderer::fFontSpritesheet->setCurSprite(10, 4);
		} else if(text[i] == 'à') {
			FontRenderer::fFontSpritesheet->setCurSprite(11, 4);
		} else if(text[i] == 'ç') {
			FontRenderer::fFontSpritesheet->setCurSprite(12, 4);
		} else if(text[i] == '&') {
			FontRenderer::fFontSpritesheet->setCurSprite(13, 4);
		}
		glBegin(GL_QUADS);

		FontRenderer::fFontSpritesheet->setTopLeftTexCoord();
		glVertex2i(0+letterWidth*i,0);

		FontRenderer::fFontSpritesheet->setTopRightTexCoord();
		glVertex2i(0+letterWidth*i + letterWidth, 0);

		FontRenderer::fFontSpritesheet->setBottomRightTexCoord();
		glVertex2i(0+letterWidth*i + letterWidth, letterWidth);

		FontRenderer::fFontSpritesheet->setBottomLeftTexCoord();
		glVertex2i(0+letterWidth*i, letterWidth);


		glEnd();

		
	}
	glDisable(GL_TEXTURE_2D); 

	glPopMatrix();

}

void FontRenderer::renderText(const char* text, int x, int y, int size) {
	this->renderText(text, x, y, size, 1.0f);
}

void FontRenderer::renderText(const char* text, int x, int y, int size, float opacity) {
	int lenght= strlen(text);
	int letterWidth = 8*size;


	glPushMatrix();

	glLoadIdentity();
	glTranslatef(x, y, 0);

	glColor4f(1.0f,1.0f,1.0f,opacity);

	glEnable(GL_TEXTURE_2D); 
	this->FontSpritesheet->bind();
	for(int i=0;i<lenght;i++) {

		if(text[i] == 'A') {
			this->FontSpritesheet->setCurSprite(0, 7);
		} else if(text[i] == 'B') {
			FontSpritesheet->setCurSprite(1, 7);
		} else if(text[i] == 'C') {
			FontSpritesheet->setCurSprite(2, 7);
		} else if(text[i] == 'D') {
			FontSpritesheet->setCurSprite(3, 7);
		} else if(text[i] == 'E') {
			FontSpritesheet->setCurSprite(4, 7);
		} else if(text[i] == 'F') {
			FontSpritesheet->setCurSprite(5, 7);
		} else if(text[i] == 'G') {
			FontSpritesheet->setCurSprite(6, 7);
		} else if(text[i] == 'H') {
			FontSpritesheet->setCurSprite(7, 7);
		} else if(text[i] == ' ') {
			FontSpritesheet->setCurSprite(0, 6);
		} else if(text[i] == 'I') {
			FontSpritesheet->setCurSprite(1, 6);
		} else if(text[i] == 'J') {
			FontSpritesheet->setCurSprite(2, 6);
		} else if(text[i] == 'K') {
			FontSpritesheet->setCurSprite(3, 6);
		} else if(text[i] == 'L') {
			FontSpritesheet->setCurSprite(4, 6);
		} else if(text[i] == 'M') {
			FontSpritesheet->setCurSprite(5, 6);
		} else if(text[i] == 'N') {
			FontSpritesheet->setCurSprite(6, 6);
		} else if(text[i] == 'O') {
			FontSpritesheet->setCurSprite(7, 6);
		} else if(text[i] == 'P') {
			FontSpritesheet->setCurSprite(0, 5);
		} else if(text[i] == 'Q') {
			FontSpritesheet->setCurSprite(1, 5);
		} else if(text[i] == 'R') {
			FontSpritesheet->setCurSprite(2, 5);
		} else if(text[i] == 'S') {
			FontSpritesheet->setCurSprite(3, 5);
		} else if(text[i] == 'T') {
			FontSpritesheet->setCurSprite(4, 5);
		} else if(text[i] == 'U') {
			FontSpritesheet->setCurSprite(5, 5);
		} else if(text[i] == 'V') {
			FontSpritesheet->setCurSprite(6, 5);
		} else if(text[i] == 'X') {
			FontSpritesheet->setCurSprite(7, 5);
		} else if(text[i] == 'Y') {
			FontSpritesheet->setCurSprite(0, 4);
		} else if(text[i] == 'Z') {
			FontSpritesheet->setCurSprite(1, 4);
		} else if(text[i] == 'a') {
			FontSpritesheet->setCurSprite(2, 4);
		} else if(text[i] == 'b') {
			FontSpritesheet->setCurSprite(3, 4);
		} else if(text[i] == 'c') {
			FontSpritesheet->setCurSprite(4, 4);
		} else if(text[i] == 'd') {
			FontSpritesheet->setCurSprite(5, 4);
		} else if(text[i] == 'e') {
			FontSpritesheet->setCurSprite(6, 4);
		} else if(text[i] == 'f') {
			FontSpritesheet->setCurSprite(7, 4);
		} else if(text[i] == 'g') {
			FontSpritesheet->setCurSprite(0, 3);
		} else if(text[i] == 'h') {
			FontSpritesheet->setCurSprite(1, 3);
		} else if(text[i] == 'i') {
			FontSpritesheet->setCurSprite(2, 3);
		} else if(text[i] == 'j') {
			FontSpritesheet->setCurSprite(3, 3);
		} else if(text[i] == 'k') {
			FontSpritesheet->setCurSprite(4, 3);
		} else if(text[i] == 'l') {
			FontSpritesheet->setCurSprite(5, 3);
		} else if(text[i] == 'm') {
			FontSpritesheet->setCurSprite(6, 3);
		} else if(text[i] == 'n') {
			FontSpritesheet->setCurSprite(7, 3);
		} else if(text[i] == 'o') {
			FontSpritesheet->setCurSprite(0, 2);
		} else if(text[i] == 'p') {
			FontSpritesheet->setCurSprite(1, 2);
		} else if(text[i] == 'q') {
			FontSpritesheet->setCurSprite(2, 2);
		} else if(text[i] == 'r') {
			FontSpritesheet->setCurSprite(3, 2);
		} else if(text[i] == 's') {
			FontSpritesheet->setCurSprite(4, 2);
		} else if(text[i] == 't') {
			FontSpritesheet->setCurSprite(5, 2);
		} else if(text[i] == 'u') {
			FontSpritesheet->setCurSprite(6, 2);
		} else if(text[i] == 'v') {
			FontSpritesheet->setCurSprite(7, 2);
		} else if(text[i] == 'w') {
			FontSpritesheet->setCurSprite(0, 1);
		} else if(text[i] == 'x') {
			FontSpritesheet->setCurSprite(1, 1);
		} else if(text[i] == 'y') {
			FontSpritesheet->setCurSprite(2, 1);
		} else if(text[i] == 'z') {
			FontSpritesheet->setCurSprite(3, 1);
		} else if(text[i] == '0') {
			this->FontSpritesheet->setCurSprite(4, 1);
		} else if(text[i] == '1') {
			this->FontSpritesheet->setCurSprite(5, 1);
		} else if(text[i] == '2') {
			this->FontSpritesheet->setCurSprite(6, 1);
		} else if(text[i] == '3') {
			this->FontSpritesheet->setCurSprite(7, 1);
		} else if(text[i] == '4') {
			this->FontSpritesheet->setCurSprite(0, 0);
		} else if(text[i] == '5') {
			this->FontSpritesheet->setCurSprite(1, 0);
		} else if(text[i] == '6') {
			FontSpritesheet->setCurSprite(2, 0);
		} else if(text[i] == '7') {
			FontSpritesheet->setCurSprite(3, 0);
		} else if(text[i] == '8') {
			FontSpritesheet->setCurSprite(4, 0);
		} else if(text[i] == '9') {
			FontSpritesheet->setCurSprite(5, 0);
		} else if(text[i] == '-') {
			FontSpritesheet->setCurSprite(6, 0);
		} else if(text[i] == ':') {
			FontSpritesheet->setCurSprite(7, 0);
		} else if(text[i] == ';') {
			FontSpritesheet->setCurSprite(8, 0);
		} else if(text[i] == 'W') {
			FontSpritesheet->setCurSprite(8, 5);
		} else if(text[i] == '[') {
			FontSpritesheet->setCurSprite(9, 0);
		} else if(text[i] == ']') {
			FontSpritesheet->setCurSprite(10, 0);
		} else if(text[i] == '_') {
			FontSpritesheet->setCurSprite(11, 0);
		} else if(text[i] == '(') {
			FontSpritesheet->setCurSprite(12, 0);
		} else if(text[i] == ')') {
			FontSpritesheet->setCurSprite(13, 0);
		} else if(text[i] == '\'') {
			FontSpritesheet->setCurSprite(14, 0);
		} else if(text[i] == '"') {
			FontSpritesheet->setCurSprite(15, 0);
		} else if(text[i] == '+') {
			FontSpritesheet->setCurSprite(8, 1);
		} else if(text[i] == '#') {
			FontSpritesheet->setCurSprite(9, 1);
		} else if(text[i] == '\\') {
			FontSpritesheet->setCurSprite(10, 1);
		} else if(text[i] == '/') {
			FontSpritesheet->setCurSprite(11, 1);
		} else if(text[i] == '.') {
			FontSpritesheet->setCurSprite(12, 1);
		} else if(text[i] == '?') {
			FontSpritesheet->setCurSprite(13, 1);
		} else if(text[i] == '!') {
			FontSpritesheet->setCurSprite(14, 1);
		} else if(text[i] == ',') {
			FontSpritesheet->setCurSprite(15, 1);
		} else if(text[i] == '=') {
			FontSpritesheet->setCurSprite(8, 2);
		} else if(text[i] == '*') {
			FontSpritesheet->setCurSprite(9, 2);
		} else if(text[i] == '$') {
			FontSpritesheet->setCurSprite(10, 2);
		} else if(text[i] == '£') {
			FontSpritesheet->setCurSprite(11, 2);
		} else if(text[i] == 'é') {
			FontSpritesheet->setCurSprite(8, 4);
		} else if(text[i] == 'è') {
			FontSpritesheet->setCurSprite(9, 4);
		} else if(text[i] == 'ù') {
			FontSpritesheet->setCurSprite(10, 4);
		} else if(text[i] == 'à') {
			FontSpritesheet->setCurSprite(11, 4);
		} else if(text[i] == 'ç') {
			FontSpritesheet->setCurSprite(12, 4);
		} else if(text[i] == '&') {
			FontSpritesheet->setCurSprite(13, 4);
		}

		glBegin(GL_QUADS);

		//glColor3ub(255,255,255);
		FontSpritesheet->setTopLeftTexCoord();
		glVertex2i(0+letterWidth*i,0);

		FontSpritesheet->setTopRightTexCoord();
		glVertex2i(0+letterWidth*i + letterWidth, 0);

		FontSpritesheet->setBottomRightTexCoord();
		glVertex2i(0+letterWidth*i + letterWidth, letterWidth);

		FontSpritesheet->setBottomLeftTexCoord();
		glVertex2i(0+letterWidth*i, letterWidth);


		glEnd();

		
	}
	glDisable(GL_TEXTURE_2D); 

	glPopMatrix();

}