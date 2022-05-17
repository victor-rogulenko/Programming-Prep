// LeetCode: 222. Count Complete Tree Nodes
// 222-Count-Complete-Tree-Nodes.cpp

// Given the root of a complete binary tree, return the number of the nodes 
// in the tree.

// According to Wikipedia, every level, except possibly the last, is 
// completely filled in a complete binary tree, and all nodes in the 
// last level are as far left as possible. It can have between 1 and 2h 
// nodes inclusive at the last level h.

// Design an algorithm that runs in less than O(n) time complexity.

// The number of nodes in the tree is in the range [0, 5 * 104].
// 0 <= Node.val <= 5 * 10^4
// The tree is guaranteed to be complete.

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

class Solution {
public:
    int findHeight(TreeNode* root) {
        int result = -1;
        while (root) {
            ++result;
            root = root->left;
        }
        return result;
    }
    
    bool checkNodeExists(TreeNode* root, int order, int cur_height) {
        if (!root || (cur_height == 0 && order > 1)) {
            return false;
        }
        if (cur_height == 0) {
            return true;
        }
        
        int base = (1 << (cur_height-1));
        if (order > base) {
            return checkNodeExists(root->right, order - base, cur_height-1);
        } else {
            return checkNodeExists(root->left, order, cur_height-1);
        }
    }
    
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int height = findHeight(root);
        if (height == 0) {
            return 1;
        }
        int start = 1;
        int finish = (1 << height) + 1;  
        
        while (start < finish) {
            int mid = start + (finish - start + 1) / 2;
            if (checkNodeExists(root, mid, height)) {
               start = mid; 
            } else {
               finish = mid - 1; 
            }
        }
        
        return (1 << height) - 1 + start;
    }
};