// LeetCode: 501. Find Mode in Binary Search Tree
// Created by Victor Rogulenko
// May 11, 2022

// Given the root of a binary search tree (BST) with duplicates, 
// return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// The number of nodes in the tree is in the range [1, 10^4].
// -10^5 <= Node.val <= 10^5
// No extra space

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

    void inorderBST(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorderBST(root->left);

        if ((prev != nullptr) && (prev->val == root->val)) {
            ++cur_cnt;
        } else {
            cur_cnt = 1;
        }

        prev = root;

        if (cur_cnt > max_cnt) {
            max_cnt = cur_cnt;
            final_output.clear();
            final_output.push_back(root->val);
        } else if (cur_cnt == max_cnt) {
            final_output.push_back(root->val);
        }

        inorderBST(root->right);
    }

    std::vector<int> findMode(TreeNode* root) {
        final_output.clear();
        inorderBST(root);
        return final_output;
    }

private:
    int max_cnt = 0;
    int cur_cnt = 0;
    TreeNode* prev = nullptr;
    std::vector<int> final_output;    
};

void RunTestCases() {
    std::vector<int> input{4, 2, 7, 1, 3};
    TreeNode* root = makeTree(input);
    TreeNode* node = root;
    assert((Solution().findMode(root) == std::vector<int>{1, 2, 3, 4, 7}));
    
    input.clear();
    input = {1};
    root = makeTree(input);
    assert((Solution().findMode(root) == std::vector<int>{1}));

    input.clear();
    input = {1, null_val, 2, null_val, null_val, null_val, 2}; 
    root = makeTree(input);
    assert((Solution().findMode(root) == std::vector<int>{2}));
}

int main() {
    RunTestCases();
    return 0;
}