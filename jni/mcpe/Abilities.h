#pragma once

#include "NBT.h"

struct PermissionsHandler;

struct Abilities {
	bool invulnerable;									// 0-1
	bool flying;										// 1-2
	bool mayfly;										// 2-3
	bool instabuild;									// 3-4
	bool idk;											// 4-5
	bool idk2;											// 5-6
	bool lightning;										// 6-8
	float walkSpeed;									// 8-12
	float flySpeed;										// 12-16
	std::unique_ptr<PermissionsHandler> permHandler;	// 16-20
	
	Abilities();
	void addSaveData(CompoundTag&) const;
	void loadSaveData(const CompoundTag&);
	float getFlyingSpeed() const;
	float getWalkingSpeed() const;
	void setFlyingSpeed(float);
	void setWalkingSpeed(float);
	bool isFlying() const;
};