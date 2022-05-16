// LeetCode: 114. Flatten Binary Tree to Linked List
// 114-Flatten-Binary-Tree-to-Linked-List.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right 
// child pointer points to the next node in the list and the left child 
// pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal 
// of the binary tree.

// Follow up: Can you flatten the tree in-place (with O(1) extra space)?

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        if (prev) {
            prev->right = root;
            prev->left = nullptr;
        }
        
        prev = root;
        flatten(left);
        flatten(right);
    }
};