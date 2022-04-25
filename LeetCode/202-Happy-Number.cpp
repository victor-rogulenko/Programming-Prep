// LeetCode: 202-Happy-Number.cpp
// Created by Victor Rogulenko
// [2022-04-25 16:21]

#include <iostream>

const int MAXITER = 50;

int convert(int start) {
	int result = 0;
	while (start > 0) {
		int digit = start % 10;
		result += digit * digit;
		start = start / 10;
	}
	return result;
}

bool isHappy(int start) {
	int iter = 0;
	while (iter < MAXITER) {
		start = convert(start);
		std::cout << start << std::endl;
		if (start == 1) {
			return true;
		}
		if (start == 4) {
			return false;
		}
		iter++;
	}
	return false;
}

int main() {
	int num;
	std::cin >> num;
	std::cout << checkLucky(num);
	return 0;
}