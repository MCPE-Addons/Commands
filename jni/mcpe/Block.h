#pragma once

#include <string>
#include <vector>

#include "AABB.h"
#include "Brightness.h"
#include "Color.h"
#include "Material.h"
#include "TextureUVCoordinateSet.h"

struct BlockSource;
struct BlockPos;
class Random;
struct Entity;
struct AABB;
struct Container;
struct Vec3;
struct ItemInstance;
struct FullBlock;
struct Mob;
struct Player;
struct HitResult;
struct TextureAtlasTextureItem;

// Size: 152
struct Block {
	class SoundType {
	public:
		float volume;			// 0
		float pitch;			// 4
		std::string stepSound;	// 8
		std::string jumpSound;	// 12
		std::string breakSound;	// 16
		std::string placeSound;	// 20
		
		SoundType(const std::string&, float, float);
		SoundType(const std::string&, const std::string&, float, float);
		SoundType(const std::string&, const std::string&, const std::string&, float, float);
		
		std::string getBreakSound() const;
		std::string getJumpSound() const;
		float getPitch() const;
		std::string getPlaceSound() const;
		std::string getStepSound() const;
		float getVolume() const;
	};
	
	//void** vtable;			// 0-4
	unsigned char blockId;		// 4-8
	int facesIsotropic;			// 8-12
	std::string desc;			// 12-16
	TextureUVCoordinateSet tex;	// 16-20
	char filler1[40 - 20];		// 20-40
	Block::SoundType sound;		// 40-44
	int filler2;				// 44-48
	int renderLayer;			// 48-52
	int blockShape;				// 52-56
	int properties;				// 56-60
	int blockEntityType;		// 60-64
	char filler3[72 - 64];		// 64-72
	float thickness;			// 72-76
	bool slide;					// 76-77
	bool instatick;				// 77-80
	float gravity;				// 80-84
	Material material;			// 84-88
	Color color;				// 88-92
	char filler4[104 - 92];		// 92-104
	float friction;				// 104-108
	bool heavy;					// 108-112
	float destroySpeed;			// 112-116
	float explosionResistance;	// 116-120
	int creativeCategory;		// 120-124
	AABB shape;					// 124-128
	
	static const Block::SoundType SOUND_WOOD;
	
