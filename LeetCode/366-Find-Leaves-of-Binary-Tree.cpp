// LeetCode: 366. Find Leaves of Binary Tree
// 366-Find-Leaves-of-Binary-Tree.cpp
// Created by Victor Rogulenko
// [2022-07-25 11:52]	

// Given the root of a binary tree, collect a tree's nodes 
// as if you were doing this:
// - Collect all the leaf nodes.
// - Remove all the leaf nodes.
// - Repeat until the tree is empty.

// The number of nodes in the tree is in the range [1, 100].
// -100 <= Node.val <= 100

// MAJOR IDEA: Run DFS, trim leaves, add push them to a vector candidate. 
// Repeat until the root becomes a leaf

#include <vector>

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
    std::vector<std::vector<int>> findLeaves(TreeNode* root) {
        bool rootIsLeaf = false;
        do {
            candidate = {};
            rootIsLeaf = checkLeafAndTrim(root);
            result.push_back(candidate);
        } while (!rootIsLeaf);
        return result;
    }
    
private:
    std::vector<std::vector<int>> result;
    std::vector<int> candidate;
    
    bool checkLeafAndTrim(TreeNode* root) {
        if (!root->left && !root->right) {
            candidate.push_back(root->val);
            return true;
        }
        
        if (root->left) {
            if (checkLeafAndTrim(root->left)) {
                root->left = nullptr;
            }
        }
        
        if (root->right) {
            if (checkLeafAndTrim(root->right)) {
                root->right = nullptr;    
            }
        }
        
        return false;
    }   
};