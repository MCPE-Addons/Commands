#pragma once

#include "Item.h"

enum ArmorSlot {};
class Color;

// Size: 80
struct ArmorItem : public Item {
	
	// Size: 24
	struct ArmorMaterial {
		int durabilityMultiplier;	// 0-4
		int slotProtection[4];		// 4-20
		int enchantValue;			// 20-24
		
		ArmorMaterial(int, int, int, int, int, int);
		
		int getDefenseForSlot(ArmorSlot) const;
		int getEnchantValue() const;
		int getHealthForSlot(ArmorSlot) const;
	};
	
	ArmorSlot slot;			// 64-68
	char filler3[4];		// 68-72
	ArmorMaterial material;	// 72-76
	char filler4[4];		// 76-80
	
	virtual bool isArmor() const;
	virtual void* appendFormattedHovertext(const ItemInstance&, const Player&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual Color getColor(const ItemInstance&) const;
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	
	ArmorItem(const std::string&, int, const ArmorItem::ArmorMaterial&, int, ArmorSlot);
	
	void clearColor(ItemInstance&);
	bool hasCustomColor(const ItemInstance&) const;
	void setColor(ItemInstance&, const Color&);
	
	static const int mHealthPerSlot[512];
	
	static const ArmorItem::ArmorMaterial CLOTH;
	static const ArmorItem::ArmorMaterial CHAIN;
	static const ArmorItem::ArmorMaterial IRON;
	static const ArmorItem::ArmorMaterial GOLD;
	static const ArmorItem::ArmorMaterial DIAMOND;
};
