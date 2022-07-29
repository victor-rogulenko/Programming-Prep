// LeetCode: 2013. Detect Squares
// 2013-Detect-Squares.cpp
// Created by Victor Rogulenko
// July 29, 2022

// You are given a stream of points on the X-Y plane. 
// Design an algorithm that:
// - Adds new points from the stream into a data structure. Duplicate 
// points are allowed and should be treated as different points.
// - Given a query point, counts the number of ways to choose three points 
// from the data structure such that the three points and the query point 
// form an axis-aligned square with positive area.
// An axis-aligned square is a square whose edges are all the same length and 
// are either parallel or perpendicular to the x-axis and y-axis.
// Implement the DetectSquares class:
// - DetectSquares() Initializes the object with an empty data structure.
// - void add(int[] point) Adds a new point point = [x, y] to the data structure.
// - int count(int[] point) Counts the number of ways to form axis-aligned squares 
// with point point = [x, y] as described above.
//  point.length == 2
// 0 <= x, y <= 1000
// At most 3000 calls in total will be made to add and count.

// MAJOR IDEA: Count # points in each coordinate. On every 'count' query, run through 
// all points and check how many squares can be formed if the query point and the given 
// point are on the same diagonal
// Time: O(N^2). Space: O(N), N - number of points

#include <vector>
#include <unordered_set>

const int coordMax = 1001;

class DetectSquares {
public:
    DetectSquares() {
    }
    
    void add(const std::vector<int>& point) {
        points.insert(point[0] * coordMax + point[1]);
        ++cntPts[point[0]][point[1]];
    }
    
    int count(const std::vector<int>& point) {
        int x1 = point[0];
        int y1 = point[1];
        int x2, y2;
        int result = 0;
        for (const auto& pt0 : points) {
            x2 = pt0 / coordMax;
            y2 = pt0 % coordMax;
            if ((x1 != x2 || y1 != y2) && 
                (std::abs(x1 - x2) == std::abs(y1 - y2))) {
                result += cntPts[x2][y2] * cntPts[x1][y2] * cntPts[x2][y1];    
            }
        }
        return result;
    }
private:
    int cntPts[coordMax][coordMax] = {0};
    std::unordered_set<int> points;
};

// #bugs = 1

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */