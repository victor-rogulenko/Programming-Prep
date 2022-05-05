// LeetCode: 2062. Count Vowel Substrings of a String
// Created by Victor Rogulenko

#include <string>
#include <unordered_map>
#include <set>
#include <cassert>

const std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
std::unordered_map<char, int> vowel_ctr;

bool checkAllVowelsArePresent() {
    bool result = true;
    for (auto& ch : vowels) {
        result = result && (vowel_ctr[ch] > 0);
    }
    return result;
}

int findIdxOfSubstringWithAllVowels(const std::string& word, int start) {
    int mid = start;
    bool all_vowels = false;
    while ((mid < word.size()) && (vowels.find(word[mid]) != vowels.end()) && 
           (!all_vowels)) {
        ++vowel_ctr[word[mid]];
        all_vowels = checkAllVowelsArePresent();
        ++mid;
    }
    if (all_vowels) {
        --mid;
    }
    return mid;
}

int countVowelSubstrings(std::string word) {
    int start = 0;
    int result = 0;
    while (start < word.size()) {
        vowel_ctr.clear();
        // mid indicates the smallest proper vowel substring
        // starting at start
        int mid = findIdxOfSubstringWithAllVowels(word, start);
        if (mid == word.size()) {
            // This is the last substring of vowels, and not all vowels are present in it;
            break;
        }
        if (!checkAllVowelsArePresent()) {
            start = mid + 1;
            continue;
        }
        // fin indicates the end of a continuous substring starting at start
        // made up of only vowels
        int fin = mid;
        while ((fin < word.size()) && (vowels.find(word[fin]) != vowels.end())) {
            ++fin;
        }
        --fin;
        while (mid <= fin) {
            result += (fin - mid + 1);
            char previous_start_char = word[start];
            ++start;
            --vowel_ctr[previous_start_char];
            // move mid if a vowel is now missing because of movign start
            if (vowel_ctr[previous_start_char] == 0) {
                ++mid;
                while ((mid <= fin) && (vowel_ctr[previous_start_char] == 0)) {
                    ++vowel_ctr[word[mid]];
                    ++mid;
                }
                if (vowel_ctr[previous_start_char] == 0) {
                    break;
                }
                --mid;
            }
        }
        start = fin + 1;      
    }
    return result;
}

void RunTestCases() {
    assert(countVowelSubstrings("aeiouu") == 2);
    assert(countVowelSubstrings("unicornarihan") == 0);
    assert(countVowelSubstrings("cuaieuouac") == 7);
    assert(countVowelSubstrings("a") == 0);
    assert(countVowelSubstrings("z") == 0);
    assert(countVowelSubstrings("cuaieuouaczzzzzcuaieuoua") == 14);
}

int main() {
    RunTestCases();
    return 0;
}