// LeetCode: 98. Validate Binary Search Tree
// 98-Validate-Binary-Search-Tree.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given the root of a binary tree, determine if it is a valid 
// binary search tree (BST).

// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less 
// than the node's key.
// The right subtree of a node contains only nodes with keys greater
// than the node's key.
// Both the left and right subtrees must also be binary search trees.

// The number of nodes in the tree is in the range [1, 10^4].
// -2^31 <= Node.val <= 2^31 - 1

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
    bool checkSubtree(TreeNode* root, int minval, int maxval, 
                      bool minval_exists, bool maxval_exists) {
        if (root == nullptr) {
            return true;
        }
        if ((minval_exists && root->val <= minval) || 
            (maxval_exists && root->val >= maxval)) {
            return false;
        }
        bool check_left = checkSubtree(root->left, minval, root->val, 
        	                           minval_exists, true);
        bool check_right = checkSubtree(root->right, root->val, maxval, 
        	                            true, maxval_exists);
        return check_left & check_right;
    }
    
    bool isValidBST(TreeNode* root) {
        return checkSubtree(root, 0, 0, false, false);
    }
};