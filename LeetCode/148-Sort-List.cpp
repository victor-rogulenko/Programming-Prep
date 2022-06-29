// LeetCode: 148. Sort List
// 148-Sort-List.cpp
// Created by Victor Rogulenko
// June 29, 2022

// Given the head of a linked list, return the list after sorting it in ascending order.
// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
// The number of nodes in the list is in the range [0, 5 * 10^4].
// -10^5 <= Node.val <= 10^5

// MAJOR IDEA: 1) Naive: put everything in a vector and sort it
// )

#include <vector>

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
    ListNode* sortList(ListNode* head) {
        std::vector<int> result;
        ListNode* ptr = head;
        while (ptr) {
            result.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        std::sort(result.begin(), result.end());
        
        int idx = 0;
        ptr = head;
        
        while (ptr) {
            ptr->val = result[idx];
            ++idx;
            ptr = ptr->next;
        }
        
        return head;
    }
};