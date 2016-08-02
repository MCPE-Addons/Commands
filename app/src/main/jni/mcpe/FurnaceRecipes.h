#pragma once

#include "ItemInstance.h"

// Size: 48
class FurnaceRecipes {
public:
	FurnaceRecipes();
	
	static FurnaceRecipes* getInstance();
	
	void addFurnaceRecipe(int, const ItemInstance&);
	void addFurnaceRecipeAuxData(short, short, const ItemInstance&);
	void clearFurnaceRecipes();
};