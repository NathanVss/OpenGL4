#pragma once

#include "Player.h"

class GameConsole;

class CommandsManager
{
public:
	CommandsManager(void);
	~CommandsManager(void);
	void checkCommand(std::string);
	void setCurPlayer(std::shared_ptr<Player> CurPlayer);

	void setGameConsole(std::shared_ptr<GameConsole>);

private:
	std::shared_ptr<Player> CurPlayer;
	std::shared_ptr<GameConsole> gGameConsole;

};

