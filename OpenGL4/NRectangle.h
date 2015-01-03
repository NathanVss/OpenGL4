#ifndef DEF_NRECTANGLE
#define DEF_NRECTANGLE

#include <memory>

class NRectangle
{
public:
	NRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	NRectangle(int x1, int y1, int width, int height);
	~NRectangle(void);
	int getX1();
	int getX2();
	int getX3();
	int getX4();
	int getY1();
	int getY2();
	int getY3();
	int getY4();
	void render();
	void changePos(int x1, int y1);

	void setColor(int red, int green, int blue);

	bool doesCollideTopRightOf(NRectangle*);
	bool doesCollideBottomLeftOf(NRectangle*);
	bool doesCollideBottomRightOf(NRectangle*);
	bool doesCollideTopLeftOf(NRectangle*);

	bool doesCollideBottomOf(NRectangle*);
	bool doesCollideTopOf(NRectangle*);
	bool doesCollideLeftOf(NRectangle*);
	bool doesCollideRightOf(NRectangle*);
	int getWidth();
	int getHeight();

private:
	int red;
	int green;
	int blue;

	int x1;
	int y1;

	int x2;
	int y2;

	int x3;
	int y3;

	int x4;
	int y4;

	int width;
	int height;
};

#endif