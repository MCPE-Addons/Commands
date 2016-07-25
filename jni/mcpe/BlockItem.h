#pragma once

#include "Item.h"

struct BlockItem : public Item {
	BlockItem(const std::string&, int);
	
	virtual ~BlockItem();
	virtual void* useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
};