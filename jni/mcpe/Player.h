#pragma once

#include <string>

#include "Abilities.h"
#include "Mob.h"

struct Player : public Mob {
	char playerfiller1[3368];	// 0-3368
	std::string username;		// 3368-3372
	Abilities abilities;		// 3372-3376
};