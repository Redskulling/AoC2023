#include <iomanip>
#include <iostream>
#include <types.h>
#include <string>
#include <vector>
#include <split.hpp>
#include "data.hpp"

// // clang-format off
// const std::string data[] = {
// 	"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
// 	"Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
// 	"Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
// 	"Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
// 	"Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
// 	"Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11",
// };
// // clang-format on

std::vector<u32> getValues(const std::string &str) {
	size_t index = 0;
	while (str[index] < '0' || str[index] > '9')
		index++;
	std::vector<u32> values;
	u32 value = 0;
	while (index < str.size()) {
		if (str[index] >= '0' && str[index] <= '9') {
			value *= 10;
			value += str[index] - '0';
			index++;
		} else {
			values.push_back(value);
			value = 0;
			while (index < str.size() && (str[index] < '0' || str[index] > '9'))
				index++;
		}
	}

	if (value)
		values.push_back(value);

	return values;
}

u32 getValue(std::string str) {
	str.erase(0, str.find_first_of(':') + 2);

	std::vector<std::string> values = split(str, '|');
	std::vector<u32> win            = getValues(values[0]);
	std::vector<u32> card           = getValues(values[1]);

	u32 value = 0;

	for (auto w : win) {
		u32 oV = value;
		for (auto c : card) {
			if (w == c) {
				value++;
				std::cout << std::setw(2) << w << ' ';
				break;
			}
		}
		if (value == oV)
			std::cout << "\033[0;31m" << std::setw(2) << w << " \033[0;0m";
	}

	return value;
}

int main() {
	std::vector<u32> counts(sizeof(data) / sizeof(*data), 1);

	u32 sum = counts.size();

	for (size_t i = 0; i < counts.size(); i++) {
		std::cout << std::setw(2) << counts[i] << " | ";
		u32 value = getValue(data[i]);
		sum += value * counts[i];
		std::cout << ", " << value * counts[i] << " : " << sum << std::endl;
		for (size_t j = 0; j < value; j++) {
			counts[i + j + 1] += counts[i];
		}
	}

	std::cout << sum << std::endl;
}
