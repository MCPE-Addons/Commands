#pragma once

#include <string>

enum class EntityType {};

EntityType EntityTypeFromString(const std::string&);
const std::string& EntityTypeToString(EntityType);