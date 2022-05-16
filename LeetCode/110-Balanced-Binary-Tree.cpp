// LeetCode: 110. Balanced Binary Tree
// 110-Balanced-Binary-Tree.cpp

// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the left and right subtrees of every node 
// differ in height by no more than 1.

// The number of nodes in the tree is in the range [0, 5000].
// -10^4 <= Node.val <= 10^4

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
    bool result = true;
public:
    int cntHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = cntHeight(root->left);
        int right = cntHeight(root->right);
        if (left > right + 1 || right > left + 1) {
            result = false;
        }
        return std::max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        cntHeight(root);
        return result;
    }
};