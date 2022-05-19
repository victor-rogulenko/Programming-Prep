// LeetCode: 310. Minimum Height Trees
// 310-Minimum-Height-Trees.cpp
// Created by Victor Rogulenko
// [2022-05-19 13:53]	

// A tree is an undirected graph in which any two vertices are 
// connected by exactly one path. In other words, any connected 
// graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array 
// of n - 1 edges where edges[i] = [ai, bi] indicates that there is 
// an undirected edge between the two nodes ai and bi in the tree, 
// you can choose any node of the tree as the root. When you select 
// a node x as the root, the result tree has height h. Among all 
// possible rooted trees, those with minimum height (i.e. min(h)) 
// are called minimum height trees (MHTs).
// Return a list of all MHTs' root labels. You can return the answer 
// in any order.
// The height of a rooted tree is the number of edges on the longest 
// downward path between the root and a leaf.

// 1 <= n <= 2 * 10^4
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no 
// repeated edges.

// MAJOR IDEA: Keep trimming leaves until we have not more than 2 nodes
// These 1 or 2 nodes are the centroids, i.e. nodes equally removed from
// other nodes

#include <vector>
#include <queue>
#include <set>

class Solution {
    std::vector<std::set<int>> neighbors;
    std::queue<int> leaves;
    int num_nodes;
public:
    void buildAdjacencies(const std::vector<std::vector<int>>& edges) {
        neighbors = std::vector<std::set<int>>(num_nodes);
        for (auto& edge : edges) {
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }
    }
    
    void buildLeaves() {
        for (int idx = 0; idx < num_nodes; ++idx) {
            if (neighbors[idx].size() == 1) {
                leaves.push(idx);
            }
        }
    }
    
    std::vector<int> findMinHeightTrees(
    	int n, const std::vector<std::vector<int>>& edges) {

        if (n < 2) {
            return std::vector<int>{0};
        }
        
        num_nodes = n;
        buildAdjacencies(edges);
        buildLeaves();
        
        while (num_nodes > 2) {
            num_nodes -= leaves.size();
            std::queue<int> new_leaves;
            while (!leaves.empty()) {
                int candidate = *(neighbors[leaves.front()].begin());
                neighbors[candidate].erase(leaves.front());
                if (neighbors[candidate].size() == 1) {
                    new_leaves.push(candidate);
                }
                leaves.pop();
            }
            leaves = new_leaves;
        }
        
        std::vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};