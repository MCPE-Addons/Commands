#pragma once

#include <memory>

#include "BlockSource.h"
#include "EntityUniqueID.h"
#include "LevelData.h"
#include "LevelStorage.h"
#include "MinecraftClient.h"
#include "Mob.h"
#include "ParticleType.h"
#include "Player.h"
#include "Vec3.h"

struct BlockPos;
struct FullBlock;
struct BlockPos;
struct MinecraftClient;
struct LocalPlayer : public Player { MinecraftClient* getMinecraftClient() const; };

struct Level {
	virtual ~Level();
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onBlockChanged(BlockSource&, const BlockPos&, FullBlock, FullBlock, int);
	virtual void addEntity(std::unique_ptr<Entity>);
	virtual void addPlayer(std::unique_ptr<Player>);
	virtual void addGlobalEntity(std::unique_ptr<Entity>);
	
	void* addParticle(ParticleType, const Vec3&, const Vec3&, int);
	void* getEntity(EntityUniqueID, bool) const;
	void* getMob(EntityUniqueID) const;
	LocalPlayer* getLocalPlayer() const;
	Player* getPlayer(EntityUniqueID) const;
	Player* getPlayer(const std::string&) const;
	LevelStorage* getLevelStorage();
	LevelData* getLevelData();
};
