// LeetCode: 105. Construct Binary Tree from Preorder and Inorder Traversal
// 105-Construct-Binary-Tree-from-Preorder-and-Inorder-Traversal.cpp
// Created by Victor Rogulenko
// [2022-07-15 01:42]	

// Given two integer arrays preorder and inorder where preorder is the preorder 
// traversal of a binary tree and inorder is the inorder traversal of the same 
// tree, construct and return the binary tree.

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.

// MAJOR IDEA: preorder: current (left) (right), inorder: (left) current (right)
// Find current node in inorder and split preorder and inorder based on it

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
    TreeNode* buildTree(const std::vector<int>& preorder, 
                        const std::vector<int>& inorder) {
        
        return processNode(preorder, inorder, 
                    0, preorder.size() - 1,
                    0, inorder.size() - 1);
    }
    
    TreeNode* processNode(const std::vector<int>& preorder,
                          const std::vector<int>& inorder,
                          int start_preorder, int finish_preorder,
                          int start_inorder, int finish_inorder) {
        
        if (start_preorder > finish_preorder) {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(preorder[start_preorder]);
        
        if (start_preorder == finish_preorder) {
            return node;
        }
        
        int delta = 0;
        while (inorder[start_inorder + delta] != preorder[start_preorder]) {
            ++delta;
        }
        
        node->left = processNode(preorder, inorder,
                                start_preorder + 1, start_preorder + delta,
                                start_inorder, start_inorder + delta - 1);
        node->right = processNode(preorder, inorder,
                                 start_preorder + delta + 1, finish_preorder,
                                 start_inorder + delta + 1, finish_inorder);
        
        return node;
    }
};

// #bugs = 1

// preorder: current (left) (right)
// inorder: (left) current (right)