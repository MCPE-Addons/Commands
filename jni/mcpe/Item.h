#pragma once

#include <string>
#include <memory>

#include "Block.h"
#include "Color.h"
#include "FoodItemComponent.h"
#include "SeedItemComponent.h"

struct TextureUVCoordinateSet;
enum CreativeItemCategory {};
enum UseAnimation {};
struct ItemInstance;
struct Player;
struct BlockSource;
struct Container;
struct Vec3;
struct Level;
struct Mob;
struct BlockID;
class IDataInput;
class IDataOutput;
struct Entity;
class Json { public: class Value {}; };

// Size: 68
struct Item {
	//void** vtable;							// 0-4
	short maxStackSize;							// 4-8
	std::string atlas;							// 8-12
	char filler1[18 - 12];						// 12-18
	short id;									// 18-20
	std::string name;							// 20-24
	char filler2[60 - 24];						// 24-56
	std::unique_ptr<FoodItemComponent> food;	// 60-64
	std::unique_ptr<SeedItemComponent> seed;	// 64-68
	
	// Size: 20
	struct Tier {
		int damageFactor;	// 0-4
		int maxDamage;		// 4-8
		float whoKnows;		// 12-16
		int enchantValue;	// 16-20
		
		static const Item::Tier DIAMOND;
		static const Item::Tier GOLD;
		static const Item::Tier IRON;
		static const Item::Tier STONE;
		static const Item::Tier WOOD;
		
		ItemInstance getTierItem() const;
	};
	
	virtual ~Item();
	virtual void setIcon(const std::string&, int);
	virtual void setIcon(const TextureUVCoordinateSet&);
	virtual void setMaxStackSize(unsigned char);
	virtual void setCategory(CreativeItemCategory);
	virtual void setStackedByData(bool);
	virtual void setMaxDamage(int);
	virtual void setHandEquipped();
	virtual void setUseAnimation(UseAnimation);
	virtual void setMaxUseDuration(int);
	virtual bool canBeDepleted();
	virtual bool canDestroySpecial(const Block*) const;
	virtual void* getLevelDataForAuxValue(int) const;
	virtual bool isStackedByData() const;
	virtual int getMaxDamage();
	virtual int getAttackDamage();
	virtual bool isHandEquipped() const;
	virtual bool isArmor() const;
	virtual bool isDye() const;
	virtual bool isGlint(const ItemInstance*) const;
	virtual bool isThrowable() const;
	virtual bool canDestroyInCreative() const;
	virtual bool isLiquidClipItem(int) const;
	virtual bool requiresInteract() const;
	virtual void* appendFormattedHovertext(const ItemInstance&, const Player&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool isComplex() const;
	virtual Color getColor(const ItemInstance&) const;
	virtual bool use(ItemInstance&, Player&);
	virtual void useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	virtual void* useTimeDepleted(ItemInstance*, Level*, Player*);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual float getDestroySpeed(ItemInstance*, Block*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void interactEnemy(ItemInstance*, Mob*, Player*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual void* readUserData(ItemInstance*, IDataInput&) const;
	virtual void* writeUserData(ItemInstance const*, IDataOutput&, bool) const;
	virtual int getMaxStackSize(const ItemInstance*);
	virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool);
	virtual void onCraftedBy(ItemInstance&, Level&, Player&);
	virtual std::string getInteractText(const Player&) const;
	virtual int getAnimationFrameFor(Mob&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual bool isMirroredArt() const;
	
	Item(const std::string&, short);
	void init(Json::Value&);
	
	static Item* mItems[512];
	static std::vector<ItemInstance> mCreativeList;
	static Item* lookupByName(const std::string&, bool);
	static void addBlockItems();
	static void addCreativeItem(Block*, short);
	static void addCreativeItem(Item*, short);
	static void addCreativeItem(const ItemInstance&);
	static void addCreativeItem(short, short);
	static void initItems();
	static void teardownItems();
};