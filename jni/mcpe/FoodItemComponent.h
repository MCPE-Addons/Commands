#pragma once

#include <vector>
#include <string>

class Item;
struct ItemInstance;
struct Player;
struct BlockPos;
struct Level;
struct Vec3;
namespace Json {
	struct Value;
};

// Size: 36
struct FoodItemComponent {
	struct Effect {};
	
	Item& item;										// 0-4
	int nutrition;									// 4-8
	float saturationModifier;						// 8-12
	bool meat;										// 12-16
	std::string eat_sound;							// 16-20
	std::string using_converts_to;					// 20-24
	std::vector<FoodItemComponent::Effect> effects;	// 24-36
	
	FoodItemComponent(Item&);
	void _applyEatEffects(ItemInstance&, Player&, Level&);
	void _loadEffects(std::vector<FoodItemComponent::Effect>&, Json::Value&);
	int getNutrition() const;
	float getSaturationModifier() const;
	void init(Json::Value&);
	bool use(ItemInstance&, Player&);
	void useOn(ItemInstance&, Player&, const BlockPos&, signed char, const Vec3&);
	void useTimeDepleted(ItemInstance&, Player&, Level&);
};
