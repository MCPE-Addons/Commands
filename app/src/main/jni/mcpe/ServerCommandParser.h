#pragma once

#include <functional>

#include "Token.h"

class ServerCommandParser {
public:
	class Command {
	public:
		Command(std::function<std::string (std::vector<Token> const&)> const&, const std::string&);
		
		void checkParameters(std::vector<Token> const&);
	};
	
	void addCommand(const std::string&, const std::string&, std::function<std::string(std::vector<Token> const&)> const&);
	void clear();
	void executeCommand(const std::string&, std::string);
	void result(const std::string&);
};
