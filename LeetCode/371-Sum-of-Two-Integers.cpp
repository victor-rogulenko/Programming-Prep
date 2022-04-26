// LeetCode: 371-Sum-of-Two-Integers.cpp
// Created by Victor Rogulenko
// [2022-04-26 17:45]	

#include <bitset>
#include <iostream>

void print_binary_and_int(int input) {
	std::cout << input << ": " << std::bitset<32>(input) << std::endl;
}

int getSum(int a, int b){
	// casting negative numbers to unsigned int
	// to avoid shifting left a negative value;
	long long unsigned int temp_val;
	while (b != 0) {
		temp_val = (long long unsigned int)(a & b) << 1;
		a = a ^ b;
		b = int(temp_val);
	}
	return a;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << getSum(a, b);
}