// LeetCode: 2096. Step-By-Step Directions From a Binary Tree Node to Another
// 2096-Step-By-Step-Directions-From-a-Binary-Tree-Node-to-Another.cpp
// Created by Victor Rogulenko
// [2022-07-22 16:27]	


// You are given the root of a binary tree with n nodes. Each node is uniquely 
// assigned a value from 1 to n. You are also given an integer startValue representing 
// the value of the start node s, and a different integer destValue representing the 
// value of the destination node t.
// Find the shortest path starting from node s and ending at node t. Generate step-by-step 
// directions of such path as a string consisting of only the uppercase letters 
// 'L', 'R', and 'U'. Each letter indicates a specific direction:
// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.
// The number of nodes in the tree is n.
// 2 <= n <= 10^5
// 1 <= Node.val <= n
// All the values in the tree are unique.
// 1 <= startValue, destValue <= n
// startValue != destValue

// MAJOR IDEA: DFS to find paths root - start and root - dest. 
// Only store startPath and destPath
// My mistake: Used BFS. ML due to storing paths to each node as strings

#include <string>
#include <algorithm> //std::reverse

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
    string getDirections(TreeNode* root, int startValue, int destValue) {        
        DFS(root, startValue, startPath);
        DFS(root, destValue, destPath);
        return combinePaths();
    }
private:
    std::string startPath, destPath;
    
    bool DFS(TreeNode* root, int dest, std::string& path) {
        if (!root) {
            return false;
        }
        
        if (root->val == dest) {
            path = "";
            return true;
        }
        
        if (DFS(root->left, dest, path)) {
            path += 'L';
            return true;
        } else if (DFS(root->right, dest, path)) {
            path += 'R';
            return true;
        }
        
        return false;
    }
    
    std::string combinePaths() {
        std::reverse(startPath.begin(), startPath.end());
        std::reverse(destPath.begin(), destPath.end());
        
        int idx = 0;
        while (idx < startPath.length() && idx < destPath.length() &&
              startPath[idx] == destPath[idx]) {
            ++idx;
        }
        
        startPath = (!startPath.empty() ? 
                     std::string(startPath.length() - idx, 'U') : 
                     "");
        destPath = (!destPath.empty() ? 
                    destPath.substr(idx) : 
                    "");
        
        return startPath + destPath;
    }
};

// #bugs = 1
// ML exceeded

// BFS
// Root -> ... -> Start: LLL
// Root -> ... -> Finish:RL
// Merge start path and finish path. Remove common characters
// Then replace all start path elements with U
// Ans = U x startPath.length() + finishPath.

// Example 1:
// Start: LL
// Finish: RL
// No common path. 
// Result: LL->UU + RL = UURL

// Example 2:
// Start: L
// Finish: ''
// No common path.
// Result: L + '' = L
