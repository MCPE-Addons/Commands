#pragma once

#include "EntityType.h"

struct Entity;
struct Mob;

class EntityClassTree {
public:
	static void* getEntityTypeIdLegacy(EntityType);
	static void* getMobCategory(EntityType);
	static bool isHangingEntity(const Entity&);
	static bool isInstanceOf(const Entity&, EntityType);
	static bool isItemEntity(const Entity&);
	static bool isMinecart(const Entity&);
	static bool isMob(const Mob&);
	static bool isMob(EntityType);
	static bool isMobLegacy(EntityType);
	static bool isOfType(EntityType, EntityType);
	static bool isPlayer(const Entity&);
	static bool isTypeInstanceOf(EntityType, EntityType);
};