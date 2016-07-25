#pragma once

#include <vector>

#include "Localization.h"

class I18n {
public:
	static std::string get(const std::string&);
	//static std::string get(const std::string&, std::vector<std::string> const); // hidden for overriding with Substrate
	static Localization getCurrentLanguage();
};