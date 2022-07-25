// LeetCode: 359. Logger Rate Limiter
// 359-Logger-Rate-Limiter.cpp
// Created by Victor Rogulenko
// [2022-07-25 17:21]	

// Design a logger system that receives a stream of messages along with their timestamps. 
// Each unique message should only be printed at most every 10 seconds 
// (i.e. a message printed at timestamp t will prevent other identical messages 
// from being printed until timestamp t + 10).
// All messages will come in chronological order. Several messages may arrive 
// at the same timestamp.
// Implement the Logger class:
// Logger() Initializes the logger object.
// bool shouldPrintMessage(int timestamp, string message) Returns true if 
// the message should be printed in the given timestamp, otherwise returns false.
// 0 <= timestamp <= 10^9
// Every timestamp will be passed in non-decreasing order (chronological order).
// 1 <= message.length <= 30
// At most 104 calls will be made to shouldPrintMessage.

// MAJOR IDEA: "1. Hash  map stringTimestampMap. Time O(1), space O(M), M - number of messages.
// 2. Queue + Set. Time O(N), space O(N), N - size of the queue. 
// Might be more efficient with memory if too many messages"

#include <string>
#include <unordered_map>

class Logger {
public:
    Logger() {    
    }
    
    bool shouldPrintMessage(int timestamp, const std::string& message) {
        if ((stringTimestampMap.find(message) == stringTimestampMap.end()) ||
           stringTimestampMap[message] + 10 <= timestamp) {
            stringTimestampMap[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }
    
private:
    std::unordered_map<std::string, int> stringTimestampMap;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */