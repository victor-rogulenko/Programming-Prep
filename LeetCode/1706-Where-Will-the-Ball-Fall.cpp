// LeetCode: 1706. Where Will the Ball Fall
// 1706-Where-Will-the-Ball-Fall.cpp
// Created by Victor Rogulenko
// June 29, 2022

// You have a 2-D grid of size m x n representing a box, and you have n balls. 
// The box is open on the top and bottom sides.
// Each cell in the box has a diagonal board spanning two corners of the cell 
// that can redirect a ball to the right or to the left.
// - A board that redirects the ball to the right spans the top-left corner to 
// the bottom-right corner and is represented in the grid as 1.
// - A board that redirects the ball to the left spans the top-right corner to 
// the bottom-left corner and is represented in the grid as -1.
// We drop one ball at the top of each column of the box. Each ball can get stuck 
// in the box or fall out of the bottom. A ball gets stuck if it hits a "V" 
// shaped pattern between two boards or if a board redirects the ball into 
// either wall of the box.
// Return an array answer of size n where answer[i] is the column that 
// the ball falls out of at the bottom after dropping the ball from the ith 
// column at the top, or -1 if the ball gets stuck in the box.
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// grid[i][j] is 1 or -1.

// MAJOR IDEA: Simulate the movement. Write functions dropBallFromLocation and 
// ballCanMove

#include <vector>

class Solution {
public:    
    std::vector<int> findBall(const std::vector<std::vector<int>>& grid) {
        width = grid[0].size();
        height = grid.size();
        
        std::vector<int> result(width, -1);
        for (int location = 0; location < width; ++location) {
            result[location] = dropBallFromLocation(grid, location);
        }
        return result;
    };
    
private:
    int width, height;
    
    int dropBallFromLocation(const std::vector<std::vector<int>>& grid, int location) {
        for (int level = 0; level < height; ++level) {
            if (ballCanMove(grid, level, location)) {
                location += grid[level][location];
            } else {
                return -1;
            }
        }
        
        return location;
    }
    
    bool ballCanMove(const std::vector<std::vector<int>>& grid, int level, int location) {
        if ((grid[level][location] == 1) && 
            (location + 1 == width || grid[level][location + 1] == -1)) {
            return false;
        }
        
        if ((grid[level][location] == -1) &&
            (location == 0 || grid[level][location - 1] == 1)) {
            return false;
        } 
        
        return true;
    }
};

// #bugs = 1