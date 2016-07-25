#pragma once

struct TextureUVCoordinateSet {
	float x0;
	float y0;
	float x1;
	float z1;
	unsigned short width;
	unsigned short height;
	int index;
	int textureFile;
	
	TextureUVCoordinateSet();
	
	bool operator==(const TextureUVCoordinateSet& other) const { // omgomgomg code inside a header. call da police
		return this->x0 == other.x0 && this->y0 == other.y0 && this->x1 == other.x1 && this->y1 == other.y1 && this->width == other.width && this->height == other.height && this.index == other.index && this.textureFile == other.textureFile;
	}
};