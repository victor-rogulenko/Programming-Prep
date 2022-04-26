// LeetCode: 242-Valid-Anagram.cpp
// Created by Victor Rogulenko
// [2022-04-26 17:30]

#include <algorithm>
#include <iostream>
#include <string>

bool isAnagram(std::string s, std::string t) {
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	return s == t;
}

int main() {
	std::string s, t;
	std::cin >> s >> t;
	std::cout << isAnagram(s, t);
	return 0;
}