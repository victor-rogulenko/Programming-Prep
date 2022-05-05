// LeetCode: 1047. Remove All Adjacent Duplicates In String
// Created by Victor Rogulenko

#include <string>
#include <cassert>

std::string removeDuplicates(std::string s) {
    if (s.empty()) {
        return s;
    }
    std::string result = "";
    result += s[0]; 
    for (int idx = 1; idx < s.length(); ++idx) {
        if ((result.empty()) || (result.back() != s[idx])) {
            result += s[idx]; 
        } else {
            result.pop_back();
        }
    }
    return result;    
}

void RunTestCases() {
    assert (removeDuplicates("abbaca") == "ca");
    assert (removeDuplicates("azxxzy") == "ay");   
    assert (removeDuplicates("a") == "a");
    assert (removeDuplicates("abcd") == "abcd");
    assert (removeDuplicates("abcedd") == "abce");
    assert (removeDuplicates("aabbcc") == "");
    assert (removeDuplicates("aa") == "");
}

int main() {
    RunTestCases();
    return 0;
}