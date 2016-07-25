#pragma once

#include <vector>

#include "LevelStorage.h"

struct LevelSummary;
class ProgressListener;

// Size: 8
class ExternalFileLevelStorageSource {
public:
	std::string basePath;	// 4-8
	
	virtual ~ExternalFileLevelStorageSource();
	virtual std::string getName();
	virtual void getLevelList(std::vector<LevelSummary>&);
	virtual LevelData& getLevelData(const std::string&);
	virtual void setLevelData(const std::string&, const LevelData&);
	virtual LevelStorage* createLevelStorage(const std::string&);
	virtual bool isNewLevelIdAcceptable(const std::string&);
	virtual void clearAll();
	virtual void deleteLevel(const std::string&);
	virtual void renameLevel(const std::string&, const std::string&);
	virtual void copyLevelFromFilePath(const std::string&);
	virtual bool isConvertible(const std::string&);
	virtual bool requiresConversion(const std::string&);
	virtual bool convertLevel(const std::string&, ProgressListener*);
	virtual std::string getBasePath() const;
	
	ExternalFileLevelStorageSource(const std::string&);
	
	void _getFullPath(const std::string&);
	void _getFullPath(const std::string&) const;
	void addLevelSummaryIfExists(std::vector<LevelSummary>&, const std::string&);
};