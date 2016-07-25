#pragma once

#include <string>
#include <memory>

#include "LevelData.h"

struct ChunkSource;
enum StorageVersion {};

class LevelStorage {
public:
	virtual ~LevelStorage();
	virtual bool loadLevelData(LevelData&) = 0;
	virtual std::unique_ptr<ChunkSource> createChunkStorage(std::unique_ptr<ChunkSource>, StorageVersion) = 0;
	virtual void saveLevelData(LevelData&) = 0;
	virtual const std::string& getFullPath() const = 0;
	virtual void savePlayerData(const std::string&, std::string&&) = 0;
};
