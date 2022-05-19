// LeetCode: 257. Binary Tree Paths
// 257-Binary-Tree-Paths.cpp
// Created by Victor Rogulenko
// [2022-05-19 12:28]  

// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]

// The number of nodes in the tree is in the range [1, 100].
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

class Solution {
    std::vector<std::string> result;
    std::stack<int> candidate;
public:
    std::string convertNumToString(int num) {
        std::string result;
        bool negative = false;
        
        if (num < 0) {
            negative = true;
            num *= (-1);
        }
        
        while (num / 10) {
            result += (char)(num % 10 + (int)('0'));
            num /= 10;
        }
        result += (char)(num % 10 + (int)('0'));
        
        if (negative) {
            result += '-';
        }
        
        return std::string(result.rbegin(), result.rend());
    }
    
    std::string convertStackToString(std::stack<int> candidate) {
        std::stack<int> temp;
        std::string result;
        
        if (candidate.empty()) {
            return result;
        }
        
        while (!candidate.empty()) {
            temp.push(candidate.top());
            candidate.pop();
        }
        
        result += convertNumToString(temp.top());
        temp.pop();
        
        while (!temp.empty()) {
            result += "->";
            result += convertNumToString(temp.top());
            temp.pop();
        }
        
        return result;
    }
    
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        
        candidate.push(root->val);
        
        if (!root->left && !root->right) {
            std::string candidate_str = convertStackToString(candidate);
            result.push_back(candidate_str);
        } else {
            dfs(root->left);
            dfs(root->right);
        }
        
        candidate.pop();
    }
    
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return result;
    }
};