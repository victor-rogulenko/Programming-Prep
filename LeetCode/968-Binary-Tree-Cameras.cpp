// LeetCode: 968. Binary Tree Cameras
// 968-Binary-Tree-Cameras.cpp
// Created by Victor Rogulenko
// [2022-06-17 23:04]	

// You are given the root of a binary tree. We install cameras on the tree 
// nodes where each camera at a node can monitor its parent, itself, and its 
// immediate children.
// Return the minimum number of cameras needed to monitor all nodes of the tree.

// The number of nodes in the tree is in the range [1, 1000].
// Node.val == 0

// MAJOR IDEA: 1) Greedy: dfs should return proximity to camera: 2 = camera in the current node,
// 1 = camera in a child, 0 = not covered at all. Do not put a camera in a leaf, then
// greedily allocate cameras. Update global res
// 2) DP: similar logic, but top down. Keep track of covered nodes.

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
    int dfs(TreeNode* node) {
        if (!node) {
            return 1;
        }
        
        if (!node->left && !node->right) {
            // This node is a leaf
            // Don't put a camera here
            return 0;
        }
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        if (left == 0 || right == 0) {
            // One of the children is not covered
            // Put a camera into this node
            ++cnt;
            return 2;
        }
        
        if (left == 1 && right == 1) {
            // Both children are covered
            // Put a camera into the parent instead
            return 0;
        }
        
        // One of the children has a camera
        // No need to put it here
        return 1;
    }
    
    int minCameraCover(TreeNode* root) {
        if (!root->left && !root->right) {
            return 1;
        }
        
        if (dfs(root) == 0) {
            ++cnt;
        };
        
        return cnt;
    };
    
private:
    int cnt = 0;
};

// #bugs = 2