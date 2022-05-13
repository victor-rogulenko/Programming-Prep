// LeetCode: 117. Populating Next Right Pointers in Each Node II
// 117-Populating-Next-Right-Pointers-in-Each-Node-II.cpp
// Created by Victor Rogulenko
// May 13, 2022

#include <cassert>

// Given a binary tree, populate each next pointer to point to 
// its next right node. If there is no next right node, the next 
// pointer should be set to NULL.

// The number of nodes in the tree is in the range [0, 6000].
// -100 <= Node.val <= 100

// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space 
// does not count as extra space for this problem.

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connectUsingPrev(Node* root, Node* prev) {
        // Set up 'next' for 'root'
        if (root == nullptr) {
            return nullptr;
        }
        if (prev == nullptr) {
            root->next = nullptr;
        } else {
            if ((prev->right != nullptr) && (prev->right != root)) {
                root->next = prev->right;
            } else {
                do {
                    prev = prev->next;
                } while ((prev != nullptr) && (prev->right == nullptr) &&
                        (prev->left == nullptr));
                // We have either found the next right node for root 
                // or reached the end of this level
                if (prev == nullptr) {
                    root->next = nullptr;
                } else if (prev->left != nullptr) {
                    root->next = prev->left;
                } else {
                    root->next = prev->right;
                }
            }
        }

        // Process the children of 'root'
        connectUsingPrev(root->right, root);
        connectUsingPrev(root->left, root);
        return root;
    };

    Node* connect(Node* root) {
        return connectUsingPrev(root, nullptr);
    };
};

// Testing on paper
// [1,2,3,4,5,6,7,8,9,10,null,null,null,null,11]

// void RunTestCases() {
//     assert(TBD() == "");
// }

int main() {
    // RunTestCases();
    return 0;
}