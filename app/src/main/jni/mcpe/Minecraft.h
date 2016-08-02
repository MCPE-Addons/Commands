#pragma once

#include "ServerCommandParser.h"
#include "Level.h"

class Minecraft {
public:
	Level* getLevel();
	ServerCommandParser* getCommandParser();
	GameMode* getGameMode();
	void init(const std::string&, bool);
};
