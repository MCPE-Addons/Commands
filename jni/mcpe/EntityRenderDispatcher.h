#pragma once

#include "ItemSpriteRenderer.h"

struct Entity;
enum EntityRendererId;

struct EntityRenderDispatcher {
	EntityRenderer* getRenderer(Entity&);
	EntityRenderer* getRenderer(EntityRendererId);
	
	static EntityRenderDispatcher* getInstance();
}; 