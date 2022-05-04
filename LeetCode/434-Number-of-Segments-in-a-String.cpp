// LeetCode: 434. Number of Segments in a String
// Created by Victor Rogulenko

#include <string>
#include <cassert>

int countSegments(std::string s) {
    if (!s.length()) {
        return 0;
    }
    int result = 0;
    for (int idx = 1; idx < s.length(); ++idx) {
        if ((s[idx-1] != ' ') && (s[idx] == ' ')) {
            ++result;
        }
    }
    if (s[s.length()-1] != ' ') {
        ++result;
    }
    return result;
}

void RunTestCases() {
    assert(countSegments("Hello, my name is John") == 5);
    assert(countSegments("Hello") == 1);
    assert(countSegments("      dfs     ") == 1);
    assert(countSegments("           ") == 0);
    assert(countSegments("") == 0);
}

int main() {
    RunTestCases();
    return 0;
}