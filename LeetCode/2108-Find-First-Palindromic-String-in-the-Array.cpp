// LeetCode: 2108. Find First Palindromic String in the Array
// Created by Victor Rogulenko
// May 06, 2022

#include <cassert>
#include <string>
#include <vector>

bool isPalindrome(const std::string& word) {
    return (word == std::string(word.rbegin(), word.rend()));
}

std::string firstPalindrome(const std::vector<std::string>& words) {
    for (auto& word : words) {
        if (isPalindrome(word)) {
            return word;
        }    
    }      
    return "";  
}

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists only of lowercase English letters.

void RunTestCases() {
    std::vector<std::string> words = {"abc","car","ada","racecar","cool"};
    assert(firstPalindrome(words) == "ada");
    
    words = {"notapalindrome","racecar"};
    assert(firstPalindrome(words) == "racecar");  

    words = {"def","ghi"};
    assert(firstPalindrome(words) == "");    

    words = {"a"};
    assert(firstPalindrome(words) == "a");  

    words = {"ab"};
    assert(firstPalindrome(words) == "");
}

int main() {
    RunTestCases();
    return 0;
}