// LeetCode: 82. Remove Duplicates from Sorted List II
// 82-Remove-Duplicates-from-Sorted-List-II.cpp
// Created by Victor Rogulenko
// [2022-06-25 23:48]	

// Given the head of a sorted linked list, delete all nodes that have 
// duplicate numbers, leaving only distinct numbers from the original list. 
// Return the linked list sorted as well.

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

// MAJOR IDEA: Create a dummy parent. Move 2 pointers: start and 
// finish = start->next. If start->val == finish->val, move finish while possible, 
// then skip everything between start and finish - 1

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        
        ListNode* parent = new ListNode(-1000);
        ListNode* prev = parent;
        
        while (head) {
            ListNode* curNode = head->next;
            
            if (!curNode || head->val != curNode->val) {
                prev->next = head;
                prev = head;
            } else {
                while (curNode && curNode->val == head->val) {
                    curNode = curNode->next;
                }
                prev->next = curNode;
            }
            head = curNode;
        }
        
        return parent->next;
    }
};