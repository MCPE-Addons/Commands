#pragma once

// Size: 1
struct BlockID {
	unsigned char id;	// 0-1
	
	BlockID() : id(0) {}
	BlockID(unsigned char id) : id(id) {}
	BlockID(const BlockID& other) { id = other.id; }
	
	static BlockID AIR;
};
