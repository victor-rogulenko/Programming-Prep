// LeetCode: 1047. Remove All Adjacent Duplicates In String
// Created by Victor Rogulenko

#include <string>
#include <cassert>

std::string::iterator findNewDuplicate(std::string& s, std::string::iterator start) {
    std::string::iterator cur_it = start;
    while (cur_it < s.end()) {
        if (*(cur_it - 1) == *cur_it) {
            return (cur_it - 1);
        }
        ++cur_it;
    }
    return cur_it;
}

std::string removeDuplicates(std::string s) {
    std::string::iterator cur_it = s.begin() + 1;
    do {
        cur_it = findNewDuplicate(s, cur_it);
        if (cur_it != s.end()) {
            auto temp = cur_it + 2;
            s.erase(cur_it, cur_it + 2);
            if (s.length() == 0) {
                return s;
            }
            cur_it = (cur_it == s.begin() ? s.begin() + 1 : cur_it);
        }
    } while (cur_it != s.end());
    return s;    
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