#include "GameConsole.h"
#include "Boot.h"
#include <memory>
GameConsole::GameConsole(void){
	this->sizeX = 600;
	this->sizeY = 300;

	this->lastDisplayTicks = 0;
	this->lastDisplayTicksCursor = 0;
	this->lastTypedLetterTicks = 0;


	this->cursorHeight = 20;
	this->cursorWidth = 3;
	this->cursorX = 0;
	this->cursorY = this->sizeY - this->cursorHeight;
	this->isFocus = false;
	this->mustDisplay = false;

	this->lettersSize = 2;
}


GameConsole::~GameConsole(void)
{
}

void GameConsole::setCommandsManager(std::shared_ptr<CommandsManager> cm) {
	this->cCommandsManager = cm;
}


void GameConsole::render() {
	

	int topLeftX = Boot::width - this->sizeX;
	int topLeftY = Boot::height - this->sizeY;

	glPushMatrix();
	glLoadIdentity();
	glTranslatef(topLeftX, topLeftY,0);

	if(this->mustDisplay) {
		glColor4f(0.5f,0.5f,0.5f,0.5f);
	} else {
		glColor4f(0.5f,0.5f,0.5f,0.2f);
	}

	glBegin(GL_QUADS);

	glVertex2i(0,0);

	glVertex2i(sizeX, 0);

	glVertex2i(sizeX, sizeY);

	glVertex2i(0, sizeY);

	glEnd();

	if(this->mustDisplay) {
		this->renderCursor();
		this->renderCurTypingContent();
		
	}
	this->renderContent();

	glPopMatrix();
	
	
}

void GameConsole::renderContent() {
	int lineNbr = 18;

	int topLeftX = Boot::width - this->sizeX;
	int j = 0;
	for(int i = ((int)this->content.size()-1); i > ((int)this->content.size() - lineNbr); i--) {
		if(i < 0) {
			break;
		}
		float opacity = 1.0f;
		if(!this->mustDisplay) {
			opacity = 0.2f;
		}

		this->fFontRenderer->renderText(this->content[i].c_str(), topLeftX, Boot::height - (j+2)*(this->lettersSize*FontRenderer::letterSize), this->lettersSize, opacity);

		j++;
	}
}


void GameConsole::renderCurTypingContent() {
	std::string curTyping = this->getCurTypingContent();

	int topLeftX = Boot::width - this->sizeX;
	int topLeftY = Boot::height - this->sizeY;


	this->fFontRenderer->renderText(curTyping.c_str(),topLeftX, Boot::height-this->lettersSize*FontRenderer::letterSize, this->lettersSize);

}

void GameConsole::renderCursor() {
	/* plus nospeed est petit plus c'est rapide */
	float nospeed = 0.5f;
	bool display = false;
	if(this->lastDisplayTicksCursor < 40*nospeed && this->lastDisplayTicksCursor >= 0) {

		display = true;

	} else if(this->lastDisplayTicksCursor >= 40*nospeed && this->lastDisplayTicksCursor < 80*nospeed) {
		display = false;
	} else {
		this->lastDisplayTicksCursor = 0;
	}

	this->cursorX = this->curTypingContent.size() * FontRenderer::letterSize*this->lettersSize;

	if(display) {

		glPushMatrix();	
		glTranslatef(this->cursorX, this->cursorY, 0);
		glColor3ub(255,255,255);

		glBegin(GL_QUADS);
		
		glVertex2i(0,0);
		glVertex2i(this->cursorWidth, 0);
		glVertex2i(this->cursorWidth, this->cursorHeight);
		glVertex2i(0, this->cursorHeight);

		glEnd();
		
		glPopMatrix();

	}
	this->lastDisplayTicksCursor++;
}

void GameConsole::update() {
	if(this->kKeyboard->getKeyT() && this->lastDisplayTicks > 10) {

		if(this->mustDisplay) {
			this->mustDisplay = false;
			this->isFocus = false;
		} else {
			this->mustDisplay = true;
			this->isFocus= true;
		}
		this->lastDisplayTicks = 0;
	}

	this->lastDisplayTicks++;

	if(this->isFocus && this->lastTypedLetterTicks > 5) {
		bool typed = false;
		if(this->kKeyboard->getKey1()) {
			this->curTypingContent.push_back('1');
			typed = true;
		}
		if(this->kKeyboard->getKeyRightSlash()) {
			this->curTypingContent.push_back('/');
			typed = true;
		}
		if(this->kKeyboard->getKeyG()) {
			this->curTypingContent.push_back('g');
			typed = true;
		}
		if(this->kKeyboard->getKeyO()) {
			this->curTypingContent.push_back('o');
			typed = true;
		}
		if(this->kKeyboard->getKeyD()) {
			this->curTypingContent.push_back('d');
			typed = true;
		}
		if(this->kKeyboard->getKeyN()) {
			this->curTypingContent.push_back('n');
			typed = true;
		}
		if(this->kKeyboard->getKeyEnter()) {

			this->submitCurTypingContent();
			typed = true;
		}


		if(this->kKeyboard->getKeyBackSpace()) {
			this->curTypingContent.pop_back();
			typed = true;
		}
		if(typed) {
			this->lastTypedLetterTicks = 0;
		}
	}
	this->lastTypedLetterTicks++;

}


void GameConsole::setFontRenderer(std::shared_ptr<FontRenderer> f) {
	this->fFontRenderer = f;
}

std::string GameConsole::getCurTypingContent() {
	std::string curTyping;

	for(int i=0;i<this->curTypingContent.size();i++) {
		curTyping = curTyping + this->curTypingContent[i];

	}
	return curTyping;
}

void GameConsole::submitCurTypingContent() {
	std::string submited = this->getCurTypingContent();

	this->addEntry(submited);
	this->cCommandsManager->checkCommand(submited);

	
	this->curTypingContent.clear();
}

void GameConsole::addEntry(std::string entry) {
	this->content.push_back(entry);
}