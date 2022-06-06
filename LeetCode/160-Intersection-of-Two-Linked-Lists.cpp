// LeetCode: 160. Intersection of Two Linked Lists
// 160-Intersection-of-Two-Linked-Lists.cpp
// Created by Victor Rogulenko
// [2022-06-06 14:33]

// Given the heads of two singly linked-lists headA and headB, 
// return the node at which the two lists intersect. If the two 
// linked lists have no intersection at all, return null
// The test cases are generated such that there are no cycles anywhere in the 
// entire linked structure.
// Note that the linked lists must retain their original structure after the 
// function returns.
// Custom Judge:
// The inputs to the judge are given as follows (your program is not given these 
// inputs):
// intersectVal - The value of the node where the intersection occurs. 
// This is 0 if there is no intersected node.
// listA - The first linked list.
// listB - The second linked list.
// skipA - The number of nodes to skip ahead in listA (starting from the head) 
// to get to the intersected node.
// skipB - The number of nodes to skip ahead in listB (starting from the head) 
// to get to the intersected node.
// The judge will then create the linked structure based on these inputs and 
// pass the two heads, headA and headB to your program. If you correctly return 
// the intersected node, then your solution will be accepted.

// Constraints:
// The number of nodes of listA is in the m.
// The number of nodes of listB is in the n.
// 1 <= m, n <= 3 * 10^4
// 1 <= Node.val <= 10^5
// 0 <= skipA < m
// 0 <= skipB < n
// intersectVal is 0 if listA and listB do not intersect.
// intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
// Follow up: Could you write a solution that runs in O(m + n) time and use only 
// O(1) memory?

// MAJOR IDEA: 1) Move the head of the longer list to the same distance from its end 
// as the head of the shorter list. Then move heads simultaneously;
// 2) Make both heads move through both lists. Then the final part of their 
// journey will be the intersection, and they will move there simultaneously

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    int findLength(ListNode *head) {
        int result = 0;
        while (head) {
            ++result;
            head = head->next;
        }
        return result;
    }
    
    void moveHead(ListNode*& head, int num_moves) {
        while (num_moves > 0 && head) {
            head = head->next;
            --num_moves;
        }    
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = findLength(headA);
        int lenB = findLength(headB);
        
        if (lenA > lenB) {
            moveHead(headA, lenA - lenB);
        } else {
            moveHead(headB, lenB - lenA);
        }
        
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr;
    }
};

// #bugs = 2