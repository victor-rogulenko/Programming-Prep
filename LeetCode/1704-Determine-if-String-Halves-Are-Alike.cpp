// LeetCode: 1704. Determine if String Halves Are Alike
// Created by Victor Rogulenko

#include <string>
#include <cassert>
#include <set>

const std::set<char> Vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int countVowels(const std::string& s) {
    int result = 0;
    for (auto& ch : s) {
        result += (Vowels.find(ch) != Vowels.end());
    }
    return result;
}

bool halvesAreAlike(std::string s) {
    assert (s.length() > 1);
    assert (s.length() % 2 == 0);
    int vowels_total = countVowels(s);
    int vowels_left = countVowels(s.substr(0, s.length()/2));
    return (vowels_total == vowels_left * 2);
}

void RunTestCases() {
    assert(halvesAreAlike("book") == true);
    assert(halvesAreAlike("textbook") == false);
    assert(halvesAreAlike("oo") == true);
    assert(halvesAreAlike("bb") == true);
    assert(halvesAreAlike("ab") == false);
    assert(halvesAreAlike("aA") == true);
    assert(halvesAreAlike("Ab") == false);
    assert(halvesAreAlike("AaOO") == true);
}

int main() {
    RunTestCases();
    return 0;
}