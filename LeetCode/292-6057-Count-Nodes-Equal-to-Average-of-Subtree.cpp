// LeetCode: Weekly Contest 292, 6057. Count Nodes Equal to Average of Subtree
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct SubtreeRes {
    SubtreeRes(int s, int c) : sum_(s), ctr_(c) {};
    int sum_, ctr_;
};

SubtreeRes add(SubtreeRes cur, SubtreeRes nw) {
    return SubtreeRes(cur.sum_ + nw.sum_, cur.ctr_ + nw.ctr_);    
}

SubtreeRes dfs(TreeNode* node, int& result) {
    if (node == nullptr) {
        return (SubtreeRes(0, 0));
    }
    SubtreeRes current_res(node->val, 1);
    current_res = add(current_res, dfs(node->left, result));
    current_res = add(current_res, dfs(node->right, result));
    if ((current_res.ctr_ != 0) && (node->val == (int)(current_res.sum_ / current_res.ctr_))) {
        ++result;
    }
    return current_res;
}

int averageOfSubtree(TreeNode* root) {
    int result = 0;
    dfs(root, result);
    return result;        
}

void RunTestCases() {
//    assert(TBD() == "");
}

int main() {
    RunTestCases();
    return 0;
}