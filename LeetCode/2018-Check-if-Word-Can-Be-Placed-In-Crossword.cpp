// LeetCode: 2018. Check if Word Can Be Placed In Crossword
// 2018-Check-if-Word-Can-Be-Placed-In-Crossword.cpp
// Created by Victor Rogulenko
// [2022-08-16 19:50]

// You are given an m x n matrix board, representing the current state 
// of a crossword puzzle. The crossword contains lowercase English letters 
// (from solved words), ' ' to represent any empty cells, and '#' to 
// represent any blocked cells.
// A word can be placed horizontally (left to right or right to left) or 
// vertically (top to bottom or bottom to top) in the board if:
// - It does not occupy a cell containing the character '#'.
// - The cell each letter is placed in must either be ' ' (empty) or match 
// the letter already on the board.
// - There must not be any empty cells ' ' or other lowercase letters directly 
// left or right of the word if the word was placed horizontally.
// - There must not be any empty cells ' ' or other lowercase letters directly 
// above or below the word if the word was placed vertically.
// Given a string word, return true if word can be placed in board, or false 
// otherwise.

// m == board.length
// n == board[i].length
// 1 <= m * n <= 2 * 10^5
// board[i][j] will be ' ', '#', or a lowercase English letter.
// 1 <= word.length <= max(m, n)
// word will contain only lowercase English letters.

// MAJOR IDEA: For each cell and each direction, check if a word can start from it.
// If so, check if the word can be finished according to the rules.
// Time: O(MN). Space: O(1)

#include <vector>
#include <string>

const int dirRow[4] = {1, 0, -1, 0};
const int dirCol[4] = {0, 1, 0, -1};

class Solution {
public:
    bool placeWordInCrossword(const std::vector<std::vector<char>>& board, 
                              const std::string& word) {
        nrows = board.size();
        ncols = board[0].size();
        
        for (int idx = 0; idx < nrows; ++idx) {
            for (int jdx = 0; jdx < ncols; ++jdx) {
                for (int dir = 0; dir < 4; ++dir) {
                    if (canStartWord(board, idx, jdx, dir) &&
                        canFinishWord(board, idx, jdx, dir, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
private:
    int nrows, ncols;
    
    bool canStartWord(const std::vector<std::vector<char>>& board,
                      int idx, int jdx, int dir) {
        if (board[idx][jdx] != '#' && 
            (idx - dirRow[dir] < 0 || jdx - dirCol[dir] < 0 ||
             idx - dirRow[dir] >= nrows || jdx - dirCol[dir] >= ncols ||
             board[idx - dirRow[dir]][jdx - dirCol[dir]] == '#')) {
            return true;
        }
        return false;
    }
    
    bool canFinishWord(const std::vector<std::vector<char>>& board,
                       int idx, int jdx, int dir, const std::string& word) {
        int chIdx = 0;
        int len = word.length();
        
        while (chIdx < len && idx >= 0 && idx < nrows &&
               jdx >= 0 && jdx < ncols &&
               (board[idx][jdx] == ' ' || board[idx][jdx] == word[chIdx])) {
            ++chIdx;
            idx += dirRow[dir];
            jdx += dirCol[dir];
        }
        
        if (chIdx == len && (idx < 0 || jdx < 0 ||
            idx >= nrows || jdx >= ncols || board[idx][jdx] == '#')) {
            return true;
        } else {
            return false;
        }
    }
};

// #bugs = 1