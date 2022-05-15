// LeetCode: 1302. Deepest Leaves Sum
// 1302-Deepest-Leaves-Sum.cpp
// Contest Template
// Created by Victor Rogulenko
// May 15, 2022

// Given the root of a binary tree, return the sum of values of its deepest leaves.

// The number of nodes in the tree is in the range [1, 10^4].
// 1 <= Node.val <= 100

#include <cassert>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), 
        left(left), right(right) {}
};

class Solution {
    int max_depth = -1;
    int deepest_sum = 0;
public:
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        if (depth > max_depth) {
            max_depth = depth;
            deepest_sum = 0;
        }
        if (depth == max_depth) {
            deepest_sum += root->val;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return deepest_sum;
    }
};

// int case_num = 1;

// void TestCase(int input, int expected) {
//     int result = Solution().method(input);
//     std::cout << "Case #" << case_num << ": expected = " << expected <<
//         ", result = " << result << "\n";
//     ++case_num;
//     assert(expected == result);
// }

// void RunTestCases() {
//     TestCase(2, 2);
// }

int main() {
    RunTestCases();
    return 0;
}