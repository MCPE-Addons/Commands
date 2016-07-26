#pragma once

#include <string>

#include "ContainerType.h"
#include "ItemInstance.h"

class ContainerListener;

struct Container {
	ContainerType type;					// 4-8
	char thingsIdontCareAbout[36 - 8];	// 8-36
	std::string customName;				// 36-40
	bool hasCName;						// 40-44
	
	virtual ~Container();
	virtual void addListener(ContainerListener*);
	virtual void removeListener(ContainerListener*);
	virtual void* getItem(int) const = 0;
	virtual void addItem(ItemInstance*);
	virtual void addItemToFirstEmptySlot(ItemInstance*);
	virtual void setItem(int, ItemInstance*) = 0;
	virtual void removeItem(int, int) = 0;
};