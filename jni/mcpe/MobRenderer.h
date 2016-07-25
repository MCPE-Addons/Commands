
#pragma once

namespace mce {
	struct TexturePtr;
};
struct Entity;

struct MobRenderer {
	mce::TexturePtr getSkinPtr(Entity&) const;
};