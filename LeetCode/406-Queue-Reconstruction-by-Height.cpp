// LeetCode: 406. Queue Reconstruction by Height
// 406-Queue-Reconstruction-by-Height.cpp
// Created by Victor Rogulenko
// June 29, 2022

// You are given an array of people, people, which are the attributes of some people 
// in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith 
// person of height hi with exactly ki other people in front who have a height greater 
// than or equal to hi.
// Reconstruct and return the queue that is represented by the input array people. 
// The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the 
// attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

// MAJOR IDEA: 1) Sorting + Linked List. Sort people in non-dec order of k, and then in non-inc 
// order of height. This way we can place each person by looking only at the previous people. 
// Use a linked list to place people
// 2) Sort people in non-inc order of height. Place people in the result from shortest to
// tallest

// SOLUTION 1. Sorting + Linked List

#include <vector>
#include <algorithm> // std::sort

struct Node {
    std::vector<int> val;
    Node* next;
    Node(std::vector<int> v) : val(v), next(nullptr) {};
};

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        // Sort people in non-decreasing order of k, and then in non-increasing order of height
        // This way we can place each person by looking only at the previous people in the vector
        std::sort(people.begin(), people.end(), [](const std::vector<int>& lhs,
                                                  const std::vector<int>& rhs) -> bool {
            return lhs[1] < rhs[1] || (lhs[1] == rhs[1] && lhs[0] > rhs[0]);
        });
        
        // Build a list of people according to their heights and k
        Node* start = new Node({-1, 0});
        for (int idx = 0; idx < people.size(); ++idx) {
            int cur_height = people[idx][0];
            int cur_count = people[idx][1];
            
            Node* prev_node = start;
            Node* cur_node = start->next;
            int cnt = 0;
            
            while (cnt < cur_count) {
                if (cur_height <= cur_node->val[0]) {
                    ++cnt;
                }
                prev_node = cur_node;
                cur_node = cur_node->next;
            }
            
            Node* new_node = new Node({cur_height, cur_count});
            new_node->next = cur_node;
            prev_node->next = new_node;
        }
        
        // Turn list into a vector
        std::vector<std::vector<int>> result(people.size());
        start = start->next;
        for (int idx = 0; idx < people.size(); ++idx) {
            result[idx] = start->val;
            start = start->next;
        }
        
        return result;
    }
};

// #bugs = 2

// [7,0],[5,0],[7,1],[6,1],[5,2],[4,4]
// [-1,0] -> [5,0] -> [7,0] -> [5,2] -> [6,1] -> [4,4] -> [7,1] -> nullprt

// SOLUTION 2. Sorting, place shortest first

class Solution2 {
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        // Sort people in non-inc order of height
        std::sort(people.begin(), people.end(), [](const std::vector<int>& lhs,
                                                  const std::vector<int>& rhs) -> bool {
            return lhs[0] < rhs[0];
        });
        
        // Place people one by one, starting from the shortest
        std::vector<std::vector<int>> result(people.size(), {-1, -1});
        for (int idx = 0; idx < people.size(); ++idx) {
            int cnt = -1;
            int pos = 0;
            int cur_height = people[idx][0];
            int cur_count = people[idx][1];
            
            while (cnt < cur_count) {
                if (result[pos][0] == -1 || result[pos][0] == cur_height) {
                    ++cnt;
                }
                ++pos;
            }

            result[pos-1] = people[idx];
        }
        
        return result;
    }
};

// #bugs = 1