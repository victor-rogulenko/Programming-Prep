// LeetCode: Weekly Contest 292, 6056. Largest 3-Same-Digit Number in String
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

std::string largestGoodInteger(std::string num) {
    int result = -1;
    int ctr = 0;
    char prev = 'a';
    for (auto& elm : num) {
        if ((ctr == 0) || (elm == prev)) {
            ++ctr;
        }
        if ((ctr == 3) && ((int)(elm) - (int)('0') > result)) {
            result = (int)(elm) - (int)('0');
        }
        if ((ctr > 2) || (elm != prev)) {
            ctr = 1;
        }
        prev = elm;
    }


    // std::cout << result << "\n";
    if (result == -1) {
        return "";
    } else {
        return std::string("").insert(0, 3, (char)(result + (int)('0')));
    }        
}

// 3 <= num.length <= 1000
// num only consists of digits.

void RunTestCases() {
    assert(largestGoodInteger("6777133339") == "777");
    assert(largestGoodInteger("2300019") == "000");
    assert(largestGoodInteger("42352338") == "");
    assert(largestGoodInteger("000") == "000");
    assert(largestGoodInteger("000999") == "999");
    assert(largestGoodInteger("00099") == "000");
}

int main() {
    RunTestCases();
    return 0;
}