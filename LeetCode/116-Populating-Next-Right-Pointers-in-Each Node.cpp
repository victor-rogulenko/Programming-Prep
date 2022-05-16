// LeetCode: 116. Populating Next Right Pointers in Each Node
// 116-Populating-Next-Right-Pointers-in-Each Node.cpp
// Created by Victor Rogulenko
// May 16, 2022

// You are given a perfect binary tree where all leaves are on the same 
// level, and every parent has two children.
// Populate each next pointer to point to its next right node. If there 
// is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL

// The number of nodes in the tree is in the range [0, 2^12 - 1].
// -1000 <= Node.val <= 1000

// Follow-up:

// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space 
// does not count as extra space for this problem.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectUsingParent(Node* root, Node* parent) {
        if (!root) {
            return;
        }
        if (parent && parent->left == root && parent->right) {
            root->next = parent->right;
        } else if (!parent) {
            root->next = nullptr;
        } else {
            Node* prev = parent->next;
            while (prev && !prev->left && !prev->right) {
                prev = prev->next;
            }
            if (!prev) {
                root->next = nullptr;
            } else if (prev->left) {
                root->next = prev->left;
            } else {
                root->next = prev->right;
            }
        }
        connectUsingParent(root->right, root);
        connectUsingParent(root->left, root);
    }
    Node* connect(Node* root) {
        connectUsingParent(root, nullptr);
        return root;
    }
};