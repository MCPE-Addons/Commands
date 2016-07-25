#pragma once

#include "BlockPos.h"
#include "Entity.h"
#include "Vec3.h"

struct HitResult {
	enum class HitResultType : unsigned char {
		Block,
		Entity,
		Nothing
	};
	
	HitResultType type;		// 0-4
	unsigned char side;		// 4-8
	char filler1[16 - 8];	// 8-16
	BlockPos blockpos;		// 16-20
	Vec3 pos;				// 20-24
	char filler2[32 - 24];	// 24-32
	Entity entity;			// 32-36
	bool indirectHit;		// 36-37
	
	HitResult();
	HitResult(Entity&);
	HitResult(const Vec3&);
	HitResult(const HitResult&);
	HitResult(Entity&, const Vec3&);
	HitResult(const BlockPos&, signed char, const Vec3&);
	
	float distanceTo(const Entity&) const;
	void setOutOfRange();
};