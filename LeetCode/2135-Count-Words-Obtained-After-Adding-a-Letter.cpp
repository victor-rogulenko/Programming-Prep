// LeetCode: 2135. Count Words Obtained After Adding a Letter
// 2135-Count-Words-Obtained-After-Adding-a-Letter.cpp
// Created by Victor Rogulenko
// [2022-08-16 13:26]	

// You are given two 0-indexed arrays of strings startWords and targetWords. 
// Each string consists of lowercase English letters only.
// For each string in targetWords, check if it is possible to choose a string 
// from startWords and perform a conversion operation on it to be equal to that 
// from targetWords.
// The conversion operation is described in the following two steps:
// 1. Append any lowercase letter that is not present in the string to its end.
// -- For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added 
// to it, but not 'a'. If 'd' is added, the resulting string will be "abcd".
// 2. Rearrange the letters of the new string in any arbitrary order.
// -- For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. 
// Note that it can also be rearranged to "abcd" itself.
// Return the number of strings in targetWords that can be obtained by performing 
// the operations on any string of startWords.
// Note that you will only be verifying if the string in targetWords can be obtained 
// from a string in startWords by performing the operations. The strings in startWords 
// do not actually change during this process.
// 1 <= startWords.length, targetWords.length <= 5 * 10^4
// 1 <= startWords[i].length, targetWords[j].length <= 26
// Each string of startWords and targetWords consists of lowercase English letters only.
// No letter occurs more than once in any string of startWords or targetWords.

// MAJOR IDEA: "Convert startWords into bits. Run a check for each word in targetWords 
// by converting it to bits, and then getting rid of each bit and checking if the resulting 
// word is in startWordsBits
// Time: O(N * alphabetLength). Space: O(M). N - size of targetWords, M - size of startWords"

#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int wordCount(const std::vector<string>& startWords, 
                  const std::vector<string>& targetWords) {
        std::unordered_set<int> startWordsBits;
        // Convert startWords into bits
        for (auto& word : startWords) {
            startWordsBits.insert(convertToBits(word));
        }
        
        // Run a check for each word in targetWords by
        // converting it to bits, and
        // then getting rid of each bit and checking
        // if the resulting word is in startWordsBits
        int result = 0;
        int mask = (1 << 26) - 1;
        for (auto& word : targetWords) {
            int wordBit = convertToBits(word);
            for (int bit = 0; bit < 26; ++bit) {
                int shortWordBit = wordBit & (mask - (1 << bit)); 
                if (wordBit != shortWordBit &&  // Must remove one character
                    startWordsBits.find(shortWordBit) != startWordsBits.end()) {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }

private:
    int convertToBits(const std::string& word) {
        int result = 0;
        for (auto ch : word) {
            result ^= 1 << (ch - 'a');
        }
        return result;
    }
};

// #bugs = 1

// startWord converts to targetWord if
// for each ch in 'a'..'z',
// count(ch) in startWord == count(ch) in targetWord
// or count(ch) in startWord == 0 annd count(ch) in targetWord == 1

// O(NM) too long. Need a quicker solution
// N - size of startWords, M - size of targetWords
// Need O(M log N)
// M is needed anyway
// How to check conversion in O(log N)?

// Need to precompute smth on startWords and sort them
// Then do binary search

// What can I precompute?
// 
// IMPORTANT! Missed on first reading:
// No letter occurs more than once in any string of startWords or targetWords
// That means we can use a binary mask of length 26
// 1 - letter is present in a word. 0 - not present

// Then for two masks start and target, 
// conversion is possible if 
// start[idx] <= target[idx] for idx = 0..25

// How do I check this condition in binary ops?
// start =  00001011..
// target = 10000111..
// start XOR target = 10001100 > target
// NEED: (start XOR target) <= target

// OK, how do I sort startWords now? Will sorting by bin masks work
// for binary search?
// No, the result of a conversion check is not monotonically nondecreasing in this case
// Sort using XOR! No, it does not create a unique order

// Did not check examples. We do append and rearrange ONLY ONCE!
// So the difference between start and target is non more than 1 letter

// For each target word, try to get rid of each letter and see if the resulting 
// word is in startWords
