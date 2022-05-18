// LeetCode: 236. Lowest Common Ancestor of a Binary Tree
// 236-Lowest-Common-Ancestor-of-a-Binary-Tree.cpp
// Created by Victor Rogulenko
// [2022-05-18 17:43]	

// Given a binary tree, find the lowest common ancestor (LCA) 
// of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: 
// “The lowest common ancestor is defined between two nodes p and q 
// as the lowest node in T that has both p and q as descendants 
// (where we allow a node to be a descendant of itself).”

// The number of nodes in the tree is in the range [2, 10^5].
// -10^9 <= Node.val <= 10^9
// All Node.val are unique.
// p != q
// p and q will exist in the tree.

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
    TreeNode* p_;
    TreeNode* q_;
    bool seen_p = false, seen_q = false;
public:
    void dfs(TreeNode* root) {        
        if (!root || result) {
            return;
        }
        
        bool seen_before = seen_p || seen_q;
        
        if (root == p_) {
            seen_p = true;
        }
        if (root == q_) {
            seen_q = true;
        }
        if (seen_p && seen_q) {
            return;
        }
        
        dfs(root->left);
        dfs(root->right);
        
        if (seen_p && seen_q && !result && !seen_before) {
            result = root;
        }        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        p_ = p;
        q_ = q;
        
        dfs(root);
        
        return result;
    }
};