#pragma once

#include <string>

class File {
public:
	static void copyDirectory(const std::string&, const std::string&);
	static void createFolder(const std::string&);
	static void deleteDirectory(const std::string&, bool);
	static bool exists(const std::string&);
};