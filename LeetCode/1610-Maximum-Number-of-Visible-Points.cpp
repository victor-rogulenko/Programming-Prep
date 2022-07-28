// LeetCode: 1610. Maximum Number of Visible Points
// 1610-Maximum-Number-of-Visible-Points.cpp
// Created by Victor Rogulenko
// [2022-07-28 14:26]

// You are given an array points, an integer angle, and your location, 
// where location = [posx, posy] and points[i] = [xi, yi] both 
// denote integral coordinates on the X-Y plane.
// Initially, you are facing directly east from your position. 
// You cannot move from your position, but you can rotate. In other words, 
// posx and posy cannot be changed. Your field of view in degrees is 
// represented by angle, determining how wide you can see from any given 
// view direction. Let d be the amount in degrees that you rotate counterclockwise. 
// Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].
// You can see some set of points if, for each point, the angle formed by the point, 
// your position, and the immediate east direction from your position is in your field of view.
// There can be multiple points at one coordinate. There may be points at your location, 
// and you can always see these points regardless of your rotation. Points do not 
// obstruct your vision to other points.
// Return the maximum number of points you can see.
// 1 <= points.length <= 10^5
// points[i].length == 2
// location.length == 2
// 0 <= angle < 360
// 0 <= posx, posy, xi, yi <= 100

// MAJOR IDEA: "Compute radians, sort them, and use a sliding window
// Time: O(NlogN). Space: O(N)"

// My bugs: Messed up with geometry. angleRad = arctan(y/x). Add pi if x < 0

#include <vector>
#include <algorithm> //std::sort, std::max
#include <cmath> // std::atan
// Since C++20, pi is definned in std::numbers::pi - #include <numbers>

const double pi = 3.14159265358979323846;

class Solution {
public:
    int visiblePoints(const std::vector<std::vector<int>>& points, int angle, 
                      const std::vector<int>& location) {
        // Convert points to radians
        int cntPtsHomeLocation = 0;
        std::vector<double> radians;
        
        for (const auto& pt : points) {
            if (pt[0] == location[0] && pt[1] == location[1]) {
                ++cntPtsHomeLocation;
            } else {
                radians.push_back(calcAngle(pt[0] - location[0], pt[1] - location[1]));
                // Add same pt + 2pi to take care of the 2pi jump
                radians.push_back(radians.back() + 2 * pi);
            }
        }
        
        // Sort all radians in increasing order
        std::sort(radians.begin(), radians.end());
        
        // Use sliding window to find max visible points
        int result = 0;
        double angleRad = (double)(angle)/180 * pi;
        int start = 0;
        int fin = 0;
        
        while (start < radians.size()) {
            while (fin < radians.size() && 
                   radians[start] + angleRad >= radians[fin]) {
                ++fin;
            }
            result = std::max(result, fin - start);
            ++start;
        }
        
        // Return result
        return result + cntPtsHomeLocation;
    }
private:
    double calcAngle(int x, int y) {
        double arctg = std::atan((double)y/x);
        if (x >= 0) {
            return arctg;
        } else {
            // (x < 0)
            return arctg + pi;
        }
    }
};

// #bugs = 4