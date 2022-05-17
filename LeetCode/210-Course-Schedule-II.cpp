// LeetCode: 210. Course Schedule II
// 210-Course-Schedule-II.cpp
// Created by Victor Rogulenko
// [2022-05-17 15:33]

// There are a total of numCourses courses you have to take, 
// labeled from 0 to numCourses - 1. You are given an array 
// prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
// take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have 
// to first take course 1.
// Return the ordering of courses you should take to finish all courses. 
// If there are many valid answers, return any of them. If it is impossible 
// to finish all courses, return an empty array.

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

#include <vector>

class Solution {
    bool cycle_found = false;
    std::vector<int> visited;
    std::vector<std::vector<int>> adjacencies;
    std::vector<int> result;
public:
    void buildAdjacencies(int numCourses, 
                          std::vector<std::vector<int>>& prerequisites) {
        adjacencies = std::vector<std::vector<int>>(numCourses);
        for (auto& prereq : prerequisites) {
            adjacencies[prereq[0]].push_back(prereq[1]);
        }     
    }
    
    void dfs(int node) {
        // visited[node] == 0 : we have not processed the node
        // visited[node] == 1 : we are processing the node
        // visited[node] == 2 : we have processed the node
        if (visited[node] == 2) {
            return;
        }
        if (visited[node] == 1) {
            // Cycle found. Finishing all courses is not possible
            cycle_found = true;
            return;
        }
        if (cycle_found) {
            return;
        }
        visited[node] = 1;
        for (auto prereq : adjacencies[node]) {
            dfs(prereq);
        }
        visited[node] = 2;
        result.push_back(node);
    }
    
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        buildAdjacencies(numCourses, prerequisites);
        visited = std::vector<int>(numCourses, 0);
        
        for (int course_id = 0; course_id < numCourses; ++course_id) {
            dfs(course_id); 
            if (cycle_found) {
                break;
            }
        }
        
        if (!cycle_found) {
            return result;
        } else {
            return std::vector<int>();
        }
    }
};