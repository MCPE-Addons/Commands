#pragma once

#include "Item.h"
#include "Particle.h"

// Size: 184
struct BreakingItemParticle : public Particle {
	Item* item;	// 180-184
	
	virtual void init(const Vec3&, const Vec3&, int, ParticleEngine&);
	virtual ~BreakingItemParticle();
	virtual void render(Tessellator&, float, float, float, float, float, float);
	virtual Color getParticleLightColor(float);
};