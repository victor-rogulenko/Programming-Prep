// LeetCode: 543. Diameter of Binary Tree
// 543-Diameter-of-Binary-Tree.cpp
// Created by Victor Rogulenko
// June 29, 2022

// Given the root of a binary tree, return the length of the diameter 
// of the tree.
// The diameter of a binary tree is the length of the longest path between 
// any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of 
// edges between them.
// The number of nodes in the tree is in the range [1, 10^4].
// -100 <= Node.val <= 100

// MAJOR IDEA: dfs should return the max length from the current 
// node to a leaf and update a global variable diameter if the longest 
// path goes through both left and right children of the node

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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    };
    
private:
    int diameter = 0;
    
    int dfs(TreeNode* root) {
        if (!root) {
            return -1;
        }
        
        int left = dfs(root->left) + 1;
        int right = dfs(root->right) + 1;
        
        if (left + right > diameter) {
            diameter = left + right;
        }
        
        return (left > right ? left : right);
    }
};