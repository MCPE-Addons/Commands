#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <memory>
#include "Substrate.h"

#include "ClientCommands.h"
#include "ServerCommands.h"
#include "mcpe/ExternalFileLevelStorageSource.h"
#include "mcpe/File.h"
#include "mcpe/LevelData.h"
#include "mcpe/LevelSettings.h"
#include "mcpe/Minecraft.h"
#include "mcpe/MinecraftClient.h"
#include "mcpe/ServerCommandParser.h"
#include "mcpe/Util.h"

#define LOG_TAG "Commands"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

MinecraftClient* mcclient_inst = NULL;

static void (*MinecraftClient$init_real)(MinecraftClient*);
static void MinecraftClient$init_hook(MinecraftClient* client) {
	mcclient_inst = client;
	MinecraftClient$init_real(client);
}

std::string BackupWorld(std::vector<Token> const& args) {
	std::string levelPath = mcclient_inst->getServer()->getLevel()->getLevelStorage()->getFullPath();
	std::string newLevelPath = levelPath + "-b";
	File::copyDirectory(levelPath, newLevelPath);
	std::vector<std::string> path = Util::split(mcclient_inst->getServer()->getLevel()->getLevelStorage()->getFullPath() + "-b", '/');
	std::string levelFolder(path[path.size() - 1]);
	return "§aSuccessfully made a backup of your world! (World is located at minecraftWorlds/" + levelFolder + ")";
}

static void (*InGamePlayScreen$_init_real)(void*, int, int);
static void InGamePlayScreen$_init_hook(void* screen, int a, int aa) {
	InGamePlayScreen$_init_real(screen, a, aa);
	
	ClientCommands::setupDebug(*(mcclient_inst->getServer()->getCommandParser()), *(mcclient_inst->getOptions()));
	ClientCommands::setupStandard(*(mcclient_inst->getServer()->getCommandParser()), *(mcclient_inst->getLocalPlayer()), *(mcclient_inst->getTextures()), *(mcclient_inst->getLevelArchiver()), *(mcclient_inst->getServer()->getGameMode()));
	ClientCommands::setupProfiling(*(mcclient_inst->getServer()->getCommandParser()), *(mcclient_inst->getOptions()));
	ServerCommands::setupStandardServer(*(mcclient_inst->getServer()->getCommandParser()), *(mcclient_inst->getServer()->getLevel()));
	mcclient_inst->getServer()->getCommandParser()->addCommand("backup", "", BackupWorld);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	LOGI("JNI_OnLoad started!");
	MSHookFunction((void*) &MinecraftClient::init, (void*) &MinecraftClient$init_hook, (void**) &MinecraftClient$init_real);
	MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN16InGamePlayScreen5_initEii"), (void*) &InGamePlayScreen$_init_hook, (void**) &InGamePlayScreen$_init_real);
	LOGI("JNI_OnLoad finished!");
	return JNI_VERSION_1_2;
}
