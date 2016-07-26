#pragma once

#include <memory>

#include "Block.h"
#include "Item.h"
#include "NBT.h"

struct ItemEnchants;
class Player;
class Level;

// Size: 20
struct ItemInstance {
	short count;						// 0-2; supposed to be a char, ain't riskin it tho
	short auxValue;						// 2-4
	bool valid;							// 4-8
	std::unique_ptr<CompoundTag> tag;	// 8-12
	Item* item;							// 12-16
	Block* block;						// 16-20
	
	static const unsigned char MAX_STACK_SIZE;
	static const std::string TAG_DISPLAY;
	static const std::string TAG_DISPLAY_NAME;
	static const std::string TAG_ENCHANTS;
	static const std::string TAG_REPAIR_COST;
	
	ItemInstance();
	ItemInstance(bool);
	ItemInstance(int, int, int);
	ItemInstance(const Block*);
	ItemInstance(const Block*, int);
	ItemInstance(const Block*, int, int);
	ItemInstance(const Item*);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Item*, int, int, const CompoundTag*);
	ItemInstance(const ItemInstance&);
	
	std::string _getHoverFormattingPrefix() const;
	void _setItem(int);
	void add(int);
	bool canDestroySpecial(Block*);
	void* clone(const ItemInstance*);
	void* cloneSafe(const ItemInstance*);
	void fromTag(const CompoundTag&);
	int getAttackDamage();
	short getAuxValue() const;
	int getBaseRepairCost() const;
	Color getColor() const;
	std::string getCustomName() const;
	short getDamageValue() const;
	float getDestroySpeed(Block*);
	std::string getEffectName() const;
	int getEnchantSlot() const;
	int getEnchantValue() const;
	ItemEnchants& getEnchantsFromUserData() const;
	std::string getFormattedHovertext(const Player&, bool) const;
	std::string getHoverName() const;
	const TextureUVCoordinateSet& getIcon(int, bool) const;
	int getId() const;
	int getIdAux() const;
	int getIdAuxEnchanted() const;
	int getMaxDamage() const;
	unsigned char getMaxStackSize() const;
	int getMaxUseDuration() const;
	std::string getName() const;
	void* getNetworkUserData() const;
	UseAnimation getUseAnimation() const;
	std::unique_ptr<CompoundTag> getUserData() const;
	bool hasCustomHoverName() const;
	bool hasSameUserData(const ItemInstance&) const;
	bool hasUserData() const;
	void hurtAndBreak(int, Mob*);
	void hurtEnemy(Mob*, Mob*);
	void init(int, int, int);
	void interactEnemy(Mob*, Player*);
	void inventoryTick(Level&, Entity&, int, bool);
	bool isArmorItem(const ItemInstance*);
	bool isDamageableItem() const;
	bool isDamaged() const;
	bool isEnchanted() const;
	bool isEnchantingBook() const;
	bool isFullStack() const;
	bool isGlint() const;
	bool isHorseArmorItem(const ItemInstance*);
	bool isItem(const ItemInstance*);
	bool isLiquidClipItem();
	bool isNull() const;
	bool isPotionItem(const ItemInstance*);
	bool isStackable(const ItemInstance*, const ItemInstance*);
	bool isStackable() const;
	bool isStackedByData() const;
	bool isThrowable() const;
	bool isWearableItem(const ItemInstance*);
	void load(const CompoundTag&);
	bool matches(const ItemInstance*) const;
	static bool matches(const ItemInstance*, const ItemInstance*);
	static bool matchesNulls(const ItemInstance*, const ItemInstance*);
	void mineBlock(BlockID, int, int, int, Mob*);
	void onCraftedBy(Level&, Player&);
	bool operator!=(const ItemInstance&) const;
	const ItemInstance& operator=(const ItemInstance&);
	bool operator==(const ItemInstance&) const;
	void releaseUsing(Player*, int);
	void remove(int);
	void resetHoverName();
	bool sameItemAndAux(const ItemInstance*) const;
	std::unique_ptr<CompoundTag> save();
	void saveEnchantsToUserData(const ItemEnchants&);
	void set(int);
	void setAuxValue(short);
	void setCustomName(const std::string&);
	void setDescriptionId(const std::string&);
	void setNull();
	void setRepairCost(int);
	void setUserData(std::unique_ptr<CompoundTag>);
	void snap(Player*);
	std::string toString() const;
	bool use(Player&);
	bool useAsFuel();
	void useOn(Player*, int, int, int, signed char, float, float, float);
	void useTimeDepleted(Level*, Player*);
};