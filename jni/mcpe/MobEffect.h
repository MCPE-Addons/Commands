#pragma once

#include <string>

struct MobEffect {
	int id;				// 4-8
	bool harmful;		// 8-12
	int color;			// 12-16
	std::string descId;	// 16-20
	int iconId;			// 20-24
	int durModifier;	// 24-28
	bool disabled;		// 28-32
	
	MobEffect(int, std::string, const std::string&, bool, int, int);
	// Example: MobEffect(1, "speed", "potion.moveSpeed", false, 0xAFC6, 124);
	
	static void initEffects();
	//static std::unique_ptr<MobEffect> mMobEffects[32];
	//static MobEffect mMobEffects[32];
};
