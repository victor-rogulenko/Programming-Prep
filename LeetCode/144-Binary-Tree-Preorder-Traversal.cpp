// LeetCode: 144. Binary Tree Preorder Traversal
// 144-Binary-Tree-Preorder-Traversal.cpp
// Created by Victor Rogulenko
// May 16, 2022

// Given the root of a binary tree, return the 
// preorder traversal of its nodes' values.

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 
// Follow up: Recursive solution is trivial, could you do it iteratively?

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
#include <set>
#include <stack>

class Solution {
    std::vector<int> result;
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return result;
        }
        result.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return result;
    }

    std::vector<int> preorderTraversalIterative(TreeNode* root) {
        if (!root) {
            return result;
        }
        
        std::set<TreeNode*> visited;
        visited.insert(root);
        
        std::stack<TreeNode*> ancestry;
        ancestry.push(root);
        
        result.push_back(root->val);
        
        while (!ancestry.empty()) {
            if (ancestry.top()->left && 
                visited.find(ancestry.top()->left) == visited.end()) {
                
                result.push_back(ancestry.top()->left->val);
                visited.insert(ancestry.top()->left);
                ancestry.push(ancestry.top()->left);
            } else if (ancestry.top()->right && 
                       visited.find(ancestry.top()->right) == visited.end()) {
                
                result.push_back(ancestry.top()->right->val);
                visited.insert(ancestry.top()->right);
                ancestry.push(ancestry.top()->right);
            } else {
                ancestry.pop();
            }
        }
        
        return result;
    }
};