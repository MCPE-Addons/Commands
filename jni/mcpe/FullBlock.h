#pragma once

#include "BlockID.h"

// Size: 5
struct FullBlock {
	BlockID id;			// 0-4
	unsigned char aux;	// 4-5
	
	Block* getBlock() const;
	
	FullBlock() : id(0), aux(0) {};
	FullBlock(BlockID id, unsigned char aux) : id(id), aux(aux) {}
	
	static FullBlock AIR;
};