#pragma once

#include "TextureGroup.h"

namespace mce {
	struct Texture {};
	
	struct TexturePtr {
		mce::TextureGroup& group;	// 0-4
		mce::Texture* texture;		// 4-8
		std::string name;			// 12-16
		
		TexturePtr();
		TexturePtr(mce::TexturePtr&&);
		TexturePtr(mce::TextureGroup&, const std::string&, TextureLocation);
		
		void _deref();
		void _move(mce::TexturePtr&&);
		void* clone() const;
		void* get() const;	// returns whatever 4-8 returns
		mce::TextureGroup& getGroup();
		std::string getName() const;
		void* hashCode() const;
		void makeTemporaryWrapper(mce::Texture&);
		void onGroupDestroyed();
		void onGroupReloaded();
		
		// TODO: operators, high-priority
		TextureGroup& operator=(mce::TexturePtr&&);
		
		static const mce::TexturePtr NONE;
	};
};