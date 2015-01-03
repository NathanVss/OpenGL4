#include "CommandsManager.h"
#include "GameConsole.h"


CommandsManager::CommandsManager(void)
{
}


CommandsManager::~CommandsManager(void)
{
}

void CommandsManager::setGameConsole(std::shared_ptr<GameConsole> g) {
	this->gGameConsole = g;
}

void CommandsManager::checkCommand(std::string cmd) {
	OutputDebugString(this->CurPlayer->getName().c_str());
	if(cmd == std::string("/god")) {
		this->CurPlayer->setGodMode(true);
		this->gGameConsole->addEntry(std::string("You are now God"));
	}
	if(cmd == std::string("/nogod")) {
		this->CurPlayer->setGodMode(false);
		this->gGameConsole->addEntry(std::string("You are now Piece of Shit"));
	}

}

void CommandsManager::setCurPlayer(std::shared_ptr<Player> c) {
	this->CurPlayer = c;
	
}
