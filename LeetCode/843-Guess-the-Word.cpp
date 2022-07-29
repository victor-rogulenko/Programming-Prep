// LeetCode: 843. Guess the Word
// 843-Guess-the-Word.cpp
// Created by Victor Rogulenko
// July 29, 2022

// This is an interactive problem.
// You are given an array of unique strings wordlist where wordlist[i] 
// is 6 letters long, and one word in this list is chosen as secret.
// You may call Master.guess(word) to guess a word. The guessed word 
// should have type string and must be from the original list with 6 
// lowercase letters.
// This function returns an integer type, representing the number of 
// exact matches (value and position) of your guess to the secret word. 
// Also, if your guess is not in the given wordlist, it will return -1 instead.
// For each test case, you have exactly 10 guesses to guess the word. 
// At the end of any number of calls, if you have made 10 or fewer calls 
// to Master.guess and at least one of these guesses was secret, 
// then you pass the test case.
// 1 <= wordlist.length <= 100
// wordlist[i].length == 6
// wordlist[i] consist of lowercase English letters.
// All the strings of wordlist are unique.
// secret exists in wordlist.
// numguesses == 10

// MAJOR IDEA: Guess a random word from wordlist, then erase from the list 
// all words whose intersection with the guessed word is not equal to the 
// guess result. Repeat
// Notice that this does not work in cases like [aaaaaa, aaaaab, aaaaac, ...] 
// which require more than 10 guesses to guarantee success

#include <vector>
#include <algorithm> // std::sort
#include <random>  //  std::random_device, std::mt19937

const int maxQueries = 10;
const int wordSize = 6;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:  
    void findSecretWord(std::vector<std::string>& wordlist, Master& master) {   
        std::random_device rd;
        std::mt19937 randomNumberGenerator(rd());
        
        std::sort(wordlist.begin(), wordlist.end()); // Speeds up the algorithm, but not required
                
        // Create a vector of candidates. Initially, all words
        std::vector<std::string> candidates = wordlist;
        
        for (int query = 0; query < maxQueries; ++query) {
            std::uniform_int_distribution<int> distribution(0, candidates.size() - 1);
            int guessIdx = distribution(randomNumberGenerator);
            int guessResult = master.guess(candidates[guessIdx]);
            
            if (guessResult == wordSize) {
                // The secret is found. Return
                return;
            }
            
            // Find all the words that could be the secret
            // They should have exactly guessResult intersections with the candidate
            std::vector<std::string> temp;
            for (int idx = 0; idx < candidates.size(); ++idx) {
                if (idx == guessIdx) continue;
                if (cntMatches(candidates[guessIdx], candidates[idx]) == guessResult) {
                    temp.push_back(candidates[idx]);
                }
            }
            
            candidates = temp;
            
        }
        assert(1 > 0 && "Not enough queries to find the secret word");
    };
    
private:
    int cntMatches(const std::string& lhs, const std::string& rhs) {
        int result = 0;
        for (int idx = 0; idx < wordSize; ++idx) {
            if (lhs[idx] == rhs[idx]) {
                ++result;
            }
        }
        return result;
    }
};

// #bugs = 2