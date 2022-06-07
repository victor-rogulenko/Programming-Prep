// LeetCode: 937. Reorder Data in Log Files
// 937-Reorder-Data-in-Log-Files.cpp
// Created by Victor Rogulenko
// [2022-06-07 17:23]  

// You are given an array of logs. Each log is a space-delimited string of words, 
// where the first word is the identifier.
// There are two types of logs:
// Letter-logs: All words (except the identifier) consist of lowercase 
// English letters.
// Digit-logs: All words (except the identifier) consist of digits.
// Reorder these logs so that:
// The letter-logs come before all digit-logs.
// The letter-logs are sorted lexicographically by their contents. If their contents 
// are the same, then sort them lexicographically by their identifiers.
// The digit-logs maintain their relative ordering.
// Return the final order of the logs.

// 1 <= logs.length <= 100
// 3 <= logs[i].length <= 100
// All the tokens of logs[i] are separated by a single space.
// logs[i] is guaranteed to have an identifier and at least one word after the identifier.

// MAJOR IDEA: Create Comp function as needed. Use std::stable_partition to ignore 
// Digit-Logs, or use std::stable_sort to keep the original order

#include <string>
#include <vector>
#include <algorithm> // std::sort, std::stable_partition

bool letterLogLess(const std::string& lhs, const std::string rhs) {
    std::string lhsContent = lhs.substr(lhs.find(' ') + 1);
    std::string rhsContent = rhs.substr(rhs.find(' ') + 1);

    return (lhsContent == rhsContent ? 
            (lhs < rhs) : 
            (lhsContent < rhsContent));
};

class Solution {
public:
    std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
        // Partition the logs into Letter-Logs and Digit-Logs
        auto iter = std::stable_partition(logs.begin(), logs.end(), 
            [](const std::string& str) -> bool {
                return std::isalpha(str.back());
            });
        // Sort only Letter-Logs
        std::sort(logs.begin(), iter, letterLogLess);
        return logs;
    }
};

// #bugs = 2