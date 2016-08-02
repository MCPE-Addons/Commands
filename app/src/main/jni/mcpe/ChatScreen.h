#pragma once

#include <string>
#include <deque>

#include "MinecraftClient.h"

struct ChatScreen {
	char filler1[20];			// 0
	MinecraftClient& client;	// 20
	char filler2[140 - 24];		// 24
	std::string msg;			// 140
	
	static std::deque<std::string> sentMessages;
	
	void sendChatMessage();
	void init();
};
