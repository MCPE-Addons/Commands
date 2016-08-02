#pragma once

#include <string>

struct LevelData {
	std::string lvlName;		// 0-4
	int storageVersion;			// 4-8
	int networkVersion;			// 8-12
	char filler1[4];			// 12-16
	long currentTick;			// 16-20
	char filler2[4];			// 20-24
	unsigned int seed;			// 24-28
	int spawnX;					// 28-32
	int spawnY;					// 32-36
	int spawnZ;					// 36-40
	int limitedWorldOriginX;	// 40-44
	int limitedWorldOriginY;	// 44-48
	int limitedWorldOriginZ;	// 48-52
	long time;					// 52-56
	long lastPlayed;			// 56-60
};