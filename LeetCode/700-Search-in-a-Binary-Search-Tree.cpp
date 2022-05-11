// LeetCode: 700. Search in a Binary Search Tree
// Created by Victor Rogulenko
// May 11, 2022

// You are given the root of a binary search tree (BST) 
// and an integer val.

// Find the node in the BST that the node's value equals 
// val and return the subtree rooted with that node. 
// If such a node does not exist, return null.

// The number of nodes in the tree is in the range [1, 5000].
// 1 <= Node.val <= 10^7
// root is a binary search tree.
// 1 <= val <= 10^7

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

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    }
    if (root->val > val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

void RunTestCases() {
    std::vector<int> input{4, 2, 7, 1, 3};
    TreeNode* root = makeTree(input);
    TreeNode* node = root;
    assert(searchBST(root, 2)->val == 2);
    assert(searchBST(root, 5) == nullptr);

    input = {1};
    root = makeTree(input);
    assert(searchBST(root, 1)->val == 1);
    assert(searchBST(root, 10000) == nullptr);

    input = {4, 2}; 
    root = makeTree(input);
    assert(searchBST(root, 2)->val == 2);
    assert(searchBST(root, -2) == nullptr);
}

int main() {
    RunTestCases();
    return 0;
}