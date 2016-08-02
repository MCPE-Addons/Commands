#pragma once

struct Particle;
enum ParticleType;
struct Entity;

class ParticleEngine {
public:
	Particle* _create(ParticleType);
	void* createTrackingEmitter(Entity&, ParticleType);
};