// LeetCode: 2162. Minimum Cost to Set Cooking Time
// 2162-Minimum-Cost-to-Set-Cooking-Time.cpp
// Created by Victor Rogulenko
// [2022-08-18 16:33]

// A generic microwave supports cooking times for:
// - at least 1 second.
// - at most 99 minutes and 99 seconds.
// To set the cooking time, you push at most four digits. The microwave 
// normalizes what you push as four digits by prepending zeroes. It 
// interprets the first two digits as the minutes and the last two digits 
// as the seconds. It then adds them up as the cooking time. For example,
// - You push 9 5 4 (three digits). It is normalized as 0954 and interpreted 
// as 9 minutes and 54 seconds.
// - You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 seconds.
// - You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
// - You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
// You are given integers startAt, moveCost, pushCost, and targetSeconds. 
// Initially, your finger is on the digit startAt. Moving the finger above 
// any specific digit costs moveCost units of fatigue. Pushing the digit below 
// the finger once costs pushCost units of fatigue.
// There can be multiple ways to set the microwave to cook for targetSeconds seconds 
// but you are interested in the way with the minimum cost.
// Return the minimum cost to set targetSeconds seconds of cooking time.
// Remember that one minute consists of 60 seconds.
// 0 <= startAt <= 9
// 1 <= moveCost, pushCost <= 10^5
// 1 <= targetSeconds <= 6039

// MAJOR IDEA 1. Brute force. Transitions: exit, push, or move to new button + push
// Time: O(numDigits^4). Space: O(numDigits^4)
// MAJOR IDEA 2. For every mm in [0, 99], calculate the needed ss to make mm:ss equal 
// to targetSeconds and minimize the cost of setting the cocking time to mm:ss
// Define a separate function costToDial(mm, ss) to calculate the cost of setting the 
// cocking time to mm minutes and ss seconds
// Time: O(minutes_range). Space: O(1)

// SOLUTION 1: Brute force

#include <string>

const int INF = (int)(1e9);

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        this->moveCost = moveCost;
        this->pushCost = pushCost;
        this->targetSeconds = targetSeconds;
        return countCosts(startAt, "");
    }

private:
    int moveCost, pushCost, targetSeconds;
    
    int countCosts(int button, std::string time) {
        // Exit
        if (convertTime(time) == targetSeconds) {
            return 0;
        }
        
        if (time.length() > 3) {
            return INF;
        }
        
        // Push a button
        int result = countCosts(button, 
                                time + (char)(button + '0')) 
                     + pushCost;
            
        // Move to a different button and push it
        for (int newButton = 0; newButton <= 9; ++newButton) {
            if (newButton != button) {
                int candidate = countCosts(newButton, 
                                           time + (char)(newButton + '0'));
                result = std::min(result, candidate + moveCost + pushCost);   
            }
        }            
        
        return result;
    }
    
    int convertTime(std::string time) {
        while (time.length() < 4) {
            time = '0' + time;
        }
        return std::stoi(time.substr(0, 2)) * 60 + 
               std::stoi(time.substr(2, 2));
    }
};

// #bugs = 2

// SOLUTION 2: Loop through all minutes and calc costs

const int INF = (int)(1e9);

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, 
                       int pushCost, int targetSeconds) {
        int result = INF;
        this->startAt = startAt;
        this->moveCost = moveCost;
        this->pushCost = pushCost;
        for (int mm = 0; mm < 100; ++mm) {
            int ss = targetSeconds - 60*mm; 
            if (ss >= 0 && ss < 100) {
                result = std::min(result, costToDial(mm, ss));
            }
        }
        return result;
    }

private:
    int startAt, moveCost, pushCost;
    
    int costToDial(int mm, int ss) {
        std::string digitSequence = std::to_string(startAt);
        if (mm > 0) digitSequence += std::to_string(mm);
        digitSequence += ((mm > 0) && (ss < 10) ? 
                          '0' + std::to_string(ss) : 
                          std::to_string(ss));
        int result = 0;
        for (int idx = 1; idx < digitSequence.size(); ++idx) {
            result += moveCost * 
                      (digitSequence[idx] != digitSequence[idx-1]) +
                      pushCost;
        }
        return result;
    }
};  

// #bugs = 3