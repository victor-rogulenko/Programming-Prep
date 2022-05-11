// LeetCode: 108. Convert Sorted Array to Binary Search Tree
// Created by Victor Rogulenko
// May 11, 2022

// Given an integer array nums where the elements are sorted 
// in ascending order, convert it to a height-balanced binary search tree.

// A height-balanced binary tree is a binary tree in which the depth 
// of the two subtrees of every node never differs by more than one.

// 1 <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4
// nums is sorted in a strictly increasing order.

#include <cassert>
#include <vector>
#include <iterator> // std::distance
#include <utility> // std::pair
#include <cmath> // std::abs
#include <algorithm> // std::max

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Solution() {};

    TreeNode* sortedArrayToBSTIterators(std::vector<int>::iterator begin_,
                                        std::vector<int>::iterator end_) {
        if (begin_ >= end_) {
            return nullptr;
        }
        if (begin_ + 1 == end_) {
            TreeNode* node = new TreeNode(*begin_);
            return node;
        }
        auto mid = begin_ + std::distance(begin_, end_) / 2;
        TreeNode* root = new TreeNode(*mid);
        TreeNode* left_subtree = sortedArrayToBSTIterators(begin_, mid);
        TreeNode* right_subtree = sortedArrayToBSTIterators(mid + 1, end_);
        root->left = left_subtree;
        root->right = right_subtree;
        return root;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBSTIterators(nums.begin(), nums.end());
    }
};

std::pair<bool, int> checkHeightBalanced(TreeNode* root) {
    if (root == nullptr) {
        return std::make_pair(true, 0);
    }
    auto left_res = checkHeightBalanced(root->left);
    auto right_res = checkHeightBalanced(root->right);
    int current_height = std::max(left_res.second, right_res.second) + 1;
    if ((!left_res.first) || (!right_res.first) || 
        (std::abs(left_res.second - right_res.second) > 1)) {
        return std::make_pair(false, current_height);
    } else {
        return std::make_pair(true, current_height);
    }
}

void RunTestCases() {
    std::vector<int> input{-10, -3, 0, 5, 9};
    TreeNode* root = Solution().sortedArrayToBST(input);
    assert(checkHeightBalanced(root).first == true);

    input= {1, 3};
    root = Solution().sortedArrayToBST(input);
    assert(checkHeightBalanced(root).first == true);

    input= {1};
    root = Solution().sortedArrayToBST(input);
    assert(checkHeightBalanced(root).first == true);

    input= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    root = Solution().sortedArrayToBST(input);
    assert(checkHeightBalanced(root).first == true);
}

int main() {
    RunTestCases();
    return 0;
}