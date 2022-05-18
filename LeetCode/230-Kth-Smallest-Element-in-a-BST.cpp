// LeetCode: 230. Kth Smallest Element in a BST
// 230-Kth-Smallest-Element-in-a-BST.cpp
// Created by Victor Rogulenko
// [2022-05-18 14:14]

// Given the root of a binary search tree, and an integer k, 
// return the kth smallest value (1-indexed) of all the values of 
// the nodes in the tree.

// The number of nodes in the tree is n.
// 1 <= k <= n <= 10^4
// 0 <= Node.val <= 10^4

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

#include <stack>

class Solution {
    const int INF = (int)(1e8);
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return INF;
        }
        
        std::stack<TreeNode*> node_stack;
        
        do {
            while (root) {
                node_stack.push(root);
                root = root->left;
            }
            root = node_stack.top();
            node_stack.pop();
            --k;
            if (k == 0) {
                return root->val;
            }
            root = root->right;
        } while (root || !node_stack.empty());
        return INF;
    }
};