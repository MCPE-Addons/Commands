#pragma once

#include <memory>

#include "EntityType.h"
#include "Mob.h"

struct BlockSource;
struct Vec2;
struct Vec3;

struct MobFactory {
	static std::unique_ptr<Mob> CreateMob(EntityType, BlockSource&, const Vec3&);
};
