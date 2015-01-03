#ifndef DEF_KEYBOARD
#define DEF_KEYBOARD
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <SDL/SDL.h>
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <cstdlib>

#include "Updatable.h"


class Keyboard : public Updatable
{
public:
	Keyboard();
	void setKeyQ(bool keyQ);
	void setKeyUp(bool keyUp);
	bool getKeyQ();
	bool getKeyUp();
	bool getKeyDown();
	bool getKeyLeft();
	bool getKeyRight();
	bool getKey0();
	bool getKey1();
	bool getKey2();
	bool getKey3();
	bool getKey4();
	bool getKey5();
	bool getKey6();
	bool getKey7();
	bool getKey8();
	bool getKey9();
	bool getKeyG();
	bool getKeyI();
	bool getKeyEnter();
	bool getKeyBackSpace();
	bool getKeyRightSlash();
	bool getKeyO();
	bool getKeyD();
	bool getKeyT();
	bool getKeyN();
	bool getKeyLeftShift();
	void checkInputs(SDL_Event &Event);
	virtual void update();

private:
	bool keyRightSlash;
	bool keyLeftShift;
	bool keyT;
	bool keyO;
	bool keyD;
	bool keyN;
	bool keyEnter;
	bool keyBackSpace;
	bool keyQ;
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keyG;
	bool key0;
	bool key1;
	bool key2;
	bool key3;
	bool key4;
	bool key5;
	bool key6;
	bool key7;
	bool key8;
	bool key9;
	bool keyI;

};

#endif