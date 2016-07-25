#pragma once

#include "EntityType.h"
#include "NBT.h"

// Size: 16
struct SpawnData {
	//void** vtable;							// 0-4
	int weight;									// 4-8
	EntityType type;							// 8-12
	std::unique_ptr<CompoundTag> properties;	// 12-16
	
	virtual ~SpawnData();
	
	SpawnData();
	SpawnData(const CompoundTag&);
	SpawnData(int, EntityType);
	SpawnData(int, EntityType, CompoundTag*);
	std::unique_ptr<CompoundTag> save();
};