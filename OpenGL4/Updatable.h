#ifndef DEF_UPDATABLE
#define DEF_UPDATABLE
#pragma once
class Updatable
{
public:
	Updatable(void);
	~Updatable(void);
	virtual void update() = 0;
};

#endif

