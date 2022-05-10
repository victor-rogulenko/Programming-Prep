// LeetCode: 111. Minimum Depth of Binary Tree
// Created by Victor Rogulenko
// May 10, 2022

// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest 
// path from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.

// The number of nodes in the tree is in the range [0, 10^5].
// -100 <= Node.val <= 100

#include <cassert>
#include <vector>
#include <limits>

const int null_val = std::numeric_limits<int>::max();

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

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_depth = minDepth(root->left) + 1;
    int right_depth = minDepth(root->right) + 1;

    if (left_depth == 1) {
        left_depth = null_val;
    }
    if (right_depth == 1) {
        right_depth = null_val;
    }

    if ((left_depth == right_depth) && (left_depth == null_val)) {
        // This is a leaf
        return 1;
    } else {
        return (left_depth < right_depth ? left_depth : right_depth);
    }
}

void RunTestCases() {
    std::vector<int> input{3, 9, 20, null_val, null_val, 15, 7};
    TreeNode* root = makeTree(input);
    TreeNode* node = root;
    assert(node->val == 3);
    assert(node->left->val == 9);
    assert(node->right->val == 20);
    node = node->right;
    assert(node->val == 20);
    assert(node->left->val == 15);
    assert(node->right->val == 7);
    node = node->right;
    assert(node->left == nullptr);
    assert(node->right == nullptr);
    assert(minDepth(root) == 2);

    input = {1, null_val, 2};
    root = makeTree(input);
    assert(minDepth(root) == 2);

    input = {1, 2};
    root = makeTree(input);
    assert(minDepth(root) == 2);

    input = {};
    root = makeTree(input);
    assert(minDepth(root) == 0);

    input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; 
    root = makeTree(input);
    assert(minDepth(root) == 4);

    input = {1, null_val, 3, null_val, null_val, null_val, 7, null_val, null_val, 
        null_val, null_val, null_val, null_val, null_val, 15}; 
    root = makeTree(input);
    assert(minDepth(root) == 4);
}

// 1
// 2 null

// 1
// 2 3
// 4 5 6 7
// 8 9 10 11 12 13 14 15

int main() {
    RunTestCases();
    return 0;
}