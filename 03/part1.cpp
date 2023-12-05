#include <iostream>
#include <types.h>
#include <string>
#include <vector>
#include <array>
#include "data.hpp"

bool isNumber(const char c) {
	return (c >= '0' && c <= '9');
}

bool isSymbol(const char c) {
	return (!isNumber(c) && c != '.');
}

template <size_t size>
bool connectedToSymbol(const std::array<std::string, size> &data, size_t x, size_t y) {
	s32 ymin = -1;
	s32 ymax = 1;
	s32 xmin = -1;
	s32 xmax = 1;
	if (y == 0)
		ymin = 0;
	else if (y == data.size() - 1)
		ymax = 0;
	if (x == 0)
		xmin = 0;
	else if (x == data[y].size() - 1)
		xmax = 0;
	for (s32 ypos = ymin; ypos <= ymax; ypos++) {
		for (s32 xpos = xmin; xpos <= xmax; xpos++) {
			if (isSymbol(data[y + ypos][x + xpos]))
				return true;
		}
	}
	return false;
}

template <size_t size>
size_t findConnected(const std::array<std::string, size> &data, size_t x, size_t y) {
	if (x && isNumber(data[y][x - 1]))
		return 0;

	std::string number;
	for (size_t xpos = x; isNumber(data[y][xpos]); xpos++) {
		number += data[y][xpos];
	}

	for (size_t xpos = 0; xpos < number.size(); xpos++) {
		if (connectedToSymbol(data, x + xpos, y))
			return std::stoi(number);
	}
	return 0;
}

int main() {
	size_t sum = 0;
	for (size_t y = 0; y < data.size(); y++) {
		for (size_t x = 0; x < data[y].size(); x++) {
			sum += findConnected(data, x, y);
		}
	}

	std::cout << sum << std::endl;
}
