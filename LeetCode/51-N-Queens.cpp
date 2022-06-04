// LeetCode: 51. N-Queens
// 51-N-Queens.cpp
// Created by Victor Rogulenko
// [2022-06-05 00:09]	

// The n-queens puzzle is the problem of placing n queens on an n x n 
// chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. 
// You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' 
// placement, where 'Q' and '.' both indicate a queen and an empty space, 
// respectively.

// 1 <= n <= 9

// MAJOR IDEA 1: Iterate through all possible n! permutations of queens. 
// Check that no 2 queens are on the same main and anti diagonals 
// (idx + jdx and idx + n - jdx, respectively)

// MAJOR IDEA 2: Store mainDiagonal, antiDiagonal, and column in binary
// cur_row is the state. Iterate over cur_column and try to put a queen there
// Then remove the queen

#include <vector>
#include <string>
#include <algorithm> // std::next_permutation

// SOLUTION 1

class Solution {
    int checkMainDiagonal[20];
    int checkAntiDiagonal[20];
    int candidate[10];
    int num_queens;
public:
    bool arrangementIsOK() {
        for (int idx = 0; idx <= 2*num_queens; ++idx) {
            checkMainDiagonal[idx] = false;
            checkAntiDiagonal[idx] = false;
        }
        
        for (int idx = 0; idx < num_queens; ++idx) {
            int mainDiagonalValue = candidate[idx] + idx;
            int antiDiagonalValue = candidate[idx] + (num_queens - idx);
            if ((checkMainDiagonal[mainDiagonalValue]) || 
                (checkAntiDiagonal[antiDiagonalValue])) {
                return false;
            }
            checkMainDiagonal[mainDiagonalValue] = true;
            checkAntiDiagonal[antiDiagonalValue] = true;
        }
        
        return true;
    }
    
    std::vector<std::string> printArrangement() {
        std::vector<std::string> result(num_queens, std::string(num_queens, '.'));
        
        for (int idx = 0; idx < num_queens; ++idx) {
            result[idx][candidate[idx]] = 'Q';
        }
        
        return result;
    }
    
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        num_queens = n;
        
        int num_candidates = 1;
        for (int idx = 0; idx < n; ++idx) {
            candidate[idx] = idx;
            num_candidates *= (idx+1);
        }
        
        for (int cnt = 0; cnt < num_candidates; ++cnt) {
            if (arrangementIsOK()) {
                result.push_back(printArrangement());
            }
            std::next_permutation(candidate, candidate + n);
        }

        return result;
    }
};

// #bugs = 1

// n = 1 -> 1 solution
// n = 2 -> no solutions
// n = 3 -> no solutions
// n = 4 -> 2 solutions
// n = 5 -> 8 solutions?

// SOLUTION 2

class SolutionTwo {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> candidate;
    long long mainDiagonal = 0, antiDiagonal = 0, column = 0;
    int num_queens;
public:    
    void buildNextSolution(int cur_row) {
        if (cur_row == num_queens) {
            result.push_back(candidate);
        }
        
        for (int cur_column = 0; cur_column < num_queens; ++cur_column) {
            // Check that we can place a queen in [cur_row][cur_column]
            if ((((1 << cur_column) & column) == 0) && 
                 (((1LL << (cur_row + cur_column)) & mainDiagonal) == 0) && 
                 (((1LL << (cur_row + num_queens - cur_column)) & antiDiagonal) == 0)) {
                // Put queen into [cur_row][cur_column]. See if it works
                column |= (1 << cur_column);
                mainDiagonal |= (1LL << (cur_row + cur_column));
                antiDiagonal |= (1LL << (cur_row + num_queens - cur_column));
                candidate[cur_row][cur_column] = 'Q';
                
                buildNextSolution(cur_row + 1);
                
                // Remove queen from [cur_row][cur_column]
                column ^= (1 << cur_column);
                mainDiagonal ^= (1LL << (cur_row + cur_column));
                antiDiagonal ^= (1LL << (cur_row + num_queens - cur_column));
                candidate[cur_row][cur_column] = '.';
            }
        }      
    }
    
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        num_queens = n;
        candidate = std::vector<std::string>(n, std::string(n, '.'));
        int cur_row = 0;
        buildNextSolution(cur_row);
        return result;
    }
};