// LeetCode: 818. Race Car
// 818-Race-Car.cpp
// Created by Victor Rogulenko
// [2022-07-22 19:41]	

// Your car starts at position 0 and speed +1 on an infinite number line. 
// Your car can go into negative positions. Your car drives automatically 
// according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):
// When you get an instruction 'A', your car does the following:
// - position += speed
// - speed *= 2
// When you get an instruction 'R', your car does the following:
// - If your speed is positive then speed = -1
// - otherwise speed = 1
// - Your position stays the same.
// For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, 
// and your speed goes to 1 --> 2 --> 4 --> -1.
// Given a target position target, return the length of the shortest sequence 
// of instructions to get there.

// 1 <= target <= 10^4

// MAJOR IDEA: DP[destination]. Iterate over # moves until the first backward 
// turning point and then over # moves until the first forward turning point. 
// This way manage the 'reverse' instruction. O(N log^2(N))

#include <algorithm> // std::min

const int INF = (int)(1e5);
const int maxSize = (int)(1e4 + 10);

class Solution {
public:
    int racecar(int target) {
        // dp[destination] = min number of instructions to reach destination
        int dp[maxSize];
        for (int idx = 1; idx <= target; ++idx) {
            dp[idx] = INF;
        }
        
        for (int destination = 1; destination <= target; ++destination) {
            // choose where to turn backwards for the first time
            int turningBackwardPnt = 1;
            int cntMovesForward = 1;
            while (turningBackwardPnt < destination) {
                int stopBackwardMovementPnt = 0;
                int cntMovesBackward = 0; 
                while (stopBackwardMovementPnt < turningBackwardPnt) {
                    dp[destination] = std::min(
                        dp[destination],
                        cntMovesForward + 1 + cntMovesBackward + 1 + 
                            dp[destination - (turningBackwardPnt - stopBackwardMovementPnt)]
                    );
                    ++cntMovesBackward;
                    stopBackwardMovementPnt = (1 << cntMovesBackward) - 1;
                }
                ++cntMovesForward;
                turningBackwardPnt = (1 << cntMovesForward) - 1;
            }
            
            if (turningBackwardPnt == destination) {
                dp[destination] = std::min(
                    dp[destination],
                    cntMovesForward
                );
            } else if (turningBackwardPnt > destination) {
                dp[destination] = std::min(
                    dp[destination],
                    cntMovesForward + 1 + dp[turningBackwardPnt - destination]
                );
            }
        }

        return dp[target];
    }
};

// #bugs = 2

// target < 10^4

//   A    A    A    R     A
// 0 -> 1 -> 3 -> 7 -> 7  -> 6
// 1 -> 2 -> 4 -> 8 -> -1 -> -2