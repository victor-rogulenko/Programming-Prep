// LeetCode: 337. House Robber III
// 337-House-Robber-III.cpp
// Created by Victor Rogulenko
// [2022-05-19 14:45]	

// The thief has found himself a new place for his thievery again. 
// There is only one entrance to this area, called root.
// Besides the root, each house has one and only one parent house. 
// After a tour, the smart thief realized that all houses in this place 
// form a binary tree. It will automatically contact the police if two 
// directly-linked houses were broken into on the same night.
// Given the root of the binary tree, return the maximum amount of money 
// the thief can rob without alerting the police.

// The number of nodes in the tree is in the range [1, 10^4].
// 0 <= Node.val <= 10^4

// MAJOR IDEA: Save the results of dfs.
// Do not do dfs multiple times on the same node
// Otherwise will get a TL

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
    const std::pair<int,int> zero{0,0};
public:
    std::pair<int,int> dfs(TreeNode* root) {
        if (!root) {
            return zero;
        }
        
        auto robLeft = dfs(root->left);
        auto robRight = dfs(root->right);
        
        std::pair<int,int> result;
        
        // Not robbing root
        result.first = std::max(robLeft.first, robLeft.second) +
                       std::max(robRight.first, robRight.second);
        // Robbing root;
        result.second = root->val + robLeft.first + robRight.first;
        
        return result;
    }
    
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return std::max(result.first, result.second);
    }
};