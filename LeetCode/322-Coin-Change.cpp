// LeetCode: 322. Coin Change
// 322-Coin-Change.cpp
// Created by Victor Rogulenko
// [2022-05-21 03:56]

// You are given an integer array coins representing coins of different 
// denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. 
// If that amount of money cannot be made up by any combination of the 
// coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 2^31 - 1
// 0 <= amount <= 10^4

// MAJOR IDEA: dp over possible amounts instead of bfs (takes much longer)
// Check amt - coin >= 0 fits into int even though coins[i] <= 2^31 - 1

class Solution {  
    const int INF = (int)(1e4) + 10;
public:
    int coinChange(const std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        int numcoins[amount+1];
        numcoins[0] = 0;
        
        for (int amt = 1; amt <= amount; ++amt) {
            numcoins[amt] = INF;
            for (auto& coin : coins) {
                if (amt - coin >= 0) {
                    numcoins[amt] = std::min(numcoins[amt], 
                                             numcoins[amt - coin] + 1);
                }
            }
        }
        
        return (numcoins[amount] == INF ? -1 : numcoins[amount]);
    }
};