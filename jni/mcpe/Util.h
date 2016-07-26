#pragma once

#include <string>
#include <vector>

class Util {
public:
	static std::string EMPTY_STRING;
	
	static std::string base64_decode(const std::string&);
	static std::string base64_encode(const std::string&, bool);
	static std::string base64_encode(const unsigned char*, unsigned int, bool);
	static void compareNoCase(const std::string&, const std::string&);
	static void countWordOcurrences(const std::string&, const std::string&);
	static bool endsWith(const std::string&, const std::string&);
	static void format(const char*, ...);
	static void formatTickDuration(int);
	static void freeStringMemory(std::string&);
	static void getBezier(float, float, float, float);
	static void getDirectory(const std::string&);
	static void getExtension(const std::string&);
	static void getFileName(const std::string&);
	static void getPoint(float, float, float);
	static void hashCode(const std::string&);
	static bool isValidPath(const std::string&);
	static void removeAll(std::string&, const char**, int);
	static void removeIllegalChars(const std::string&);
	static void simpleFormat(const std::string&, std::vector<std::string>);
	static std::vector<std::string> split(const std::string&, char);
	static std::vector<std::string> split(const std::string&, std::vector<std::string> const&, bool);
	static std::vector<std::string> splitString(const std::string&, char, std::vector<std::string>&);
	static bool startsWith(const std::string&, const std::string&);
	static bool stringContains(const std::string&, char);
	static void stringReplace(std::string&, const std::string&, const std::string&, int);
	static void stringTrim(const std::string&);
	static void stringTrim(const std::string&, const std::string&, bool, bool);
	static void toBool(const std::string&, bool&);
	static void toHex(char);
	static void toInt(const std::string&, int&, int, int);
	static std::string toLower(const std::string&);
	static std::string toNiceString(int);
	/*
	static std::string toString(float);
	static std::string toString(std::basic_string<wchar_t, std::char_traits<wchar_t>> const&);
	static std::string toString(const std::string&);
	static std::string toString<int, (void*)0, (void*)0>(int);
	static std::string toString<long long, (void*)0, (void*)0>(long long);
	static std::string toString<short, (void*)0, (void*)0>(short);
	static std::string toString<unsigned char, (void*)0, (void*)0>(unsigned char);
	static std::string toString<unsigned int, (void*)0, (void*)0>(unsigned int);
	static std::string toString<unsigned long long, (void*)0, (void*)0>(unsigned long long);
	static std::string toString<unsigned short, (void*)0, (void*)0>(unsigned short);
	*/
	static std::string toUpper(const std::string&);
	static void toWideString(const std::string&);
	static void urlEncode(const std::string&);
	static void utf8len(const std::string&, bool);
	static void utf8substring(const std::string&, int, int);
};
