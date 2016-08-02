#pragma once

#include <string>

#include "EntityDamageCause.h"

struct Entity;

class EntityDamageSource {
public:
	EntityDamageCause cause;	// 4-8
	
	virtual ~EntityDamageSource();
	virtual bool isEntitySource() const;
	virtual bool isChildEntitySource() const;
	virtual Entity* getDamagingEntity() const;
	virtual bool isBlockSource() const;
	virtual std::string getDeathMessage(std::string, Entity*) const;
	
	EntityDamageSource(EntityDamageCause);
};