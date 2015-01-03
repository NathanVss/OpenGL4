#pragma once
class ShadowMap
{
public:
	ShadowMap(int w, int h);
	~ShadowMap(void);
	bool setScale(int x, int y, int s);
	unsigned char*** getScale();
	int getScale(int, int);
	int getWidth();
	int getHeight();

private:
	unsigned char** scale;
	int width;
	int height;
};

