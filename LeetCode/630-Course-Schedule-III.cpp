// LeetCode: 630. Course Schedule III
// 630-Course-Schedule-III.cpp
// Created by Victor Rogulenko
// [2022-06-25 19:54]	

// There are n different online courses numbered from 1 to n. You are given 
// an array courses where courses[i] = [durationi, lastDayi] indicate that 
// the ith course should be taken continuously for durationi days and must 
// be finished before or on lastDayi.
// You will start on the 1st day and you cannot take two or more courses 
// simultaneously.
// Return the maximum number of courses that you can take.

// 1 <= courses.length <= 10^4
// 1 <= durationi, lastDayi <= 10^4

// MAJOR IDEA: Greedy: Sort courses by inc deadline. Keep track of the courses taken 
// sorted by duration (priority queue). Try to take each course. If not possible,
// try to replace the longest taken course with it (if that taken course is longer 
// than the current course)

#include <vector>
#include <algorightm> // std::sort
#include <priority_queue>

class Solution {
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) {
        int courseCnt = courses.size();
        
        // Sort courses by lastDay
        std::sort(courses.begin(), courses.end(), 
                 [](const std::vector<int>& lhs, 
                    const std::vector<int>& rhs) -> bool {
            return lhs[1] < rhs[1];
        } );
        
        // Keep track of the courses taken sorted by duration
        std::priority_queue<int> courseDurationsTaken;
        int timeElapsed = 0;
        int result = 0;
        
        for (int idx = 0; idx < courseCnt; ++idx) {            
            if (timeElapsed + courses[idx][0] <= courses[idx][1]) {
                // Take the course
                ++result;
                timeElapsed += courses[idx][0];
                courseDurationsTaken.push(courses[idx][0]);
                
            } else if (!courseDurationsTaken.empty()) {
                // Find the longest course among those taken and try 
                // to replace it with the current course
                int maxDurationTaken = courseDurationsTaken.top();
                if (courses[idx][0] < maxDurationTaken &&
                    timeElapsed + courses[idx][0] - maxDurationTaken <= 
                    courses[idx][1]) {
                    
                    timeElapsed += courses[idx][0] - maxDurationTaken;
                    courseDurationsTaken.pop();
                    courseDurationsTaken.push(courses[idx][0]);
                }
            }
        }
        
        return result;
    }
};

// #bugs = 3
// maxDurationsTaken 7 4 3
// timeElapsed = 14
// result = 3