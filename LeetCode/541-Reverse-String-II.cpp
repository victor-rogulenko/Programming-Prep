// LeetCode: 541. Reverse String II
// Created by Victor Rogulenko

#include <algorithm> // std::min
#include <string>
#include <cassert>

std::string reverseStr(std::string& s, int k) {
    if (k <= 1) {
        return s;
    }
    int idx = 0;
    while (idx < s.length()) {
        int fin = std::min(idx + k - 1, int(s.length() - 1));
        int jdx = idx;
        while (jdx < fin) {
            char temp = s[fin];
            s[fin] = s[jdx];
            s[jdx] = temp;
            ++jdx;
            --fin;
        }
        idx += 2*k;
    }
    return s;
}

void RunTestCases() {
    std::string str = "abcdefg";
    assert (reverseStr(str, 2) == "bacdfeg");
    str = "abcd";
    assert (reverseStr(str, 2) == "bacd");
    str = "ab";
    assert (reverseStr(str, 2) == "ba");
    str = "a";
    assert (reverseStr(str, 2) == "a");
    str = "abcABCabcABCabcAB";
    assert (reverseStr(str, 3) == "cbaABCcbaABCcbaAB");
}

int main() {
    RunTestCases();
    return 0;
}