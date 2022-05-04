// LeetCode: 606. Construct String from Binary Tree
// Created by Victor Rogulenko

#include <string>
#include <vector>
#include <cassert>

const int Null_Val = -10000;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::string tree2str(TreeNode* root) {
    // If the root is empty, return empty string
    if (root == nullptr) {
        return "";
    }
    std::string result = std::to_string(root->val);
    // If the root has no children, just return its value
    if ((root->left == nullptr) && (root->right == nullptr)) {
        return result;
    }
    // Output the result for the left child
    result += '(' + tree2str(root->left) + ')';
    // If the root has the right child, output the result for it, too
    if (root->right != nullptr) {
        result += '(' + tree2str(root->right) + ')';
    }
    // Return
    return result;    
}

TreeNode* buildTree(std::vector<int> input) {
    if (!input.size()) {
        return nullptr;
    }
    std::vector<TreeNode*> all_nodes;
    TreeNode* node = new TreeNode(input[0]);
    all_nodes.emplace_back(node);
    for (int idx = 1; idx < input.size(); ++idx) {
        if (input[idx] != Null_Val) {
            node = new TreeNode(input[idx]);
            all_nodes.emplace_back(node); 
            // Make sure there's a parent;
            assert (all_nodes[(idx-1)/2] != nullptr);
            if ((idx-1) % 2 == 0) {
            // This is a left child
                 all_nodes[(idx-1)/2]->left = node;
            } else {
            // This is a right child
                 all_nodes[(idx-1)/2]->right = node;
            }
        } else {
            all_nodes.emplace_back(nullptr);
        }
    }
    return all_nodes[0];
}

void RunTestCases() {
    std::vector input = {1, 2, 3, 4};
    TreeNode* new_tree = buildTree(input);
    std::string result = tree2str(new_tree);
    assert (result == "1(2(4))(3)");

    input = {1, 2, 3, Null_Val, 4};
    new_tree = buildTree(input);
    result = tree2str(new_tree);
    assert (result == "1(2()(4))(3)");    

    input = {1};
    new_tree = buildTree(input);
    result = tree2str(new_tree);
    assert (result == "1");

    input = {1, Null_Val, 3};
    new_tree = buildTree(input);
    result = tree2str(new_tree);
    assert (result == "1()(3)");

    input = {1, 2};
    new_tree = buildTree(input);
    result = tree2str(new_tree);
    assert (result == "1(2)");
}

int main() {
    RunTestCases();
    return 0;
}