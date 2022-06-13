// LeetCode: 2130. Maximum Twin Sum of a Linked List
// 2130-Maximum-Twin-Sum-of-a-Linked-List.cpp
// Created by Victor Rogulenko
// [2022-06-12 22:59]	

// In a linked list of size n, where n is even, the ith node (0-indexed) 
// of the linked list is known as the twin of the (n-1-i)th node, if 
// 0 <= i <= (n / 2) - 1.
// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is 
// the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.
// Given the head of a linked list with even length, return the maximum twin 
// sum of the linked list.
// The number of nodes in the list is an even integer in the range [2, 10^5].
// 1 <= Node.val <= 10^5

// MAJOR IDEA: 1) Put values of the the second half into a stack
// 2) Reverse the second half

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// SOLUTION 1. Stack

#include <stack>
#include <algorithm> //std::max

class Solution {
public:    
    int pairSum(ListNode* head) {
        int n = findListLength(head);
        std::stack<int> st = buildStackSecondHalf(head, n);
        return findMaxPairSum(head, st, n); 
    };
    
private:
    int findListLength(ListNode* head) {
        // Find how many nodes there are
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        return n;
    };
    
    std::stack<int> buildStackSecondHalf(ListNode* head, int n) {
        // Build a stack of values starting from n/2
        int idx = n;
        while (idx > n/2) {
            head = head->next;
            --idx;
        }
        std::stack<int> result = {};
        while (head) {
            result.push(head->val);
            head = head->next;    
        }
        return result;
    };
    
    int findMaxPairSum(ListNode* head, std::stack<int>& st, int n) {
        // Compare the pairs and find the max
        int result = 0;
        int idx = 0;
        while (idx < n/2) {
            result = std::max(result, head->val + st.top());
            st.pop();
            head = head->next;
            ++idx;
        }
        return result;
    }
};

// #bugs = 0

// SOLUTION 2. Revert half of the list

class Solution2 {
public:    
    int pairSum(ListNode* head) {
        int n = findListLength(head);
        auto tail = RevertSecondHalf(head, n);
        
        // Examine pairs, find the max;
        int result = 0;
        for (int cnt = 0; cnt < n/2; ++cnt) {
            result = std::max(result, head->val + tail->val);
            head = head->next;
            tail = tail->next;
        }
        return result;
    };
    
private:
    int findListLength(ListNode* head) {
        // Find how many nodes there are
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        return n;
    };
    
    ListNode* RevertSecondHalf(ListNode* head, int n) {
        ListNode* tail = head;
        ListNode* prev;
        for (int cnt = 0; cnt < n/2; ++cnt) {
            prev = tail;
            tail = tail->next;
        }
        while (tail) {
            auto nxt = tail->next;
            tail->next = prev;
            prev = tail;
            tail = nxt;
        }
        return prev;
    }
};