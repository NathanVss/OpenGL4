
#ifndef DEF_RENDERER
#define DEF_RENDERER

#pragma once
class Renderer
{
public:
	Renderer(void);
	~Renderer(void);
	virtual void render() = 0;
};

#endif
