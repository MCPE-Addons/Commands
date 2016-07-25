#pragma once

#include "Abilities.h"
#include "Mob.h"

struct Player : public Mob {
	char filler1[3324]; 	// 0-3324
	Abilities abilities;	// 3324-3328
};