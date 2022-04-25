// LeetCode: 204. Count Primes.cpp
// Created by Victor Rogulenko
// [2022-04-25 17:02]

#include <cmath>
#include <iostream>
#include <vector>

const int MAXN = int(5e6)+3;
std::vector<bool> is_prime(MAXN, true);

void populateSieve(int cur_num, int max_num) {
	int limit = max_num/cur_num;
	for (auto i = 3; i <= limit; i += 2) {
		// Skip even numbers
		is_prime[i * cur_num] = false;
	}
}

void buildSieve(int max_num) {
	is_prime.resize(max_num + 1, true);
	int cur_num = 3;
	int limit = int(std::sqrt(max_num));
	while (cur_num <= limit) {
		if (is_prime[cur_num]) {
			populateSieve(cur_num, max_num);
		}
		// Skip even numbers
		cur_num += 2;
	}
}

int countPrimes(int n) {
	if (n < 3) {
		return 0;
	}
	// ctr = 1 to account for "2"
	int ctr = 1; 
	for (auto i = 3; i < n; i += 2) {
		// Skip even numbers
		ctr += is_prime[i];
		// std::cout << i << ", prime: " << is_prime[i] << std::endl;
	}
	return ctr;
}

int main() {
	int num;
	std::cin >> num;
	buildSieve(num);
	std::cout << countPrimes(num);
	return 0;
}