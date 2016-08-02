#pragma once

#include "AABB.h"
#include "ParticleEngine.h"
#include "TextureUVCoordinateSet.h"
#include "Vec3.h"

struct BlockSource;
namespace mce { class TexturePtr; class TextureGroup; };
class Color;
class Random;
class Tessellator { public: static Tessellator instance; };

// Size: 180
struct Particle {
	//void** vtable;			// 0-4
	float cameraOffset;			// 4-8
	int lifetime;				// 8-12
	TextureUVCoordinateSet tex;	// 12-16
	char filler1[64 - 16];		// 16-64
	int oldSysTex;				// 64-68
	char filler2[88 - 68]; 		// 68-88
	ParticleType type;			// 88-92
	char filler3[108 - 92];		// 92-108
	BlockSource region;			// 108-112
	Vec3 pos;					// 112-116
	char filler4[152 - 116];	// 116-152
	AABB boundingBox;			// 152-156
	char filler5[180 - 156];	// 156-180
	
	virtual void init(const Vec3&, const Vec3&, int, ParticleEngine&) = 0;
	virtual ~Particle();
	virtual void normalTick();
	virtual void render(Tessellator&, float, float, float, float, float, float);
	virtual mce::TexturePtr getParticleTexture() const;
	virtual Color getParticleLightColor(float);
	
	static mce::TexturePtr FLAME_ATLAS, ITEMS_ATLAS, PARTICLE_ATLAS, TERRAIN_ATLAS;
	static Vec3 off, playerViewDir;
	static Random sharedRandom;
	
	Particle(BlockSource&, ParticleType);
	
	void _init(const Vec3&, const Vec3&, int, ParticleEngine&);
	void initStaticResources(mce::TextureGroup&);
	void move(const Vec3&);
	void scale(float);
	void setPos(const Vec3&);
	void setPower(float);
	void setSize(float);
};
