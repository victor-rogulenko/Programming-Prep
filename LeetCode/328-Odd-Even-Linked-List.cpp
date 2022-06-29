// LeetCode: 328. Odd Even Linked List
// 328-Odd-Even-Linked-List.cpp
// Created by Victor Rogulenko
// June 29, 2022

// Given the head of a singly linked list, group all the nodes with odd indices 
// together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain 
// as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.
// The number of nodes in the linked list is in the range [0, 104].
// -10^6 <= Node.val <= 10^6

// MAJOR IDEA: Run odd and even ptrs simultaneously, update their links. 
// Append evenHead to the last oddPtr

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* evenHead = head->next;
        
        ListNode* oddPtr = head;
        ListNode* evenPtr = evenHead;
        
        // Iterate through all the nodes, relink the odd and the even nodes
        while (evenPtr && evenPtr->next) {
            oddPtr->next = evenPtr->next;
            oddPtr = oddPtr->next;
            
            evenPtr->next = oddPtr->next;
            evenPtr = evenPtr->next;
        }
        
        // Append the even head to the odd tail
        oddPtr->next = evenHead;
        
        return head;
    }
};