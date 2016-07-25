#pragma once

#include <vector>
#include <string>

struct GuiMessage {
	int ticks;				// 0
	int maxTicks;			// 4
	std::string message;	// 8
	std::string user;		// 12
	std::string string;		// 16
	bool forceVisible;		// 20
	bool newF;				// 21
	
	GuiMessage();
	GuiMessage(const GuiMessage&);
	GuiMessage(const std::string&, const std::string&, int, bool);
	
	int getMaxTicks() const;
	std::string getMessage() const;
	void* getPercentComplete() const;
	std::string getString() const;
	int getTicks() const;
	std::string getUser() const;
	void incrementTick();
	bool isCommand() const;
	bool isDead() const;
	bool isForceVisible() const;
	bool isNew() const;
	void setOld();
};

struct GuiData {
	char filler1[132];
	std::vector<GuiMessage> messageList;
};