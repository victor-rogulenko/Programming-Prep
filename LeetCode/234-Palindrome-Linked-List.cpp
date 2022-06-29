// LeetCode: 234. Palindrome Linked List
// 234-Palindrome-Linked-List.cpp
// Created by Victor Rogulenko
// June 29, 2022

// Given the head of a singly linked list, return true if it is a palindrome.
// Follow up: Could you do it in O(n) time and O(1) space?
// The number of nodes in the list is in the range [1, 10^5].
// 0 <= Node.val <= 9

// MAJOR IDEA: Find the center of the list. Reverse "next" pointers for the left half. 
// Check equalities with 2 pointers: left and right

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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Find the length of the list
        int len = 0;
        ListNode* right_ptr = head;
        while (right_ptr) {
            ++len;
            right_ptr = right_ptr->next;
        }
        
        // Move to the list center, reverse 'next' links
        right_ptr = head;
        ListNode* prev = nullptr;
        ListNode* preprev = nullptr;
        int cnt = len/2;
        while (cnt > 0) {
            --cnt;
            preprev = prev;
            prev = right_ptr;
            right_ptr = right_ptr->next;
            prev->next = preprev;
        }
        
        // Move with 2 pointers: left and right.
        // Check that the values are the same
        ListNode* left_ptr = prev;
        if (len % 2) {
            right_ptr = right_ptr->next;
        }
        
        while (left_ptr && right_ptr) {
            if (left_ptr->val != right_ptr->val) {
                return false;
            }
            left_ptr = left_ptr->next;
            right_ptr = right_ptr->next;
        }
        
        return true;
    }
};