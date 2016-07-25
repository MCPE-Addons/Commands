#pragma once

#include <string>

struct MobEffect {
	//void** vtable;	// 0
	int id;				// 4
	bool harmful;		// 8
	int color;			// 12
	std::string descId;	// 16
	int icon;			// 20
	int durModifier;	// 24
	bool disabled;		// 28
	
	MobEffect(int, std::string, const std::string&, bool, int, int);
	// Example: MobEffect(1, "speed", "potion.moveSpeed", false, 0xAFC6, 124);
	
	static void initEffects();
	static std::unique_ptr<MobEffect> mMobEffects[32];
	//static MobEffect mMobEffects[32];
};
