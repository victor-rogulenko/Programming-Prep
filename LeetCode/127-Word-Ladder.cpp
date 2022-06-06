// LeetCode: 127. Word Ladder
// 127-Word-Ladder.cpp
// Created by Victor Rogulenko
// [2022-06-06 16:19]	

// A transformation sequence from word beginWord to word endWord using a 
// dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk 
// such that:
// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need 
// to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, 
// return the number of words in the shortest transformation sequence 
// from beginWord to endWord, or 0 if no such sequence exists.

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.

// MAJOR IDEA 1: Build a graph from possible word pairs and run bfs from start
// MAJOR IDEA 2: use hash sets head and tail. Try to make all possible moves from 
// head. Check if the resulting word is in tail. If so, stop. If not, and if this
// word is in wordList, add it to next_head. After all words in head were processed,
// move next_head into head. If head is bigger than tail, swap them.

#include <vector>
#include <string>
#include <unordered_set> // Solution 2

// SOLUTION 1

class Solution {
    const int INF = 10000;
    int start = INF; 
    int finish = INF;
public:
    bool differsByOneLetter(const std::string& one,
                            const std::string& two) {
        if (one.size() != two.size()) {
            return false;
        }
        int cnt = 0;
        for (int idx = 0; idx < one.size(); ++idx) {
            cnt += (one[idx] != two[idx]);
        }
        return (cnt == 1);
    }
    
    std::vector<std::vector<int>> buildGraph(
        const std::string& beginWord, 
        const std::string& endWord, 
        const std::vector<string>& wordList) {
        // Build a graph of possible transitions
        std::vector<std::vector<int>> result(wordList.size()+1);
        start = wordList.size();
        
        for (int idx = 0; idx < wordList.size(); ++idx) {
            if (wordList[idx] == endWord) {
                finish = idx;
            }
            if (wordList[idx] == beginWord) {
                start = idx;
            }
        }
        start = std::min(start, (int)(wordList.size()));
        if (finish == INF) {
            return {};
        }
        
        for (int idx = 0; idx < wordList.size(); ++idx) {
            if ((start == wordList.size()) && 
                (differsByOneLetter(wordList[idx], beginWord))) {
                
                result[start].push_back(idx);
                result[idx].push_back(start);
            }
            
            for (int jdx = idx + 1; jdx < wordList.size(); ++jdx) {
                if (differsByOneLetter(wordList[idx], wordList[jdx])) {
                    result[idx].push_back(jdx);
                    result[jdx].push_back(idx);
                }
            }
        }
        return result;
    };
    
    std::vector<int> distanceFromStart(
        const std::vector<std::vector<int>>& graph) {
        
        std::vector<int> result(graph.size(), INF);
        std::queue<int> Q;
        Q.push(start);
        result[start] = 1;
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (auto elm : graph[cur]) {
                if (result[elm] == INF) {
                    result[elm] = result[cur] + 1;
                    Q.push(elm);
                }
            }
        }        
        return result;
    }
    
    int ladderLength(const std::string& beginWord, 
                     const std::string& endWord, 
                     const std::vector<string>& wordList) {
        std::vector<std::vector<int>> graph = buildGraph(beginWord, endWord, wordList);
        if (finish == INF) {
            return 0;
        }
        std::vector<int> dist = distanceFromStart(graph);
        
        return (dist[finish] != INF ? dist[finish] : 0);    
    };
};

// #bugs = 5

// SOLUTION 2

class Solution2 {
public:
    int ladderLength(const std::string& beginWord, 
                     const std::string& endWord, 
                     const std::vector<string>& wordList) {
        std::unordered_set<std::string> words = 
            std::unordered_set(wordList.begin(), wordList.end());
        std::unordered_set<std::string> head, tail;
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        
        int result = 2;
        head.insert(beginWord);
        tail.insert(endWord);
        
        while (!head.empty() && !tail.empty()) {
            if (head.size() > tail.size()) {
                head.swap(tail);
            }
            std::unordered_set<std::string> next_head;
            for (auto wrd : head) {
                // Consider all possible 1-letter modification of wrd
                for (int idx = 0; idx < wrd.length(); ++idx) {
                    char initial_char = wrd[idx];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        wrd[idx] = ch;
                        if (tail.find(wrd) != tail.end()) {
                            return result;
                        }
                        if (words.erase(wrd)) {
                            next_head.insert(wrd);
                        }
                    }
                    wrd[idx] = initial_char;
                }
            }
            head = move(next_head);
            ++result;
        }
        
        return 0;
    };
};