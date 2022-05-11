// LeetCode: 2037. Minimum Number of Moves to Seat Everyone
// Created by Victor Rogulenko
// May 11, 2022

// There are n seats and n students in a room. You are given an 
// array seats of length n, where seats[i] is the position of the ith seat. 
// You are also given the array students of length n, where students[j] 
// is the position of the jth student.

// You may perform the following move any number of times:
// Increase or decrease the position of the ith student by 1 (i.e., 
// moving the ith student from position x to x + 1 or x - 1)

// Return the minimum number of moves required to move each student to 
// a seat such that no two students are in the same seat.

// n == seats.length == students.length
// 1 <= n <= 100
// 1 <= seats[i], students[j] <= 100

#include <cassert>
#include <vector>
#include <algorithm> // std::sort
#include <cmath> // std::abs

int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
    int result = 0;
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());
    for (int idx = 0; idx < seats.size(); ++idx) {
        result += std::abs(seats[idx] - students[idx]);
    }
    return result;
}

void RunTestCases() {
    std::vector<int> seats{3,1,5};
    std::vector<int> students{2,7,4};
    assert(minMovesToSeat(seats, students) == 4);

    seats = {4,1,5,9};
    students = {1,3,2,6};
    assert(minMovesToSeat(seats, students) == 7);

    seats = {2,2,6,6};
    students = {1,3,2,6};
    assert(minMovesToSeat(seats, students) == 4);

    seats = {0};
    students = {100};
    assert(minMovesToSeat(seats, students) == 100);
}

int main() {
    RunTestCases();
    return 0;
}