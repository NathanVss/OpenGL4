#include "Keyboard.h"


Keyboard::Keyboard() {
	keyQ = false;
	keyUp = false;
	keyDown = false;
	keyLeft = false;
	keyRight = false;
	keyG = false;
	key0 = false;
	key1 = false;
	key2 = false;
	key3 = false;
	key4 = false;
	key5 = false;
	key6 = false;
	key7 = false;
	key8 = false;
	key9 = false;
	keyI = false;
	keyEnter = false;
	keyBackSpace = false;
	keyRightSlash = false;
	keyG = false;
	keyO = false;
	keyD = false;
	keyT = false;
	keyN = false;
	keyLeftShift = false;
}

void Keyboard::update() {

}



void Keyboard::checkInputs(SDL_Event &Event) {
	if(Event.type == SDL_KEYDOWN) {
		//Keyboard.checkInputs(&event);
		if(Event.key.keysym.sym == SDLK_UP) {
			this->keyUp = true;
		}
		if(Event.key.keysym.sym == SDLK_DOWN) {
			this->keyDown = true;
		}
		if(Event.key.keysym.sym == SDLK_LEFT) {
			this->keyLeft = true;
		}
		if(Event.key.keysym.sym == SDLK_RIGHT) {
			this->keyRight = true;
		}
		if(Event.key.keysym.sym == SDLK_g) {
			this->keyG = true;
		}
		if(Event.key.keysym.sym == SDLK_0) {
			this->key0 = true;
		}
		if(Event.key.keysym.sym == SDLK_1) {
			this->key1 = true;
		}
		if(Event.key.keysym.sym == SDLK_2) {
			this->key2 = true;
		}
		if(Event.key.keysym.sym == SDLK_3) {
			this->key3 = true;
		}
		if(Event.key.keysym.sym == SDLK_4) {
			this->key4 = true;
		}
		if(Event.key.keysym.sym == SDLK_5) {
			this->key5 = true;
		}
		if(Event.key.keysym.sym == SDLK_6) {
			this->key6 = true;
		}
		if(Event.key.keysym.sym == SDLK_7) {
			this->key7 = true;
		}
		if(Event.key.keysym.sym == SDLK_8) {
			this->key8 = true;
		}
		if(Event.key.keysym.sym == SDLK_9) {
			this->key9 = true;
		}
		if(Event.key.keysym.sym == SDLK_i) {
			this->keyI = true;
		}
		if(Event.key.keysym.sym == SDLK_RETURN) {
			this->keyEnter = true;
		}
		if(Event.key.keysym.sym == SDLK_BACKSPACE) {
			this->keyBackSpace = true;
		}
		if(Event.key.keysym.sym == SDLK_o) {
			this->keyO = true;
		}
		if(Event.key.keysym.sym == SDLK_d) {
			this->keyD = true;
		}
		if(Event.key.keysym.sym == SDLK_PERIOD && this->keyLeftShift) {
			this->keyRightSlash = true;
		}
		if(Event.key.keysym.sym == SDLK_LSHIFT) {
			this->keyLeftShift = true;
		}
		if(Event.key.keysym.sym == SDLK_t) {
			this->keyT = true;
		}
		if(Event.key.keysym.sym == SDLK_n) {
			this->keyN = true;
		}
		//OutputDebugString((SDL_GetKeyName(Event.key.keysym.sym)));
		//OutputDebugString("\n");

	}
	if(Event.type == SDL_KEYUP) {
		if(Event.key.keysym.sym == SDLK_UP) {
			this->keyUp = false;
		}
		if(Event.key.keysym.sym == SDLK_DOWN) {
			this->keyDown = false;
		}
		if(Event.key.keysym.sym == SDLK_LEFT) {
			this->keyLeft = false;
		}
		if(Event.key.keysym.sym == SDLK_RIGHT) {
			this->keyRight = false;
		}
		if(Event.key.keysym.sym == SDLK_g) {
			this->keyG = false;
		}
		if(Event.key.keysym.sym == SDLK_0) {
			this->key0 = false;
		}
		if(Event.key.keysym.sym == SDLK_1) {
			this->key1 = false;
		}
		if(Event.key.keysym.sym == SDLK_2) {
			this->key2 = false;
		}
		if(Event.key.keysym.sym == SDLK_3) {
			this->key3 = false;
		}
		if(Event.key.keysym.sym == SDLK_4) {
			this->key4 = false;
		}
		if(Event.key.keysym.sym == SDLK_5) {
			this->key5 = false;
		}
		if(Event.key.keysym.sym == SDLK_6) {
			this->key6 = false;
		}
		if(Event.key.keysym.sym == SDLK_7) {
			this->key7 = false;
		}
		if(Event.key.keysym.sym == SDLK_8) {
			this->key8 = false;
		}
		if(Event.key.keysym.sym == SDLK_9) {
			this->key9 = false;
		}
		if(Event.key.keysym.sym == SDLK_i) {
			this->keyI = false;
		}
		if(Event.key.keysym.sym == SDLK_RETURN) {
			this->keyEnter = false;
		}
		if(Event.key.keysym.sym == SDLK_BACKSPACE) {
			this->keyBackSpace = false;
		}
		if(Event.key.keysym.sym == SDLK_o) {
			this->keyO = false;
		}
		if(Event.key.keysym.sym == SDLK_d) {
			this->keyD = false;
		}
		if(Event.key.keysym.sym == SDLK_PERIOD) {
			this->keyRightSlash = false;
		}
		if(Event.key.keysym.sym == SDLK_LSHIFT) {
			this->keyLeftShift = false;
		}
		if(Event.key.keysym.sym == SDLK_t) {
			this->keyT = false;
		}
		if(Event.key.keysym.sym == SDLK_n) {
			this->keyN = false;
		}
	}
}


