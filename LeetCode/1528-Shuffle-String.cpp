// LeetCode: 1528. Shuffle String
// Created by Victor Rogulenko

#include <string>
#include <vector>
#include <string>
#include <cassert>

std::string restoreString(std::string& s, const std::vector<int>& indices) {
    std::vector<bool> IsProcessed(indices.size(), false);
    int idx = 0;
    while (idx < indices.size()) {
        if (!IsProcessed[idx]) {
            int jdx = idx;
            char insert = s[jdx];
            while (!IsProcessed[jdx]) {
                IsProcessed[jdx] = true;
                char temp = s[indices[jdx]];
                s[indices[jdx]] = insert;
                insert = temp;
                jdx = indices[jdx];    
            }
        }
        ++idx;
    }
    return s;
}

void RunTests() {
    std::string str = "codeleet";
    assert (restoreString(str,{4, 5, 6, 7, 0, 2, 1, 3}) == "leetcode");
    str = "abc";
    assert (restoreString(str,{0, 1, 2}) == "abc");
    str = "a";
    assert (restoreString(str,{0}) == "a");
    str = "abcd";
    assert (restoreString(str,{1, 2, 3, 0}) == "dabc");
    str = "abab";
    assert (restoreString(str,{1, 0, 3, 2}) == "baba");
}

int main() {
    RunTests();
    return 0;
}