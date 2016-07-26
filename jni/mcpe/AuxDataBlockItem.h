#pragma once

#include "BlockItem.h"

// Size: 68
struct AuxDataBlockItem : public BlockItem {
	Block* block;	// 64-68
	
	AuxDataBlockItem(const std::string&, int, Block*);
	
	virtual ~AuxDataBlockItem();
	virtual int getLevelDataForAuxValue(int);
	virtual std::string buildDescriptionName(const ItemInstance&) const;
};