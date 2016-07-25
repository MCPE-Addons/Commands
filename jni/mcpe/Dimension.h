#pragma once

#include "Weather.h"

struct Dimension {
	char filler1[100];	// 0-100
	Weather weather;	// 100-104
};