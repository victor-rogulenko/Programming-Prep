// LeetCode: 557. Reverse Words in a String III
// Created by Victor Rogulenko

#include <string>
#include <cassert>
#include <algorithm> // std::reverse

struct WordIterators {
    WordIterators(std::string::iterator b, std::string::iterator e) : begin_(b), end_(e) {};
    std::string::iterator begin_, end_;
};

WordIterators * findNextWord(std::string::iterator begin_,
                            std::string::iterator string_end) {
    while ((begin_ != string_end) && (*begin_ == ' ')) {
        ++begin_;
    }
    if (begin_ == string_end) {
        return nullptr;
    }
    std::string::iterator end_ = begin_;
    while ((end_ != string_end) && (*end_ != ' ')) {
        ++end_;
    }
    WordIterators* result = new WordIterators(begin_, end_);
    return result;
}

std::string reverseWords(std::string s) {
    std::string::iterator cur_it = s.begin();
    while (cur_it != s.end()) {
        WordIterators* next_word = findNextWord(cur_it, s.end());
        if (next_word == nullptr) {
            break;
        }
        std::reverse(next_word->begin_, next_word->end_);
        cur_it = next_word->end_;
        delete next_word;
    }
    return s;    
}

void RunTestCases() {
    assert (reverseWords("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc");
    assert (reverseWords("God Ding") == "doG gniD");
    assert (reverseWords("   z") == "   z");
    assert (reverseWords("z") == "z");
    assert (reverseWords("za") == "az");
    assert (reverseWords("      ab            ") == "      ba            ");
    assert (reverseWords("%$  2321") == "$%  1232");
}

int main() {
    RunTestCases();
    return 0;
}
