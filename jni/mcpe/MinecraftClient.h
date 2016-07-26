#pragma once

#include <memory>

#include "Minecraft.h"
#include "TextureGroup.h"

struct ScreenChooser;
class ParticleEngine;
class Options;
class LevelArchiver;
class Minecraft; // #FuckAIDE
struct LevelSettings;
class Player;

class MinecraftClient {
public:
	ScreenChooser* getScreenChooser() const;
	LocalPlayer* getLocalPlayer();
	ParticleEngine* getParticleEngine() const;
	mce::TextureGroup* getTextures() const;
	Options* getOptions();
	Minecraft* getServer();
	LevelArchiver* getLevelArchiver();
	
	void init();
	void startLocalServer(std::string, std::string, LevelSettings);
	void leaveGame(bool);
};