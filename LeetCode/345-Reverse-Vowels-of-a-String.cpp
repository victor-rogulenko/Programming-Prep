// LeetCode 345. Reverse Vowels of a String
// Created by Victor Rogulenko

#include <string>
#include <stack>
#include <set>
#include <queue>
#include <cassert>

const std::set<char> isVowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

std::string reverseVowels(std::string s) {
    std::stack<char> all_vowels;
    std::queue<int> all_vowel_idces;
    int ctr = 0;
    // Find all vowels and put them in a stack;
    for (auto& ch : s) {
        if (isVowel.find(ch) != isVowel.end()) {
            all_vowels.push(ch);
            all_vowel_idces.push(ctr);
        }
        ++ctr;
    }
    // Iterate through all vowel indeces and put vowels in the reverse order;
    ctr = all_vowel_idces.size();
    while (ctr > 0) {
        s[all_vowel_idces.front()] = all_vowels.top();
        all_vowel_idces.pop();
        all_vowels.pop();
        --ctr; 
    }
    return s;    
}

void RunTestCases() {
    assert (reverseVowels("hello") == "holle");
    assert (reverseVowels("leetcode") == "leotcede");
    assert (reverseVowels("a") == "a");
    assert (reverseVowels("aA") == "Aa");
    assert (reverseVowels("str") == "str");
    assert (reverseVowels("S") == "S");
    assert (reverseVowels("aaaEEE") == "EEEaaa");
}

int main() {
    RunTestCases();
    return 0;
}