// LeetCode: 489. Robot Room Cleaner
// 489-Robot-Room-Cleaner.cpp
// Created by Victor Rogulenko
// [2022-08-05 14:05]	

// You are controlling a robot that is located somewhere in a room. 
// The room is modeled as an m x n binary grid where 0 represents a wall 
// and 1 represents an empty slot.
// The robot starts at an unknown location in the room that is guaranteed 
// to be empty, and you do not have access to the grid, but you can move 
// the robot using the given API Robot.
// You are tasked to use the robot to clean the entire room (i.e., clean every 
// empty cell in the room). The robot with the four given APIs can move forward, 
// turn left, or turn right. Each turn is 90 degrees.
// When the robot tries to move into a wall cell, its bumper sensor detects the 
// obstacle, and it stays on the current cell.
// Design an algorithm to clean the entire room using the following APIs:
// interface Robot {
//   // returns true if next cell is open and robot moves into the cell.
//   // returns false if next cell is obstacle and robot stays on the current cell.
//   boolean move();
//   // Robot will stay on the same cell after calling turnLeft/turnRight.
//   // Each turn will be 90 degrees.
//   void turnLeft();
//   void turnRight();
//   // Clean the current cell.
//   void clean();
// }
// Note that the initial direction of the robot will be facing up. You can assume all 
// four edges of the grid are all surrounded by a wall.
// Custom testing:
// The input is only given to initialize the room and the robot's position internally. 
// You must solve this problem "blindfolded". In other words, you must control the robot 
// using only the four mentioned APIs without knowing the room layout and the initial 
// robot's position.

// MAJOR IDEA: DFS into each possible direction + backtracking (go back when cannot move anymore)
// Time: O(number of empty cells). Space: O(number of empty cells)

#include <vector>
#include <functional> // std::hash
#include <utility> // std::pair

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

const std::vector<std::pair<int,int>> 
    direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct CoordHash {
    std::size_t operator()(const std::pair<int,int>& s) const noexcept {
        return std::hash<int>{}(s.first * 1000 + s.second);
    }
};

class Solution {
public:
    void cleanRoom(Robot& robot) {
        cleanCell(robot, 0, 0, 0);
    }

private: 
    std::unordered_set<std::pair<int,int>, CoordHash> visited;
    
    void moveBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight(); 
    }
    
    void cleanCell(Robot& robot, int x, int y, int dir) {
        if (visited.find({x, y}) != visited.end()) {
            moveBack(robot);
            return;
        }
        visited.insert({x,y});
        robot.clean();
        for (int moveIdx = 0; moveIdx < 4; ++moveIdx) {
            if (robot.move()) {
                auto nextCell = direction[(dir + moveIdx) % 4];
                cleanCell(robot,
                          x + nextCell.first, 
                          y + nextCell.second, 
                          (dir + moveIdx) % 4);
            }
            robot.turnRight();
        }
        moveBack(robot);
    }
};