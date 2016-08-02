#pragma once

struct Level;
struct Block;
struct BlockEntity;
class Dimension;

struct BlockSource {
	Level* getLevel();
	Block* getBlock(int, int, int);
	BlockEntity* getBlockEntity(int, int, int);
	Dimension* getDimension();
	//Dimension* getDimension() const;
};