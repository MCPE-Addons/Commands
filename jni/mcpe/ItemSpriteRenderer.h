#pragma once

#include "Item.h"
#include "TextureGroup.h"

typedef void EntityRenderer;

// Size: 236
struct ItemSpriteRenderer : public EntityRenderer {
	char filler1[148];
	Item* item;			// 148-152
	char mesh[80];		// 152-232
	bool foil;			// 232-236
	
	ItemSpriteRenderer(mce::TextureGroup&, Item*, bool);
};