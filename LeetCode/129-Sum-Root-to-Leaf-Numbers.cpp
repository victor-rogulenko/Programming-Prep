// LeetCode: 129. Sum Root to Leaf Numbers
// 129-Sum-Root-to-Leaf-Numbers.cpp
// Created by Victor Rogulenko
// May 16, 2022

// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated 
// so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 9
// The depth of the tree will not exceed 10.


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

#include <string>

class Solution {
    int result = 0;
    std::string candidate;
public:
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return result;
        }
        
        candidate += (char)(root->val + (int)('0'));
        
        if (!root->left && !root->right) {
            int candidate_int = std::stoi(candidate);
            result += candidate_int;
        }
        
        sumNumbers(root->left);
        sumNumbers(root->right);
        
        candidate.pop_back();
        
        return result;
    }
};