bool Keyboard::getKeyN() {
	return this->keyN;
}
bool Keyboard::getKeyT() {
	return this->keyT;
}

bool Keyboard::getKeyLeftShift() {
	return this->keyLeftShift;
}

bool Keyboard::getKeyRightSlash() {
	return this->keyRightSlash;
}
bool Keyboard::getKeyO() {
	return this->keyO;
}
bool Keyboard::getKeyD() {
	return this->keyD;
}

bool Keyboard::getKeyBackSpace() {
	return this->keyBackSpace;
}

bool Keyboard::getKeyEnter() {
	return this->keyEnter;
}

bool Keyboard::getKeyI() {
	return this->keyI;
}

bool Keyboard::getKey0() {
	return this->key0;
}
bool Keyboard::getKey1() {
	return this->key1;
}
bool Keyboard::getKey2() {
	return this->key2;
}
bool Keyboard::getKey3() {
	return this->key3;
}
bool Keyboard::getKey4() {
	return this->key4;
}

bool Keyboard::getKey5() {
	return this->key5;
}
bool Keyboard::getKey6() {
	return this->key6;
}
bool Keyboard::getKey7() {
	return this->key7;
}
bool Keyboard::getKey8() {
	return this->key8;
}
bool Keyboard::getKey9() {
	return this->key9;
}



void Keyboard::setKeyQ(bool keyQ) {
	this->keyQ = keyQ;
}

void Keyboard::setKeyUp(bool keyUp) {
	this->keyUp = keyUp;
}

bool Keyboard::getKeyG() {
	return this->keyG;
}

bool Keyboard::getKeyQ() {
	return this->keyQ;
}

bool Keyboard::getKeyUp() {
	return this->keyUp;
}

bool Keyboard::getKeyDown() {
	return this->keyDown;
}

bool Keyboard::getKeyLeft() {
	return this->keyLeft;
}

bool Keyboard::getKeyRight() {
	return this->keyRight;
}

