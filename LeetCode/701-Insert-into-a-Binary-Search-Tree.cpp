// LeetCode: 701. Insert into a Binary Search Tree
// 701-Insert-into-a-Binary-Search-Tree.cpp
// Created by Victor Rogulenko
// [2022-05-18 14:27]  

// You are given the root node of a binary search tree (BST) 
// and a value to insert into the tree. Return the root node of 
// the BST after the insertion. It is guaranteed that the new value 
// does not exist in the original BST.
// Notice that there may exist multiple valid ways for the insertion, 
// as long as the tree remains a BST after insertion. You can return any of them.

// The number of nodes in the tree will be in the range [0, 10^4].
// -10^8 <= Node.val <= 10^8
// All the values Node.val are unique.
// -10^8 <= val <= 10^8
// It's guaranteed that val does not exist in the original BST.

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode* result = root;
        TreeNode* prev = nullptr;
        
        while (root) {
            prev = root;
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        TreeNode* new_node = new TreeNode(val);
        
        if (val < prev->val) {
            prev->left = new_node;
        } else {
            prev->right = new_node;
        }      
        
        return result;
    }
};