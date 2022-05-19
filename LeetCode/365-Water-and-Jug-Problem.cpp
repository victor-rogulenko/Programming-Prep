// LeetCode: 365. Water and Jug Problem
// 365-Water-and-Jug-Problem.cpp
// Created by Victor Rogulenko
// [2022-05-19 16:43]	

// You are given two jugs with capacities jug1Capacity and jug2Capacity 
// liters. There is an infinite amount of water supply available. 
// Determine whether it is possible to measure exactly targetCapacity 
// liters using these two jugs.

// If targetCapacity liters of water are measurable, you must have 
// targetCapacity liters of water contained within one or both buckets 
// by the end.

// Operations allowed:
// Fill any of the jugs with water.
// Empty any of the jugs.
// Pour water from one jug into another till the other jug is completely full, 
// or the first jug itself is empty.


// Explanation why gcd(a,b) works
// https://math.stackexchange.com/questions/2399425/jugs-of-water-puzzle-minimum-number-of-operations
// MAJOR IDEA: once you chose from which jar to pour to the other,
// it only makes sense to keep pouring in the same direction

// Bézout's identity — Let a and b be integers or polynomials 
// with greatest common divisor d. Then there exist integers or 
// polynomials x and y such that ax + by = d.

#include <algorithm> // std::swap

class Solution {
public:
    int gcd(int a, int b){
        while (a > 0){
            b %= a;
            std::swap(a, b);
        }
        return b;
    }
    
    bool canMeasureWater(int a, int b, int targetCapacity) {
        return (a + b < targetCapacity ? false : targetCapacity % gcd(a,b) == 0);
    }
};