// LeetCode: 1370. Increasing Decreasing String
// Created by Victor Rogulenko

#include <string>
#include <vector>
#include <cassert>

const int AlphabetSize = 26;

std::vector<int> buildCharLibraryWithOccurances(const std::string& s) {
    std::vector<int> result(AlphabetSize, 0);
    for (auto& ch : s) {
        ++result[(int)(ch) - (int)('a')];
    }
    return result;
}

std::string sortString(std::string s) {
    std::vector<int> char_library = buildCharLibraryWithOccurances(s);
    int remaining_characters = s.length();
    std::string result = "";
    bool increasing_order = true;
    int start, finish, chg;
    while (remaining_characters > 0) {
        if (increasing_order) {
            start = 0;
            finish = AlphabetSize;
            chg = 1;
        } else {
            start = AlphabetSize - 1;
            finish = -1;
            chg = -1;
        }
        increasing_order = !increasing_order;
        for (int current_char = start; current_char != finish; current_char += chg) {
            if (char_library[current_char] > 0) {
               result += (char)((int)('a') + current_char); 
               --char_library[current_char];
               --remaining_characters;
            }
        }
    }
    return result;
}

void RunTestCases() {
    assert (sortString("rat") == "art");
    assert (sortString("a") == "a");
    assert (sortString("ab") == "ab");
    assert (sortString("aba") == "aba");
    assert (sortString("aaaab") == "abaaa");
    assert (sortString("abcdef") == "abcdef");
    assert (sortString("aaaabbbbcccc") == "abccbaabccba");
}

int main() {
    RunTestCases();
    return 0;
}