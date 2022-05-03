// LeetCode: 344. Reverse String
// Created by Victor Rogulenko

#include <vector>
#include <cassert>

void reverseString(std::vector<char>& s) {
    int begin_ = 0;
    int end_ = s.size() - 1;
    while (begin_ < end_) {
        char temp = s[begin_];
        s[begin_] = s[end_];
        s[end_] = temp;
        ++begin_;
        --end_;
    }
}

void RunTests() {
    std::vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> str_result = {'o', 'l', 'l', 'e', 'h'};
    reverseString(str);
    assert (str == str_result);
    str = {'H'};
    str_result = {'H'};
    reverseString(str);
    assert (str == std::vector<char>{'H'});
}

int main() {
    RunTests();
    return 0;
}