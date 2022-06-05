// LeetCode: 52. N-Queens II
// 52-N-Queens-II.cpp
// Created by Victor Rogulenko
// [2022-06-05 15:49]  

// The n-queens puzzle is the problem of placing n queens on an n x n 
// chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions 
// to the n-queens puzzle.

// 1 <= n <= 9

// MAJOR IDEA: 1) Brute force: Iterate through all possible n! permutations of 
// queens. Check that no 2 queens are on the same main and anti diagonals 
// (idx + jdx and idx + n - jdx, respectively)
// 2) Backtracking: Store mainDiagonal, antiDiagonal, and column in binary. 
// cur_row is the state. Iterate over cur_column and try to put a queen there. 
// Then remove the queen

class Solution {
    int result = 0;
    long long mainDiagonal = 0, antiDiagonal = 0, column = 0;
    int num_queens;
public:    
    void buildNextSolution(int cur_row) {
        if (cur_row == num_queens) {
            ++result;
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
                
                buildNextSolution(cur_row + 1);
                
                // Remove queen from [cur_row][cur_column]
                column ^= (1 << cur_column);
                mainDiagonal ^= (1LL << (cur_row + cur_column));
                antiDiagonal ^= (1LL << (cur_row + num_queens - cur_column));
            }
        }      
    }
    
    int totalNQueens(int n) {
        num_queens = n;
        int cur_row = 0;
        buildNextSolution(cur_row);
        return result;
    }
};

// #bugs = 0