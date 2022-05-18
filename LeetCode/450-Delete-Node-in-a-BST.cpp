// LeetCode: 450. Delete Node in a BST
// 450-Delete-Node-in-a-BST.cpp
// Created by Victor Rogulenko
// [2022-05-18 17:22]  

// Given a root node reference of a BST and a key, 
// delete the node with the given key in the BST. 
// eturn the root node reference (possibly updated) of the BST.

// Follow up: Could you solve it with time complexity O(height of tree)?

// The number of nodes in the tree is in the range [0, 10^4].
// -10^5 <= Node.val <= 10^5
// Each node has a unique value.
// root is a valid binary search tree.
// -10^5 <= key <= 10^5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// MAJOR IDEA: we do not necessarily delete the node with key.
// We find a more suitable node for deletion, swap its values with
// the key_match_node, and delete it.
// Suitable: key_match_node itself if it has one child only
// or the next node with no left child

class Solution {
    struct ChildParentPair {
        ChildParentPair() : self(nullptr), parent(nullptr) {};
        ChildParentPair(TreeNode* sf, TreeNode* pr) : 
            self(sf), parent(pr) {};      
        TreeNode* self;
        TreeNode* parent;
    };

public:
    ChildParentPair findNode(TreeNode* root, int key) {
        TreeNode* prev = nullptr;
        while (root) {
            TreeNode* cur = root;
            if (key < root->val) {
                root = root->left;
            } else if (key > root->val) {
                root = root->right;
            } else {
                break;
            }
            prev = cur;
        }
        return ChildParentPair(root, prev);
    }
    
    ChildParentPair findNext(TreeNode* root) {
        if (!root) {
            return ChildParentPair(nullptr, nullptr);
        }
        
        TreeNode* prev = root;
        root = root->right;
        
        while (root && root->left) {
            TreeNode* cur = root;
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
            prev = cur;
        }
        
        return ChildParentPair(root, prev);
    }
    
    void replaceConnection(TreeNode* parent, 
                           TreeNode* old_child, 
                           TreeNode* new_child) {
        if (!parent) {
            return;
        }
        
        TreeNode* comparisonNode = (old_child != nullptr ? 
                                    old_child : 
                                    new_child);
        
        if (comparisonNode) {
            if (comparisonNode->val < parent->val) {
                parent->left = new_child;
            } else {
                parent->right = new_child;
            }
        }
        // Otherwise, both old_child and new_child are nullptr, 
        // so there's nothing to replace
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        // Find which key we want to delete
        auto key_match_node = findNode(root, key);
        
        // If key's not found in the tree, return
        if (!key_match_node.self) {
            return root;
        }
        
        auto node_for_deletion = key_match_node;
        // If the node_for_deletion has both children, replace it with 
        // the next node which does not have a left child
        if (node_for_deletion.self->left && node_for_deletion.self->right) {
            node_for_deletion = findNext(node_for_deletion.self);    
        }
        
        // Collect all the belongings of node_for_deletion
        key_match_node.self->val = node_for_deletion.self->val;
        
        TreeNode* child = nullptr;
        if (node_for_deletion.self->left) {
            child = node_for_deletion.self->left;
        } else {
            child = node_for_deletion.self->right;
        }
        
        // Update root if needed
        if (node_for_deletion.self == root) {
            root = child;    
        }
        
        // Connect node_for_deletion's parent to child
        replaceConnection(node_for_deletion.parent,
                          node_for_deletion.self,
                          child);
        
        // Delete!
        delete node_for_deletion.self;
        
        return root;
    }
};