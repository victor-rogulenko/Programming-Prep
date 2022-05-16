// LeetCode: 113. Path Sum II
// 113-Path-Sum-II.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given the root of a binary tree and an integer targetSum, 
// return all root-to-leaf paths where the sum of the node values 
// in the path equals targetSum. Each path should be returned as 
// a list of the node values, not node references.

// A root-to-leaf path is a path starting from the root and ending 
// at any leaf node. A leaf is a node with no children.

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
    std::vector<int> candidate;
    std::vector<std::vector<int>> result;
    int sum = 0;
    int target;
public:
    void traverseNode(TreeNode* root) {
        if (!root) {
            return;
        }
        
        candidate.push_back(root->val);
        sum += root->val;
        
        if (!root->left && !root->right && sum == target) {
            result.push_back(candidate);
        }
        traverseNode(root->left);
        traverseNode(root->right);
        
        sum -= root->val;
        candidate.pop_back();
    }
    
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        traverseNode(root);
        return result;
    }
};