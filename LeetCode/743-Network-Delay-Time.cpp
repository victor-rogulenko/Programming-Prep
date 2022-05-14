// LeetCode: 743. Network Delay Time // 743-Network-Delay-Time.cpp
// Created by Victor Rogulenko
// May 14, 2022

// You are given a network of n nodes, labeled from 1 to n. 
// You are also given times, a list of travel times as directed edges 
// times[i] = (ui, vi, wi), where ui is the source node, vi is the 
// target node, and wi is the time it takes for a signal to travel 
// from source to target.

// We will send a signal from a given node k. Return the time it takes 
// for all the n nodes to receive the signal. If it is impossible 
// for all the n nodes to receive the signal, return -1.

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

#include <cassert>
#include <vector>
#include <set>
#include <utility> // std::pair
#include <unordered_map>
#include <iostream>

class Solution {
    const int INF = (int)(1e9);
    std::vector<int> distances;
    std::unordered_map<int, std::vector<std::pair<int, int>>> edges;
public:
    void buildAdjacencyList(std::vector<std::vector<int>>& times, int num_nodes) {
        for (auto& edge : times) {
            // edge[0] is the start of the edge
            // edge[1] is the end of it
            // edge[2] is the weight of it
            edges[edge[0]].push_back(std::pair<int, int>(edge[2], edge[1]));
        }
    }

    void Dijkstra(std::vector<std::vector<int>>& times, 
                         int num_nodes, int start_node) {
        // Build the adjacency list
        buildAdjacencyList(times, num_nodes);

        distances = std::vector<int>(num_nodes+1, INF);
        distances[0] = 0; // 0 is not used because the nodes are numbered 1..num_nodes
        distances[start_node] = 0;
        // Initiate the queue
        // First: distances[node_num]
        // Second: node_num
        // std::set is a red-black tree, so its beginning is the element
        // with the smallest key 
        std::set<std::pair<int, int>> Q;
        Q.insert(std::pair<int, int>(0, start_node));

        // Process the queue;
        while (!Q.empty()) {
            // Fetch the closest to start element
            // std::set allows to do that
            std::pair<int, int> top = *Q.begin();
            Q.erase(Q.begin());
            int v = top.second;

            // Run through all the nodes adjacent to v
            // and relax the distances
            for (auto& edge : edges[v]) {
                int v2 = edge.second;
                int edge_time = edge.first;

                if (distances[v2] > distances[v] + edge_time) {
                    // Erase the old distance if it wasn't INF
                    if (distances[v2] != INF) {
                        Q.erase(Q.find(std::pair<int, int>(distances[v2], v2)));
                    }
                    distances[v2] = distances[v] + edge_time;
                    Q.insert(std::pair<int, int>(distances[v2], v2));
                }
            }
        }
    }

    int networkDelayTime(std::vector<std::vector<int>>& times, 
                         int num_nodes, int start_node) {
        // Run Dijskstra from current node
        Dijkstra(times, num_nodes, start_node);

        // Find the latest time by which a node is reached 
        // (i.e. all nodes are reached by then)
        // If the answer is INF, return -1
        int result = 0;
        for (auto dist : distances) {
            result = (result < dist ? dist : result);
        }
        return (result < INF ? result : -1);
    }
};

void TestCase(std::vector<std::vector<int>> times, int n, int k, int expected) {
    int result = Solution().networkDelayTime(times, n, k);
    std::cout << "result is " << result << ", expected is " << expected << "\n";
    assert (result == expected);
}

void RunTestCases() {
    TestCase(std::vector<std::vector<int>>{{2,1,1},{2,3,1},{3,4,1}}, 4, 2, 2);
    TestCase(std::vector<std::vector<int>>{{1,2,1}}, 2, 1, 1);
    TestCase(std::vector<std::vector<int>>{{1,2,1}}, 5, 1, -1);
}

int main() {
    RunTestCases();
    return 0;
}