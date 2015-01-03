#pragma once

#include <vector>
#include <string>
#include <memory>

#include "Renderer.h"
#include "FontRenderer.h"
#include "Updatable.h"

class DebugOverlay : public Renderer, public Updatable
{
public:
	DebugOverlay(void);
	~DebugOverlay(void);
	void addString(std::string);
	void setFontRenderer(std::shared_ptr<FontRenderer>);
	void render();
	void update();

private:
	int x;
	int y;
	int lettersSize;
	std::vector<std::string> strings;
	std::shared_ptr<FontRenderer> fFontRenderer;
};

