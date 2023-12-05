#include <iostream>
#include <types.h>
#include <string>
#include <vector>
#include "data.hpp"

constexpr u32 maxRed   = 12;
constexpr u32 maxGreen = 13;
constexpr u32 maxBlue  = 14;

std::vector<std::string> split(const std::string &str, char seperator) {
	std::vector<std::string> ret;

	size_t index    = 0;
	size_t oldindex = 0;
	while ((index = str.find(seperator, index)) != std::string::npos) {
		std::string substr = str.substr(oldindex, index - oldindex);
		if (!substr.empty())
			ret.push_back(substr);
		oldindex = ++index;
	}
	ret.push_back(str.substr(oldindex));

	return ret;
}

u32 runGame(std::string str) {
	// Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
	std::string game = str.substr(4, str.find_first_of(':') - 4);
	u32 gameNumber   = std::stoi(game);

	str.erase(0, str.find_first_of(':') + 2);

	std::vector<std::string> rounds = split(str, ';');

	for (auto &round : rounds) {
		std::vector<std::string> objects = split(round, ',');
		for (auto &object : objects) {
			std::vector<std::string> parts = split(object, ' ');
			if (parts[1] == "blue")
				if (std::stoul(parts[0]) > maxBlue)
					return 0;
			if (parts[1] == "red")
				if (std::stoul(parts[0]) > maxRed)
					return 0;
			if (parts[1] == "green")
				if (std::stoul(parts[0]) > maxGreen)
					return 0;
		}
	}

	return gameNumber;
}

int main() {

	u32 sum = 0;
	for (auto &str : argv) {
		sum += runGame(str);
	}

	std::cout << sum << std::endl;
}
