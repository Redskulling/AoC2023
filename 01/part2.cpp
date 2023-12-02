#include <iostream>
#include <types.h>
#include <string>

struct Skip {
	char c;
	size_t num;
};

Skip getWordNumber(const std::string &str, size_t index) {
	if (str.compare(index, 3, "one") == 0)
		return { '1', sizeof("one") - 2 - 1 };
	if (str.compare(index, 3, "two") == 0)
		return { '2', sizeof("two") - 2 - 1 };
	if (str.compare(index, 5, "three") == 0)
		return { '3', sizeof("three") - 2 - 1 };
	if (str.compare(index, 4, "four") == 0)
		return { '4', sizeof("four") - 2 }; // no overlaps
	if (str.compare(index, 4, "five") == 0)
		return { '5', sizeof("five") - 2 - 1 };
	if (str.compare(index, 3, "six") == 0)
		return { '6', sizeof("six") - 2 }; // no overlaps
	if (str.compare(index, 5, "seven") == 0)
		return { '7', sizeof("seven") - 2 - 1 };
	if (str.compare(index, 5, "eight") == 0)
		return { '8', sizeof("eight") - 2 - 1 };
	if (str.compare(index, 4, "nine") == 0)
		return { '9', sizeof("nine") - 2 - 1 };
	return { '\0', 0 };
}

u32 getLineNum(const std::string &str) {
	char first = '\0';
	char last  = '\0';

	for (size_t i = 0; i < str.size(); i++) {
		Skip res = getWordNumber(str, i);
		if (!res.num) {
			if (str[i] < '0' || str[i] > '9')
				continue;
			res.c = str[i];
		}
		if (first == '\0')
			first = res.c;
		last = res.c;
		i += res.num;
	}

	return (first - '0') * 10 + last - '0';
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <space seperated strings>" << std::endl;
		return 1;
	}

	u32 sum = 0;
	for (int i = 1; i < argc; i++) {
		sum += getLineNum(argv[i]);
	}

	std::cout << sum << std::endl;
}
