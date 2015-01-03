#pragma once

class Item
{
public:
	Item(void);
	~Item(void);
	virtual void render(int x, int y) = 0;
	int getId();
	bool isPlaceable();

protected:
	int id;
	bool placeable;
};

