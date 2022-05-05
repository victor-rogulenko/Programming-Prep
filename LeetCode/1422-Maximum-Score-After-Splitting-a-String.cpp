// LeetCode: 1422. Maximum Score After Splitting a String
// Created by Victor Rogulenko

#include <string>
#include <vector>
#include <cassert>

int countChars(const std::string& s, char ch) {
    int ctr = 0;
    for (auto& cur_ch : s) {
        ctr += (cur_ch == ch);
    }
    return ctr;
}

int maxScore(std::string s) {
    assert (s.length() > 1);
    // substrings should be nonempty! Hence start from s[0] vs s[1..]
    int zero_ctr = (s[0] == '0'); 
    s.erase(0, 1);
    int one_ctr = countChars(s, '1');
    int result =  zero_ctr + one_ctr;
    // last char should be part of the right substring, so we don't iterate through it 
    s.pop_back();
    for (auto& cur_ch : s) {
        // cur_ch is the last char of the left substring;
        if (cur_ch == '0') {
            ++zero_ctr;
        } else {
            --one_ctr;
        }
        result = std::max(result, zero_ctr + one_ctr);
    }
    return result;
}

void RunTestCases() {
    assert (maxScore("011101") == 5);
    assert (maxScore("00111") == 5);
    assert (maxScore("1111") == 3);
    assert (maxScore("01") == 2);
    assert (maxScore("10") == 0);
    assert (maxScore("00") == 1);
    assert (maxScore("11") == 1);
    assert (maxScore("00010001") == 7);
}

int main() {
    RunTestCases();
    return 0;
}