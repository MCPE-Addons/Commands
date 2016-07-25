#pragma once

#include <string>

enum TextureLocation {};

namespace mce {
	struct TexturePtr;
	
	class TextureGroup {
	public:
		mce::TexturePtr& getTexture(const std::string&, TextureLocation);
	};
};