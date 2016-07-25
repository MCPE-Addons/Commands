#pragma once

#include "BlockSource.h"
#include "Vec2.h"
#include "Vec3.h"

struct Entity {
	char filler1[260];
	int rendererId;
	
	const Vec3& getPos() const;
	Vec2 getRotation() const;
	void setRot(const Vec2&);
	BlockSource& getRegion() const;
	long long getUniqueID() const;
};