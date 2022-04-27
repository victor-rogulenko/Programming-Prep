// 14-Longest-Common-Prefix.cpp
// Created by Victor Rogulenko
// [2022-04-27 20:29]

#include <iostream>
#include <string>
#include <vector>

bool isSameChar(size_t ind, const std::vector<std::string>& strs) {
	char current_char = (char) 0;
	for (auto& str : strs) {
		if (str.size() <= ind) {
			return false;
		}
		if (current_char == (char) 0) {
			current_char = str[ind];
		} else if (current_char != str[ind]) {
			return false;
		}
	}
	return true;
}

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
	size_t ind = 0;
	std::string result = "";
	while (ind < (*strs.begin()).size()) {
		if (isSameChar(ind, strs)) {
			result += (*strs.begin())[ind];
		} else {
			break;
		}
		++ind;
	}
	return result;
}

std::vector<std::string> ReadStrings(std::istream& stream = std::cin) {
	size_t num;
	stream >> num;
	std::vector<std::string> result(num);
	for (auto& str : result) {
		stream >> str;
	}
	return result;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::vector<std::string> strs = ReadStrings();
	std::string result = longestCommonPrefix(strs);
	std::cout << result;
}