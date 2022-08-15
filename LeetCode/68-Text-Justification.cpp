// LeetCode: 68. Text Justification
// 68-Text-Justification.cpp
// Created by Victor Rogulenko
// [2022-08-15 18:39]	

// Given an array of strings words and a width maxWidth, 
// format the text such that each line has exactly maxWidth 
// characters and is fully (left and right) justified.
// You should pack your words in a greedy approach; that is, 
// pack as many words as you can in each line. Pad extra spaces 
// ' ' when necessary so that each line has exactly maxWidth characters.
// Extra spaces between words should be distributed as evenly as 
// possible. If the number of spaces on a line does not divide evenly 
// between words, the empty slots on the left will be assigned more 
// spaces than the slots on the right.
// For the last line of text, it should be left-justified, and 
// no extra space is inserted between words.
// Note:
// A word is defined as a character sequence consisting of 
// non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not 
// exceed maxWidth.
// The input array words contains at least one word.

// 1 <= words.length <= 300
// 1 <= words[i].length <= 20
// words[i] consists of only English letters and symbols.
// 1 <= maxWidth <= 100
// words[i].length <= maxWidth

// MAJOR IDEA: Create a separate method to process a line. Find start and finish 
// of each line based on word lengths. In each line, find the extra spaces between 
// words, distribute them evenly, and fill in the trailing spaces 
// (last line, one-word lines)
// Time: O(NM). Space: O(NM), N - number of words, M - length of a word

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, 
                                         int maxWidth) {
        std::vector<std::string> result;
        std::vector<std::string>::iterator startIt;
        startIt = words.begin();
        while (startIt != words.end()) {
            int curLen = 0;
            auto endIt = startIt;
            while (endIt != words.end() && 
                   curLen + endIt->length() <= maxWidth) {
                curLen += endIt->length() + 1;
                ++endIt;
            }
            --curLen; // remove space after the last word of the line
            int interWordSpaces = (endIt != words.end() ? 
                                   maxWidth - curLen : 0);
            std::string newLine = addNewLine(startIt, endIt, maxWidth, interWordSpaces);
            result.push_back(newLine);
            startIt = endIt;
        }
        
        return result;
    }

private:
    std::string addNewLine(std::vector<std::string>::iterator startIt,
                           std::vector<std::string>::iterator endIt,
                           int maxWidth, int interWordSpaces) {
        std::string result;
        int cntWords = std::distance(startIt, endIt);
        auto curIt = startIt;
        // Add spaces between words
        while (std::next(curIt) != endIt) {
            int spacesAfterThisWord = interWordSpaces/(cntWords-1) + 
                (interWordSpaces % (cntWords-1) > 0);
            result += *curIt + std::string(spacesAfterThisWord + 1, ' ');
            ++curIt;
            --cntWords;
            interWordSpaces -= spacesAfterThisWord;
        }
        result += *curIt;
        
        // Add trailing spaces
        result += std::string(maxWidth - result.length(), ' ');
        
        return result;
    }
};

// #bugs = 0

