// LeetCode: 235. Lowest Common Ancestor of a Binary Search Tree
// Created by Victor Rogulenko
// May 11, 2022

// Given a binary search tree (BST), find the lowest common 
// ancestor (LCA) of two given nodes in the BST.

// The number of nodes in the tree is in the range [2, 10^5].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the BST.

#include <cassert>
#include <vector>
#include <limits>

const int null_val = std::numeric_limits<int>::min();

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), 
        right(right) {}
};

TreeNode* makeTree(const std::vector<int>& input) {
    if (input.empty()) {
        return nullptr;
    }
    std::vector<TreeNode*> nodes;
    for (int idx = 0; idx < input.size(); ++idx) {
        TreeNode* new_node = new TreeNode(input[idx]);
        nodes.push_back(new_node);
        if ((idx > 0) && (input[idx] != null_val)) {    
            if ((idx-1) % 2 == 0) {
               nodes[(idx-1)/2]->left = new_node;
            } else {
                nodes[(idx-1)/2]->right = new_node;
            }
        }
    }
    return nodes[0];
}

class Solution {
public:
    Solution() {};

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* min, TreeNode* max) {
        // root, p, and q cannot be nullptr by the task conditions
        if (min->val > max->val) {
            TreeNode* temp = min;
            min = max;
            max = temp;
        }
        while ((root->val > max->val) || (root->val < min->val)) {
            if (root->val > max->val) {
                // Both min and max are left descendants of root
                root = root->left;
            } else {
                // Both min and max are right descendants of root
                root = root->right;
            }
        }
        return root;
    }
};

void RunTestCases() {
}

int main() {
    RunTestCases();
    return 0;
}