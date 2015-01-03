#pragma once

#include "Updatable.h"
#include "Renderer.h"
#include "Keyboardable.h"
#include "FontRenderer.h"
#include "CommandsManager.h"
#include <memory>
#include <vector>

class GameConsole : public Updatable, public Renderer, public Keyboardable
{
public:
	GameConsole(void);
	~GameConsole(void);
	virtual void update();
	virtual void render();
	void renderCursor();
	void renderCurTypingContent();
	void renderContent();
	void submitCurTypingContent();
	void addEntry(std::string);
	std::string getCurTypingContent();

	void setFontRenderer(std::shared_ptr<FontRenderer>);
	void setCommandsManager(std::shared_ptr<CommandsManager>);

private:
	int lastTypedLetterTicks;
	std::vector<char> curTypingContent;
	std::vector<std::string> content;

	std::shared_ptr<FontRenderer> fFontRenderer;
	std::shared_ptr<CommandsManager> cCommandsManager;

	int lastDisplayTicks;
	bool mustDisplay;

	bool isFocus;

	int lastDisplayTicksCursor;

	int cursorHeight;
	int cursorWidth;
	int cursorX;
	int cursorY;

	int sizeX;
	int sizeY;

	int lettersSize;
};

