// LeetCode: 2053. Kth Distinct String in an Array
// Created by Victor Rogulenko

#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

std::string kthDistinct(const std::vector<std::string>& arr, int k) {
    std::unordered_map<std::string, int> occurances_ctr;
    for (auto& str : arr) {
        if (occurances_ctr.find(str) != occurances_ctr.end()) {
            ++occurances_ctr[str];
        } else {
            occurances_ctr[str] = 1;
        }
    }
    std::string candidate = "";
    for (auto& str : arr) {
        if (occurances_ctr[str] == 1) {
            --k;
            candidate = str;
        }
        if (k == 0) {
            break;
        }
    }
    if (k > 0) {
        return "";
    } else {
        return candidate;
    }
}

void RunTestCases() {
    std::vector<std::string> input = {"d","b","c","b","c","a"};
    assert(kthDistinct(input, 2) == "a");

    input = {"aaa","aa","a"};
    assert(kthDistinct(input, 1) == "aaa");

    input = {"a","b","a"};
    assert(kthDistinct(input, 3) == "");

    input = {"d"};
    assert(kthDistinct(input, 1) == "d");

    input = {"d","d"};
    assert(kthDistinct(input, 2) == "");
}

int main() {
    RunTestCases();
    return 0;
}