	virtual ~Block();
	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual void* getCollisionShape(AABB&, BlockSource&, const BlockPos&, Entity*);
	virtual bool isObstructingChests(BlockSource&, const BlockPos&);
	virtual void* randomlyModifyPosition(const BlockPos&, int&) const;
	virtual void* randomlyModifyPosition(const BlockPos&) const;
	virtual const TextureUVCoordinateSet& getCarriedTexture(signed char, int);
	virtual void addAABBs(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&);
	virtual void* getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int);
	virtual void addCollisionShapes(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&, Entity*);
	virtual bool isCropBlock() const;
	virtual bool isContainerBlock() const;
	virtual bool isCraftingBlock() const;
	virtual bool isInteractiveBlock() const;
	virtual bool isWaterBlocking() const;
	virtual bool isHurtableBlock() const;
	virtual bool isDoorBlock() const;
	virtual bool isRedstoneBlock() const;
	virtual bool isRedstoneAttachable() const;
	virtual bool isSignalSource() const;
	virtual bool getDirectSignal(BlockSource&, const BlockPos&, int);
	virtual bool waterSpreadCausesSpawn() const;
	virtual void handleRain(BlockSource&, const BlockPos&, float) const;
	virtual float getThickness() const;
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&);
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual void onRemove(BlockSource&, const BlockPos&);
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*);
	virtual void onStepOn(Entity&, const BlockPos&);
	virtual void onFallOn(BlockSource&, const BlockPos&, Entity*, float);
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool);
	virtual void onLoaded(BlockSource&, const BlockPos&);
	virtual int getRedstoneProperty(BlockSource&, const BlockPos&);
	virtual void* updateEntityAfterFallOn(Entity&);
	virtual bool onFertilized(BlockSource&, const BlockPos&, Player*);
	virtual bool mayConsumeFertilizer(BlockSource&);
	virtual bool mayPick();
	virtual bool mayPick(BlockSource&, int, bool);
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char);
	virtual bool mayPlace(BlockSource&, const BlockPos&);
	virtual bool mayPlaceOn(const Block&);
	virtual void tryToPlace(BlockSource&, const BlockPos&, unsigned char);
	virtual void destroy(BlockSource&, const BlockPos&, int, Entity*);
	virtual void* playerWillDestroy(Player&, const BlockPos&, int);
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual bool getSecondPart(BlockSource&, const BlockPos&, BlockPos&);
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, int) const;
	virtual float getDestroyProgress(Player&);
	virtual void spawnResources(BlockSource&, const BlockPos&, int, float, int);
	virtual void spawnBurnResources(BlockSource&, float, float, float);
	virtual float getExplosionResistance(Entity*);
	virtual HitResult clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool, int);
	virtual bool use(Player&, const BlockPos&);
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);
	virtual bool attack(Player*, const BlockPos&);
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Entity*, Vec3&);
	virtual void entityInside(BlockSource&, const BlockPos&, Entity&);
	virtual void* playerDestroy(Player*, const BlockPos&, int);
	virtual bool canSurvive(BlockSource&, const BlockPos&);
	virtual int getExperienceDrop(Random&) const;
	virtual bool canBeBuiltOver(BlockSource&, const BlockPos&) const;
	virtual void triggerEvent(BlockSource&, const BlockPos&, int, int);
	virtual int getTextureNum(int);
	virtual void getMobToSpawn(BlockSource&, const BlockPos&) const;
	virtual void* getMapColor(const FullBlock&) const;
	virtual void* getMapColor() const;
	virtual bool shouldStopFalling(Entity&);
	virtual float calcGroundFriction(Mob&, const BlockPos&) const;
	virtual bool canHaveExtraData() const;
	virtual bool hasComparatorSignal();
	virtual void* getComparatorSignal(BlockSource&, const BlockPos&, signed char, int);
	virtual bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, const AABB&) const;
	virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual const TextureUVCoordinateSet& getTexture(BlockSource&, const BlockPos&, signed char);
	virtual void* getTessellatedUVs();
	virtual int getIconYOffset() const;
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual int getColor(int) const;
	virtual int getColor(BlockSource&, const BlockPos&) const;
	virtual int getColorForParticle(BlockSource&, const BlockPos&, int) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	virtual void prepareRender(BlockSource&, const BlockPos&);
	virtual bool onGraphicsModeChanged(bool, bool, bool);
	virtual int getRenderLayer(BlockSource&, const BlockPos&) const; 
	virtual int getExtraRenderLayers();
	virtual void* getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
	virtual void* getVisualShape(unsigned char, AABB&, bool);
	virtual void animateTick(BlockSource&, const BlockPos&, Random&);
	virtual void* getDebugText(std::vector<std::string>&);
	virtual void init();
	virtual bool canBeSilkTouched() const;
	virtual ItemInstance getSilkTouchItemInstance(unsigned char);
	virtual void setVisualShape(const AABB&);
	virtual void setVisualShape(const Vec3&, const Vec3&);
	virtual void setSoundType(const Block::SoundType&);
	virtual void setLightBlock(Brightness);
	virtual void setLightEmission(float);
	virtual void setExplodeable(float);
	virtual void setDestroyTime(float);
	virtual void setFriction(float);
	virtual void setTicking(bool);
	virtual void setMapColor(const Color&);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	
	Block(const std::string&, int, const Material&);
	Block(const std::string&, int, const std::string&, const Material&);
	Block(const std::string&, int, TextureUVCoordinateSet, const Material&);
	
	void setSolid(bool);
	bool isType(const Block*) const;
	
	static Block* mBlocks[256];
	static bool mShouldTick[256];
	static bool mSolid[256];
	static uint_fast8_t mLightBlock[256];
	static float mTranslucency[256];
	static int mLightEmission[256];
	static Block* lookupByName(const std::string&, bool);
	
	static void initBlocks();
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static const TextureAtlasTextureItem& getTextureItem(const std::string&);
};
