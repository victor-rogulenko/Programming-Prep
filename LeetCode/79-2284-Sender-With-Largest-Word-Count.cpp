// LeetCode: BW Contest 79, 2284. Sender With Largest Word Count
// 79-2284-Sender-With-Largest-Word-Count.cpp
// Created by Victor Rogulenko
// May 28, 2022

// You have a chat log of n messages. You are given two string arrays messages 
// and senders where messages[i] is a message sent by senders[i].
// A message is list of words that are separated by a single space with 
// no leading or trailing spaces. The word count of a sender is the total 
// number of words sent by the sender. Note that a sender may send more than 
// one message.
// Return the sender with the largest word count. If there is more than one 
// sender with the largest word count, return the one with the lexicographically 
// largest name.
// Note:
// Uppercase letters come before lowercase letters in lexicographical order.
// "Alice" and "alice" are distinct.

// n == messages.length == senders.length
// 1 <= n <= 10^4
// 1 <= messages[i].length <= 100
// 1 <= senders[i].length <= 10
// messages[i] consists of uppercase and lowercase English letters and ' '.
// All the words in messages[i] are separated by a single space.
// messages[i] does not have leading or trailing spaces.
// senders[i] consists of uppercase and lowercase English letters only.

// MAJOR IDEA: Use a hash map to keep count

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countWords(const std::string& message) {
        if (message.size() == 0) {
            return 0;
        }
        int result = 1;
        for (auto ch : message) {
            if (ch == ' ') {
                ++result;
            }
        }
        return result;
    }
    
    std::string largestWordCount(std::vector<std::string>& messages, 
                                 std::vector<std::string>& senders) {
        std::unordered_map<std::string, int> cntr;
        
        for (int idx = 0; idx < messages.size(); ++idx) {
            cntr[senders[idx]] += countWords(messages[idx]);
        }
        
        int res = 0;
        std::string name;
        
        for (auto candidate : cntr) {
            if ((candidate.second > res) || (candidate.second == res && candidate.first > name)) {
                res = candidate.second;
                name = candidate.first;
            }
        }
        
        return name;
    }
};