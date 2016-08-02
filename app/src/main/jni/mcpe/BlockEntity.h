#pragma once

#include <string>
#include <vector>

#include "AABB.h"
#include "BlockEntityType.h"
#include "BlockPos.h"

struct CompoundTag;
struct BlockSource;
enum BlockEntityRendererId {};

// Size: 92
struct BlockEntity {
	BlockPos pos;								// 4-8
	char filler1[40 - 8];						// 8-40
	AABB aabb;									// 40-68
	int data;									// 68-72
	BlockEntityType type;						// 72-76
	int runningId;								// 76-80
	bool clientSideOnly;						// 80-84
	BlockEntityRendererId rendererId;			// 84-88
	bool changed;								// 88-92
	
	virtual ~BlockEntity();
	virtual void load(CompoundTag&);
	virtual void save(CompoundTag&);
	virtual void tick(BlockSource&);
	virtual bool isFinished();
	virtual void onChanged(BlockSource&);
	virtual void* getUpdatePacket(BlockSource&);
	virtual void onUpdatePacket(CompoundTag&):
	virtual void onRemoved();
	virtual void triggerEvent(int, int);
	virtual void clearCache();
	virtual void onNeighborChanged(BlockSource&, const BlockPos&);
	virtual float getShadowRadius(BlockSource&) const;
	virtual void* getCrackEntity(BlockSource&, const BlockPos&);
	virtual void* getDebugText(std::vector<std::string>&);
	
	BlockEntity(BlockEntityType, const BlockPos&, const std::string&);
	
	void _destructionWobble(float&, float&, float&);
	void _resetAABB();
	AABB& getAABB() const;
	int getData() const;
	BlockPos& getPosition() const;
	int getRendererId() const;
	int getRunningId() const;
	BlockEntityType getType() const;
	bool isClientSideOnly() const;
	bool isInWorld() const;
	bool isType(BlockEntityType);
	bool isType(BlockEntity&, BlockEntityType);
	void setBB(AABB);
	void setChanged();
	void setClientSideOnly(bool);
	void setData(int);
	void setId(BlockEntityType, const std::string&);
	void setRendererId(BlockEntityRendererId);
	void setRunningId(int);
	void stopDestroy();
	
	static std::map<std::string, BlockEntityType> idClassMap;
	static std::map<BlockEntityType, std::string> classIdMap;
	static int _runningId;
	static void initBlockEntities();
	static BlockEntity* loadStatic(CompoundTag&);
};