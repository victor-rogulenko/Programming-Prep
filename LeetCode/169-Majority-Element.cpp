// LeetCode: 169-Majority-Element.cpp
// Created by Victor Rogulenko
// [2022-04-25 15:57]	
// Using Boyer–Moore majority vote algorithm

#include <cassert>
#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums) {
	assert(nums.size());
	bool change_result = true;
	int result;
	int ctr = 0;
	for (auto& value : nums) {
		if (change_result) {
			result = value;
			change_result = false;
		}
		if (value == result) {
			ctr++;
		} else {
			ctr--;
		}
		if (!ctr) {
			change_result = true;
		}
	}
	ctr = 0;
	for (auto& value : nums) {
		if (value == result) {
			ctr++;
		}
	}
	assert(ctr > nums.size()/2);
	return result;
};

int main() {
	int n;
	std::cin >> n;
	std::vector<int> input(n);
	for (auto& value : input) {
		std::cin >> value;
	}
	int result = majorityElement(input);
	std::cout << result << std::endl;
	return 0;
}


