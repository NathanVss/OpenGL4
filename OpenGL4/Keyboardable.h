#ifndef DEF_KEYBOARDABLE
#define DEF_KEYBOARDABLE
#pragma once

#include "Keyboard.h"

class Keyboardable
{
public:
	Keyboardable(void);
	~Keyboardable(void);
	virtual void setKeyboard(Keyboard*);
protected:
	Keyboard* kKeyboard;
};

#endif
