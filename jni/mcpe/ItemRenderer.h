#pragma once

namespace mce {
	class TextureGroup;
	struct TexturePtr;
};
struct Item;
struct ItemInstance;

struct ItemRenderer {
	void createSingleton(mce::TextureGroup&);
	
	static const mce::TexturePtr& getGraphics(const Item&);
	//static const mce::TexturePtr& getGraphics(const ItemInstance&);
	
	static ItemRenderer& instance;
};