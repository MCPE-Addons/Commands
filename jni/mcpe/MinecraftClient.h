#pragma once

#include <memory>

#include "Minecraft.h"
#include "TextureGroup.h"

struct ScreenChooser;
class ParticleEngine;
class Options;
class LevelArchiver;
class Minecraft;
struct LevelSettings;

class MinecraftClient {
public:
	char filler1[100];
	Minecraft& minecraft;
	
	ScreenChooser* getScreenChooser() const;
	LocalPlayer* getLocalPlayer();
	ParticleEngine* getParticleEngine() const;
	mce::TextureGroup* getTextures() const;
	Options* getOptions();
	Minecraft* getServer();
	LevelArchiver* getLevelArchiver();
	
	void init();
	void startLocalServer(std::string, std::string, LevelSettings);
};
