// LeetCode: 559. Maximum Depth of N-ary Tree
// Created by Victor Rogulenko
// May 10, 2022

#include <cassert>

// Given a n-ary tree, find its maximum depth.
// The maximum depth is the number of nodes along the 
// longest path from the root node down to the farthest 
// leaf node.

// Nary-Tree input serialization is represented in their 
// level order traversal, each group of children is 
// separated by the null value (See examples).

// The total number of nodes is in the range [0, 10^4].
// The depth of the n-ary tree is less than or equal to 1000.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int result = 1;
    for (auto& node : root->children) {
        int candidate = maxDepth(node) + 1;
        result = (result < candidate ? candidate : result);
    }
    return result;
}

void RunTestCases() {
    //assert(TBD() == "");
}

int main() {
    RunTestCases();
    return 0;
}