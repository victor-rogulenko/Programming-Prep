// LeetCode: 102. Binary Tree Level Order Traversal
// Created by Victor Rogulenko
// May 11, 2022

// Given the root of a binary tree, return the level order 
// traversal of its nodes' values. (i.e., from left to right, level by level).

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        std::vector<TreeNode*> node_queue;
        node_queue.push_back(root);
        std::vector<int> current_level;
        int new_level_idx = 1;
        int head = 0;
        
        while (head < node_queue.size()) {
            if (head == new_level_idx) {
                result.push_back(current_level);
                current_level.clear();
                new_level_idx = node_queue.size();
            }

            current_level.push_back(node_queue[head]->val);

            if (node_queue[head]->left != nullptr) {
                // Add left child to the queue
                node_queue.push_back(node_queue[head]->left);
            }
            if (node_queue[head]->right != nullptr) {
                // Add right child to the queue
                node_queue.push_back(node_queue[head]->right);
            }
            ++head;
        }
        if (current_level.size() > 0) {
            result.push_back(current_level);
        }
        return result;
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

void TestCase(std::vector<int> first_vec, std::vector<std::vector<int>> result) {
    TreeNode* first_node = makeTree(first_vec);
    assert((Solution().levelOrder(first_node) == result));   
}

void RunTestCases() {
    TestCase(std::vector<int>{3,9,20,Null,Null,15,7}, 
             std::vector<std::vector<int>> {{3}, {9, 20}, {15, 7}});
    TestCase(std::vector<int>{1}, 
             std::vector<std::vector<int>> {{1}});
    TestCase(std::vector<int>{}, 
             std::vector<std::vector<int>> {});
    TestCase(std::vector<int>{3,Null,20,Null,Null,Null,7}, 
             std::vector<std::vector<int>> {{3}, {20}, {7}});
}

int main() {
    RunTestCases();
    return 0;
}