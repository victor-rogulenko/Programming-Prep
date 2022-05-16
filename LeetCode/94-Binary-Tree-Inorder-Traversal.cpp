// LeetCode: 94. Binary Tree Inorder Traversal
// 94-Binary-Tree-Inorder-Traversal.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given the root of a binary tree, return the inorder traversal 
// of its nodes' values.

// The number of nodes in the tree is in the range [0, 100].
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

#include <vector>

class Solution {
    std::vector<int> result;
public:
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
};