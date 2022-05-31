// LeetCode: 1025. Divisor Game
// 1025-Divisor-Game.cpp
// Created by Victor Rogulenko
// [2022-05-31 14:03]  

// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there is a number n on the chalkboard. On each player's turn, 
// that player makes a move consisting of:
// Choosing any x with 0 < x < n and n % x == 0.
// Replacing the number n on the chalkboard with n - x.
// Also, if a player cannot make a move, they lose the game.
// Return true if and only if Alice wins the game, assuming both players 
// play optimally.

// 1 <= n <= 1000

// MAJOR IDEA: 1) Math: odd loses, even wins;
// 2) DP: For every position/value, if there's at least one transition 
// to a losing position, than the initial position if a winning one. 
// Otherwise, it's a losing one

class Solution {
public:
    bool divisorGame(int n) {
        return (n % 2 == 0);
    //     bool dp[1001];
    //     dp[0] = false;
    //     dp[1] = false;
    //     for (int idx = 2; idx <= n; ++idx) {
    //         dp[idx] = false;
    //         for (int jdx = 1; jdx <= idx/2; ++jdx) {
    //             if (idx % jdx == 0 && !dp[idx - jdx]) {
    //                 dp[idx] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp[n];
    }
};

// dp[1] = false
// dp[2] = true
// dp[3] = false
// dp[4] = true

// #bugs = 0