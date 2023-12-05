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
	return (c == '*');
}

template <size_t size>
std::string getNumber(const std::array<std::string, size> &data, size_t x, size_t y) {
	std::string number;
	for (size_t xpos = x; isNumber(data[y][xpos]) && xpos < data[y].size(); xpos++) {
		number += data[y][xpos];
	}
	return number;
}

template <size_t size>
size_t connectedNumber(const std::array<std::string, size> &data, size_t x, size_t y) {
	s32 ymax = 1;
	s32 xmax = 1;
	s32 xmin = -1;
	s32 ymin = -1;
	if (y == 0)
		ymin = 0;
	else if (y == data.size() - 1)
		ymax = 0;
	if (x == data[y].size() - 1)
		xmax = 0;

	size_t num1 = 0;

	for (s32 ypos = ymin; ypos <= ymax; ypos++) {
		for (s32 xpos = xmin; xpos <= xmax; xpos++) {
			if (isNumber(data[y + ypos][x + xpos])) {
				if (xpos != xmin && isNumber(data[y + ypos][x + xpos - 1]))
					continue;
				s32 nxpos = xpos;
				while (isNumber(data[y + ypos][x + nxpos]) && (x + nxpos != 0))
					nxpos--;
				size_t num = std::stoul(getNumber(data, x + nxpos + 1, y + ypos));
				if (!num1)
					num1 = num;
				else
					return num1 * num;
			}
		}
		xmin = -1 + (x == 0);
	}
	return 0;
}

template <size_t size>
size_t countAroundSymbol(const std::array<std::string, size> &data, size_t x, size_t y) {
	size_t count = 0;
	s32 ymin     = -1;
	s32 ymax     = 1;
	s32 xmin     = -1;
	s32 xmax     = 1;
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
			if (isNumber(data[y + ypos][x + xpos])) {
				count++;
				size_t num = getNumber(data, x + xpos, y + ypos).size();
				xpos += num - 1;
			}
		}
	}
	return count;
}

template <size_t size>
size_t findConnected(const std::array<std::string, size> &data, size_t x, size_t y) {
	if (!isSymbol(data[y][x]))
		return 0;

	if (countAroundSymbol(data, x, y) != 2)
		return 0;

	return connectedNumber(data, x, y);
}

int main() {

	for (auto &str : data) {
		str = '.' + str;
	}

	size_t sum = 0;
	for (size_t y = 0; y < data.size(); y++) {
		for (size_t x = 0; x < data[y].size(); x++) {
			size_t num = findConnected(data, x, y);
			sum += num;
		}
	}

	std::cout << sum << std::endl;
}
