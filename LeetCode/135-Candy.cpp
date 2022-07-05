// LeetCode: 135. Candy
// 135-Candy.cpp
// Created by Victor Rogulenko
// [2022-07-05 22:56]	

// There are n children standing in a line. Each child is assigned a rating 
// value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// - Each child must have at least one candy.
// - Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies 
// to the children.

// MAJOR IDEA: If a child's rating is not greater than any of the neighbors', allocate
// 1 candy to him. Else calculate recursively the allocation to the smaller neighbors
// and allocate max of smaller neighboers allocations + 1.

#include <vector>

class Solution {
public:
    int candy(const std::vector<int>& ratings) {
        ratingsSize = ratings.size();
        cd = std::vector<int>(ratingsSize, 0);
        int result = 0;
        for (int idx = 0; idx < ratingsSize; ++idx) {
            if (cd[idx] == 0) {
                int right = (idx + 1 < ratingsSize && 
                             ratings[idx] > ratings[idx+1] ? 
                             allocCandy(idx + 1, true, ratings) + 1 : 1);
                int left = (idx > 0 && 
                            ratings[idx] > ratings[idx-1] ? 
                            allocCandy(idx - 1, false, ratings) + 1 : 1);
                cd[idx] = std::max(left, right);
            }
            result += cd[idx];
        }
        
        return result;
    };
    
private: 
    int ratingsSize;
    std::vector<int> cd;
    int allocCandy(int idx, bool moveRight, 
                   const std::vector<int>& ratings) {
        
        if (cd[idx] != 0) {
            return cd[idx];
        }
        
        if (idx == 0 || idx == ratingsSize - 1) {
            cd[idx] = 1;    
        } else if (ratings[idx] <= ratings[idx - 1] && 
                   ratings[idx] <= ratings[idx + 1]) {
            cd[idx] = 1;
        } else {
            cd[idx] = allocCandy(idx + 1 * moveRight - 1 * !moveRight, 
                                 moveRight, ratings) + 1;
        }
        
        return cd[idx];
    }
};

// #bugs = 2