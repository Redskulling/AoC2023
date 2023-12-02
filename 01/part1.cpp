#include <iostream>
#include <types.h>

u32 getLineNum(char *str) {
	char first = '\0';
	char last  = '\0';

	for (; *str; str++) {
		if (*str < '0' || *str > '9')
			continue;
		if (first == '\0')
			first = *str;
		last = *str;
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
