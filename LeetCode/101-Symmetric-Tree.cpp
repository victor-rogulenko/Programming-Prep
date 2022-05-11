// LeetCode: 101. Symmetric Tree
// Created by Victor Rogulenko
// May 11, 2022

// Given the root of a binary tree, check whether 
// it is a mirror of itself (i.e., symmetric around its center).

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return areSymmetric(root->left, root->right);
    }

    bool areSymmetric(TreeNode* p, TreeNode* q) {
        if ((p == nullptr) || (q == nullptr)) {
            return (p == q);
        }
        bool this_ = (p->val == q->val);
        bool left_ = areSymmetric(p->left, q->right);
        bool right_ = areSymmetric(p->right, q->left);
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

void TestCase(std::vector<int> first_vec, bool res) {
    TreeNode* first_node = makeTree(first_vec);
    assert(Solution().isSymmetric(first_node) == res);   
}

void RunTestCases() {
    TestCase(std::vector<int>{1,2,2}, true);
    TestCase(std::vector<int>{1,2,1}, false);
    TestCase(std::vector<int>{1}, true);
    TestCase(std::vector<int>{1, Null, 2, Null, Null, Null, 4}, false);
    TestCase(std::vector<int>{1, 2, 2, Null, 3, Null, 3}, false);
    TestCase(std::vector<int>{1, 2, 2, Null, 3, 3, Null}, true);
    TestCase(std::vector<int>{1, 2, 2, 3, 4, 4, 3}, true);
}

int main() {
    RunTestCases();
    return 0;
}