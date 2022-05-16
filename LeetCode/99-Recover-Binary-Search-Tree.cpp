// LeetCode: 99. Recover Binary Search Tree
// 99-Recover-Binary-Search-Tree.cpp
// Created by Victor Rogulenko
// May 16, 2022

// You are given the root of a binary search tree (BST), where 
// the values of exactly two nodes of the tree were swapped by mistake. 
// Recover the tree without changing its structure.

// The number of nodes in the tree is in the range [2, 1000].
// -2^31 <= Node.val <= 2^31 - 1

//******************************************************//

// [MAJOR IDEA 1] Don't worry about the tree structure
// Use inorder traversal to find the 2 misplaced nodes

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
    TreeNode* first_misplaced_node = nullptr;
    TreeNode* last_misplaced_node = nullptr;
public:    
    void inorderTraversal(TreeNode* root) {
        if (!root) {
            return;
        }
        
        inorderTraversal(root->left);
        
        // Check that prev->val < root->val
        if (prev && prev->val > root->val) {
            // first_misplaced_node updates only once
            if (!first_misplaced_node) {
                first_misplaced_node = prev;
            }
            last_misplaced_node = root;
        }
        
        prev = root;
        inorderTraversal(root->right);     
    }
    
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        std::swap(first_misplaced_node->val, last_misplaced_node->val);
    }
};