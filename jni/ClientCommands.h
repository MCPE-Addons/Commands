#pragma once

class ServerCommandParser;
class Options;
struct LocalPlayer;
namespace mce {
	class TextureGroup;
};
class LevelArchiver;
class GameMode;
class MinecraftClient;

class ClientCommands {
public:
	static void setupDebug(ServerCommandParser&, Options&);
	static void setupDebugLog(ServerCommandParser&, Options&);
	static void setupStandard(ServerCommandParser&, LocalPlayer&, mce::TextureGroup&, LevelArchiver&, GameMode&);
	static void setupProfiling(ServerCommandParser&, Options&);
	static void setupStartMenuScreen(ServerCommandParser&, MinecraftClient&);
};
