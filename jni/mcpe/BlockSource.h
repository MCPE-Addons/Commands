#pragma once

struct Level;
struct Block;
struct BlockEntity;

struct BlockSource {
	Level* getLevel();
	Block* getBlock(int, int, int);
	BlockEntity* getBlockEntity(int, int, int);
};