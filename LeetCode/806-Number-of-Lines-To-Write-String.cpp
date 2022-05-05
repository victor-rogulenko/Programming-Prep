// LeetCode: 806. Number of Lines To Write String
// Created by Victor Rogulenko

#include <vector>
#include <string>
#include <cassert>

const int MaxLineLength = 100;

std::vector<int> numberOfLines(const std::vector<int>& widths, std::string s) {
    int qty_lines = 1;
    int cur_line_len = 0;
    for (auto& ch: s) {
        int cur_ch = (int)(ch) - (int)('a');
        if (cur_line_len + widths[cur_ch] > 100) {
            ++qty_lines;
            cur_line_len = 0;
        }
        cur_line_len += widths[cur_ch];
    }
    return std::vector<int>{qty_lines, cur_line_len};    
};

void RunTestCases() {
    std::vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    assert ((numberOfLines(widths, "abcdefghijklmnopqrstuvwxyz") == std::vector<int>{3, 60}));

    widths = {100,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    assert ((numberOfLines(widths, "aaaa") == std::vector<int>{4, 100}));

    widths = {60,70,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    assert ((numberOfLines(widths, "ab") == std::vector<int>{2, 70}));   
};

int main() {
    RunTestCases();
    return 0;
}

