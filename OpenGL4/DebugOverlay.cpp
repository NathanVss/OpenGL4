#include "DebugOverlay.h"


DebugOverlay::DebugOverlay(void){
	this->x = 0;
	this->y = 0;
	this->lettersSize = 2;
}


DebugOverlay::~DebugOverlay(void){
}

void DebugOverlay::addString(std::string s) {
	this->strings.push_back(s);
}

void DebugOverlay::setFontRenderer(std::shared_ptr<FontRenderer> f) {
	this->fFontRenderer = f;
}

void DebugOverlay::render() {
	for(int i=0;i<(int)this->strings.size();i++) {

		this->fFontRenderer->renderText(this->strings[i].c_str(), this->x, this->y + i*FontRenderer::letterSize*this->lettersSize, this->lettersSize);

	}
	this->strings.clear();
}

void DebugOverlay::update() {
	
}