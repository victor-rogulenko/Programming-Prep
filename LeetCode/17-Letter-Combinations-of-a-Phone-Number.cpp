// LeetCode: 17. Letter Combinations of a Phone Number
// Created by Victor Rogulenko
// May 09, 2022

#include <cassert>
#include <vector>
#include <string>

const std::vector<std::vector<char>> digit_mapping = 
    {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'},
     {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
     {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

std::vector<std::string> letterCombinations(const std::string& digits) {
    std::vector<std::string> result;
    if (digits.empty()) {
        return result;
    }

    for (auto ch_digit : digits) {
        std::vector<std::string> temp;
        int digit = (int)(ch_digit) - (int)('0');
        for (auto ch : digit_mapping[digit]) {
            if (result.empty()) {
                temp.push_back(std::string(1, ch));
            } else {
                for (auto& str : result) {
                    temp.push_back(str + ch);
                }                
            }
        }
        result = temp;
    }
    return result;    
}

void RunTestCases() {
    std::string digits = "";
    std::vector<std::string> result;
    assert(letterCombinations(digits) == result);

    digits = "23";
    result = {"ad","bd","cd", "ae", "be", "ce", "af", "bf", "cf"};
    assert(letterCombinations(digits) == result);

    digits = "9999";
    assert(!letterCombinations(digits).empty());
}

int main() {
    RunTestCases();
    return 0;
}