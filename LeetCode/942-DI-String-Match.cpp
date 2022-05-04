// LeetCode 942. DI String Match
// Created by Victor Rogulenko

#include <vector>
#include <string>
#include <cassert>

std::vector<int> diStringMatch(const std::string& s) {
    std::vector<int> result(s.length() + 1, 0);
    int top = 0, bottom = 0;
    for (int idx = 1; idx < result.size(); ++idx) {
        if (s[idx-1] == 'I') {
            ++top;
            result[idx] = top;
        } else {
            --bottom;
            result[idx] = bottom;
        }
    }
    for (auto& elm : result) {
        elm -= bottom;
    }
    return result;
}

std::string buildDiString(const std::vector<int> input) {
    std::string result = "";
    for (int idx = 1; idx < input.size(); ++idx) {
        if (input[idx] > input[idx-1]) {
            result += 'I';
        } else {
            result += 'D';
        }
    }
    return result;
}

bool checkCase(std::string s) {
    std::vector<int> candidate = diStringMatch(s);
    return (buildDiString(candidate) == s);
}

void RunTestCases() {
    assert (checkCase("IDID"));
    assert (checkCase("III"));
    assert (checkCase("I"));
    assert (checkCase("D"));
    assert (checkCase("DDDD"));
    assert (checkCase("IIIDDD"));
}

int main() {
    RunTestCases();
    return 0;
}