// LeetCode: 539. Minimum Time Difference
// 539-Minimum-Time-Difference.cpp
// Created by Victor Rogulenko
// July 26, 2022

// Given a list of 24-hour clock time points in "HH:MM" format, 
// return the minimum minutes difference between any two time-points 
// in the list.

// 2 <= timePoints.length <= 2 * 10^4
// timePoints[i] is in the format "HH:MM".

// MAJOR IDEA: Keep count of times each minute was seen. Iterate through 
// 24*60 minutes instead of all timestamps to find the min distance. 
// Do not store each timestamp. Do not waste time sorting timestamps
// Time: O(N), N - number of timePoints. Space O(M), M - number of minutes in 24 hours

#include <vector>
#include <string> // std::stoi

const int cntMinutes = 24*60;

class Solution {
public:
    int findMinDifference(const std::vector<std::string>& timePoints) {
        int minutes[cntMinutes] = {0};
        for (const auto& timePoint : timePoints) {
            ++minutes[convertTimePointToMinutes(timePoint)];
        }
           
        int minDiff = 24*60;
        int curPoint = -cntMinutes;
        int prevPoint;
        int start = cntMinutes;
        
        for (int idx = 0; idx < cntMinutes; ++idx) {
            if (minutes[idx] > 1) {
                return 0;
            } else if (minutes[idx] == 1) {
                if (start == cntMinutes) {
                    start = idx;
                }
                prevPoint = curPoint;
                curPoint = idx;
                minDiff = std::min(minDiff, curPoint - prevPoint);
            }
        }
        
        return std::min(minDiff, start + cntMinutes - curPoint);
    }
    
private:
    int convertTimePointToMinutes(const std::string& timePoint) {
        int hh = std::stoi(timePoint.substr(0, 2));
        int mm = std::stoi(timePoint.substr(3, 2));
        return hh*60 + mm;
    }
};

// #bugs = 1