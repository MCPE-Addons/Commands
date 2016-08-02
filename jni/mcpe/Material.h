#pragma once

#include <vector>
#include <memory>

enum class MaterialType : int {
	DIRT = 1,
	WOOD,
	STONE,
	IRON,
	WATER,
	LAVA,
	WOOL,
	DECORATION = 8,
	PLANT,
	SAND = 14,
	TORCH,
	PORTAL = 25,
	CIRCUIT = 28,
	LAMP = 30,
};

struct Material {
	MaterialType type;		// 0
	bool flammable;			// 4
	bool neverBuildable;	// 5
	bool alwaysDestroyable;	// 6
	bool replaceable;		// 7
	bool liquid;			// 8
	float traslucency;		// 12
	bool blockingMotion;	// 16
	bool solid;				// 17
	bool superHot;			// 18
	
	enum Settings : int {
		Default
	};
	
	static std::vector<std::unique_ptr<Material>> mMaterials;
	
	//Material(MaterialType, Material::Settings, float);
	
	static void addMaterial(std::unique_ptr<Material>);
	static void _setupSurfaceMaterials();
	static Material& getMaterial(MaterialType);
};
