#include "Mouse.h"


FontRenderer* Mouse::fFontRenderer;
int Mouse::relX = 0;
int Mouse::relY = 0;
int Mouse::wX = 0;
int Mouse::wY = 0;
bool Mouse::leftClick = false;
bool Mouse::rightClick = false;


Mouse::Mouse(void){
}


Mouse::~Mouse(void){
}

void Mouse::setFontRenderer(FontRenderer* fFontRenderer) {
	Mouse::fFontRenderer = fFontRenderer;
}

void Mouse::checkInputs(SDL_Event *SdlEvent) {

	if((*SdlEvent).type == SDL_MOUSEBUTTONDOWN) {
		if((*SdlEvent).button.button == SDL_BUTTON_LEFT) {
			//Mouse::leftClick = true;
			Mouse::leftClick = true;
			
		}
		if(SdlEvent->button.button == SDL_BUTTON_RIGHT) {
			Mouse::rightClick = true;
		}

	} else if((*SdlEvent).type == SDL_MOUSEBUTTONUP) {
		if((*SdlEvent).button.button == SDL_BUTTON_LEFT) {
			Mouse::leftClick = false;
		}
		if(SdlEvent->button.button == SDL_BUTTON_RIGHT) {
			Mouse::rightClick = false;
		}
	}

}

void Mouse::render() {


}

void Mouse::update() {

	

	SDL_GetMouseState(&Mouse::relX, &Mouse::relY);
	Mouse::wX = (Camera::curX-Boot::width/2) + Mouse::relX;
	Mouse::wY = (Camera::curY-Boot::height/2)  + Mouse::relY;
}
