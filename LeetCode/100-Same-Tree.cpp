// LeetCode: 100. Same Tree
// Created by Victor Rogulenko
// May 11, 2022

// Given the roots of two binary trees p and q, write a 
// function to check if they are the same or not.

// Two binary trees are considered the same if they are 
// structurally identical, and the nodes have the same value.

// The number of nodes in both trees is in the range [0, 100].
// -10^4 <= Node.val <= 10^4

#include <cassert>
#include <vector>
#include <limits>

const int Null = std::numeric_limits<int>::max();

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == nullptr) || (q == nullptr)) {
            return (p == q);
        }
        bool this_ = (p->val == q->val);
        bool left_ = isSameTree(p->left, q->left);
        bool right_ = isSameTree(p->right, q->right);
        return (this_ && left_ && right_);
    }
};

TreeNode* makeTree(const std::vector<int>& input) {
    if (input.empty()) {
        return nullptr;
    }
    std::vector<TreeNode*> nodes;
    for (int idx = 0; idx < input.size(); ++idx) {
        TreeNode* new_node = new TreeNode(input[idx]);
        nodes.push_back(new_node);
        if ((idx > 0) && (input[idx] != Null)) {    
            if ((idx-1) % 2 == 0) {
               nodes[(idx-1)/2]->left = new_node;
            } else {
                nodes[(idx-1)/2]->right = new_node;
            }
        }
    }
    return nodes[0];
};

void TestCase(std::vector<int> first_vec, std::vector<int> second_vec, bool res) {
    TreeNode* first_node = makeTree(first_vec);
    TreeNode* second_node = makeTree(second_vec);
    assert(Solution().isSameTree(first_node, second_node) == res);   
}

void RunTestCases() {
    TestCase(std::vector<int>{1,2,3}, std::vector<int>{1,2,3}, true);
    TestCase(std::vector<int>{1,2,3}, std::vector<int>{1,2}, false);
    TestCase(std::vector<int>{20}, std::vector<int>{20}, true);
    TestCase(std::vector<int>{1, Null, 2, Null, Null, Null, 4}, 
             std::vector<int>{1, Null, 2, Null, Null, Null, Null}, false);
    TestCase(std::vector<int>{1, Null, 2, Null, Null, Null, 4}, 
             std::vector<int>{1, Null, 2, Null, Null, Null, 4}, true);
}

int main() {
    RunTestCases();
    return 0;
}