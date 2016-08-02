#pragma once

struct Item;
namespace Json {
	struct Value;
}
struct ItemInstance;
struct Player;
struct BlockPos;
struct Vec3;

struct SeedItemComponent {
	Item& item;					// 0-4
	unsigned char crop_result;	// 4-5
	unsigned char plant_at;		// 5-6
	// crop_result and plant_at are actually BlockID's,
	// but size is obligatory 1, so I won't take any
	// chances into it. Besides, using an unsigned char
	// instead of a BlockID won't cause any trouble when
	// using it.
	
	SeedItemComponent(Item&);
	void init(Json::Value&);
	void useOn(ItemInstance&, Player&, const BlockPos&, signed char, const Vec3&);
};