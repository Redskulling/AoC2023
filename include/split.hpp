#ifndef SPLIT_HPP
#define SPLIT_HPP

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

#endif // SPLIT_HPP