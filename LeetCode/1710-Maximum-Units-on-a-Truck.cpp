// LeetCode: 1710. Maximum Units on a Truck
// 1710-Maximum-Units-on-a-Truck.cpp
// Created by Victor Rogulenko
// [2022-06-08 17:01]	

// You are assigned to put some amount of boxes onto one truck. You are given 
// a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
// numberOfBoxesi is the number of boxes of type i.
// numberOfUnitsPerBoxi is the number of units in each box of the type i.
// You are also given an integer truckSize, which is the maximum number of boxes 
// that can be put on the truck. You can choose any boxes to put on the truck 
// as long as the number of boxes does not exceed truckSize.
// Return the maximum total number of units that can be put on the truck.

// MAJOR IDEA: Count #boxes for each size. Remember the largest size. 
// Take as many boxes as truckSize allows starting from the largest size. 

#include <vector>

const int MaxSize = 1001;
class Solution {
public:
    int maximumUnits(const std::vector<std::vector<int>>& boxTypes, int truckSize) {
        int numberOfBoxesWithXUnits[MaxSize] = {0};
        
        int largestBox = 1;
        for (auto& elm : boxTypes) {
            numberOfBoxesWithXUnits[elm[1]] += elm[0];
            largestBox = std::max(largestBox, elm[1]);
        }
        
        int result = 0;
        for (int idx = largestBox; idx > 0; --idx) {
            result += std::min(truckSize, numberOfBoxesWithXUnits[idx]) * idx;
            truckSize -= numberOfBoxesWithXUnits[idx];
            if (truckSize <= 0) {
                return result;
            }    
        }
        
        return result;
    }
};