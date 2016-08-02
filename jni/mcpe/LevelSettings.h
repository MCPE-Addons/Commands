#pragma once

struct LevelSettings {
	unsigned int seed;		// 0
	int gametype;			// 4
	int generatortype;		// 8
	bool loadedInCreative;	// 12
	int a;					// 16
	int dayCycleStopTime;	// 20
	bool eduWorld;			// 24
	int b;					// 28
	int c;					// 32
};