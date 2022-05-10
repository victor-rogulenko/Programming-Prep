// LeetCode: 897. Increasing Order Search Tree
// Created by Victor Rogulenko
// May 10, 2022

// Given the root of a binary search tree, rearrange 
// the tree in in-order so that the leftmost node in 
// the tree is now the root of the tree, and every 
// node has no left child and only one right child.

// The number of nodes in the given tree will be in the range [1, 100].
// 0 <= Node.val <= 1000

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

struct TreeNodePair {
    TreeNode* head;
    TreeNode* tail;
    TreeNodePair(TreeNode* h, TreeNode* t) : head(h), tail(t) {};
};

TreeNodePair* processOneNode(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNodePair* left_subtree = processOneNode(root->left);
    TreeNodePair* right_subtree = processOneNode(root->right);

    TreeNode* head = root;
    TreeNode* tail = root;

    if (left_subtree != nullptr) {
        (left_subtree->tail)->right = root;
        head = left_subtree->head;
    }
    if (right_subtree != nullptr) {
        root->right = right_subtree->head;
        tail = right_subtree->tail;
    }

    // Remove left children now that they are rearranged
    root->left = nullptr;

    TreeNodePair* result = new TreeNodePair(head, tail);
    return result;
}

TreeNode* increasingBST(TreeNode* root) {
    TreeNodePair* updated_tree = processOneNode(root);
    if (updated_tree == nullptr) {
        return nullptr;
    } else {
        return updated_tree->head;
    }
}

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

bool checkIncreasingBST(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    if (root->left != nullptr) {
        return false;
    }
    return checkIncreasingBST(root->right);
}

void RunTestCases() {
    std::vector<int> input{5, 1, 7};
    TreeNode* root = makeTree(input);
    TreeNode* new_tree = increasingBST(root);
    assert(checkIncreasingBST(new_tree));

    input = {3, 9, 20, null_val, null_val, 15, 7};
    root = makeTree(input);
    new_tree = increasingBST(root);
    assert(checkIncreasingBST(new_tree));

    input = {1, null_val, 2};
    root = makeTree(input);
    new_tree = increasingBST(root);
    assert(checkIncreasingBST(new_tree));

    input = {};
    root = makeTree(input);
    new_tree = increasingBST(root);
    assert(checkIncreasingBST(new_tree));

    input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; 
    root = makeTree(input);
    new_tree = increasingBST(root);
    assert(checkIncreasingBST(new_tree));

    input = {1, null_val, 3, null_val, null_val, null_val, 7, null_val, null_val, 
        null_val, null_val, null_val, null_val, null_val, 15}; 
    root = makeTree(input);
    new_tree = increasingBST(root);
    assert(checkIncreasingBST(new_tree));
}

int main() {
    RunTestCases();
    return 0;
}