#pragma once

struct Weather {
	char filler1[32];		// 0-32; filling includes vtable
	float rainLevel;		// 32-36
	char filler2[44 - 36];	// 36-44
	float lightningLevel;	// 44-48
	float fogLevel;			// 48-52
	int skyFlashTime;		// 52-56
};