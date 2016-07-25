#pragma once

#include "ContainerType.h"

struct Container {
	ContainerType type;		// 4-8
	
	virtual ~Container();
};