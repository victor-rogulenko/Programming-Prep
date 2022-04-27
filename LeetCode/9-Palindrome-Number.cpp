// LeetCode: 9-Palindrome-Number.cpp
// Created by Victor Rogulenko
// [2022-04-27 20:17]	

#include <iostream>
#include <string>

bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	std::string converted_int = std::to_string(x);
	auto start_it = converted_int.begin();
	auto finish_it = converted_int.end();
	while (start_it < finish_it) {
		--finish_it;
		if (*start_it != *finish_it) {
			return false;
		}
		++start_it;
	}
	return true;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int number;
	std::cin >> number;
	std::cout << isPalindrome(number);
}