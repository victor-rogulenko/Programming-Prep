// LeetCode: 112. Path Sum
// 112-Path-Sum.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given the root of a binary tree and an integer targetSum, return 
// true if the tree has a root-to-leaf path such that adding up all 
// the values along the path equals targetSum.

// A leaf is a node with no children.

// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

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
    int sum = 0;
    int target;
    bool result = false;
public:
    void traverseNode(TreeNode* root) {
        if (!root || result) {
            return;
        }
        
        sum += root->val;
        
        if (!root->left && !root->right && sum == target) {
            result = true;
            return;
        }
        
        traverseNode(root->left);
        traverseNode(root->right);
        
        sum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        traverseNode(root);
        return result;    
    }
};