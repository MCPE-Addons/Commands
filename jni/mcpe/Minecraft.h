#pragma once

#include "ServerCommandParser.h"
#include "Level.h"

class GameMode;

class Minecraft {
public:
	char filler1[64];
	ServerCommandParser* cmdParser;
	
	Level* getLevel();
	ServerCommandParser* getCommandParser();
	GameMode* getGameMode();
};
