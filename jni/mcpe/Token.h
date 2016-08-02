#pragma once

#include <string>
#include <vector>

struct Token {
	typedef std::vector<Token> List;
	
	enum class Type : int {
		String,
		Number,
	};
	
	Token(const std::string&);
	
	void _parseRandom();
	bool compatibleWith(Token::Type) const;
	bool getBool(bool) const;
	std::string getText(const std::string&) const;
	int getValue(int) const;
	
	static Token::List tokenize(const std::string&);
};