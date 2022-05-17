// LeetCode: 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
// 1379-Find-a-Corresponding-Node-of-a-Binary-Tree-in-a-Clone-of-That-Tree.cpp
// Created by Victor Rogulenko
// May 17, 2022

// Given two binary trees original and cloned and given a reference to 
// a node target in the original tree.
// The cloned tree is a copy of the original tree.
// Return a reference to the same node in the cloned tree.
// Note that you are not allowed to change any of the two trees or the 
// target node and the answer must be a reference to a node in the cloned tree.

// The number of nodes in the tree is in the range [1, 10^4].
// The values of the nodes of the tree are unique.
// target node is a node from the original tree and is not null.

// Follow up: Could you solve the problem if repeated values on the tree are allowed?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* result = nullptr;
    TreeNode* target_;
public:
    void dfs(TreeNode* node_original, TreeNode* node_clone) {
        if (result) {
            return;
        }
        if (!node_original) {
            return;
        }
        if (node_original == target_) {
            result = node_clone;
            return;
        }
        dfs(node_original->left, node_clone->left);
        dfs(node_original->right, node_clone->right);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        target_ = target;
        dfs(original, cloned);
        return result;
    }
};