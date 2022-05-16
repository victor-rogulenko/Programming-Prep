// LeetCode: 199. Binary Tree Right Side View
// 199-Binary-Tree-Right-Side-View.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given the root of a binary tree, imagine yourself standing on 
// the right side of it, return the values of the nodes you can see 
// ordered from top to bottom.

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
    void dfs(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        if (depth >= result.size()) {
            result.push_back(root->val);
        } else {
            result[depth] = root->val;
        }
        ++depth;
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
    std::vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};