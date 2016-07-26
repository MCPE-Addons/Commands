#pragma once

#include <string>
#include <functional>

#include "MinecraftClient.h"

class MinecraftUISoundPlayer {};
enum UIScreenType : int { DESKTOP, POCKET };
enum CreateWorldScreenType : int { NORMAL };
enum CraftingType : int { INVENTORY, WORKBENCH };
enum WorldType {};
class SignBlockEntity;

// Size: 28; wtf?
struct ScreenChooser {
	MinecraftClient& client;		// 0-4
	MinecraftUISoundPlayer& player;	// 4-8
	bool canInvite;					// 8-12
	
	ScreenChooser(MinecraftClient&, bool);
	
	void* _getUIScreenSetupStrategy(bool);
	void _pushAchievementScreen();
	
	void pushAddExternalServerScreen();
	void pushChatScreen();
	void pushConsoleScreen();
	void pushCreateWorldScreen(CreateWorldScreenType);
	void pushDeathScreen();
	void pushDebugScreen();
	void pushGamePadLayoutScreen(bool);
	void pushGameViewerScreen();
	void pushInventoryScreen(CraftingType);
	void pushNetherProgressScreen(bool);
	void pushPauseScreen();
	void pushPortfolioScreen();
	void pushProgressScreen(WorldType, const std::string&, std::function<void()>, std::function<void()>, std::function<void()>);
	void pushTextEditScreen(SignBlockEntity*);
	void setDisconnectScreen(const std::string&, const std::string&);
	void setGameplayScreen();
	void setLeaveLevelScreen();
	void setStartMenuScreen();
};
