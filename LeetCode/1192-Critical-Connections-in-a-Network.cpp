// LeetCode: 1192. Critical Connections in a Network
// 1192-Critical-Connections-in-a-Network.cpp

// There are n servers numbered from 0 to n - 1 connected by undirected 
// server-to-server connections forming a network where connections[i] = [ai, bi] 
// represents a connection between servers ai and bi. Any server can reach 
// other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some 
// servers unable to reach some other server.
// Return all critical connections in the network in any order.

// 2 <= n <= 10^5
// n - 1 <= connections.length <= 10^5
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated connections.

#include <vector>

class Solution {
    const int INF = (int)(1e9);
    int num_servers;
    int timestamp = 0;
    std::vector<int> start_timestamp;
    std::vector<int> low_timestamp;
    std::vector<char> color;
    std::vector<std::vector<int>> adjacencies;
    std::vector<std::vector<int>> result;
public:
    void initialize(int n) {
        num_servers = n;
        start_timestamp = std::vector<int>(num_servers, INF);
        low_timestamp = std::vector<int>(num_servers, INF);
        color = std::vector<char>(num_servers, 'W'); 
        // 'W' = white (not visited); 'G' = grey (being visited);
        // 'B' = black (visited)
    }
    
    void buildAdjacencies(int n, const std::vector<std::vector<int>>& connections) {
        adjacencies = std::vector<std::vector<int>>(n);
        for (auto& connection : connections) {
            adjacencies[connection[0]].push_back(connection[1]);
            adjacencies[connection[1]].push_back(connection[0]);
        }
    }
    
    void dfs(int server, int prev_server) {
        color[server] = 'G';
        ++timestamp;
        start_timestamp[server] = timestamp;
        low_timestamp[server] = timestamp;
        
        for (auto& next_server : adjacencies[server]) {
            if (color[next_server] == 'W') {
                dfs(next_server, server);
                // MAJOR IDEA: If the lowest reachable server for next_server comes 
                // after server, than [server, next_server] is a critical connection
                if (low_timestamp[next_server] > start_timestamp[server]) {
                    result.push_back(std::vector<int>{server, next_server});
                }
            }
            if (next_server != prev_server) {
                low_timestamp[server] = std::min(low_timestamp[server], 
                                                 low_timestamp[next_server]);                
                // CAVEAT: servers in the same component might NOT have the same low_timestamp!
                // I thought otherwise. That was my mistake initially.
            }
        }
        color[server] = 'B'; 
    }
    
    std::vector<std::vector<int>> criticalConnections(
        int n, const std::vector<std::vector<int>>& connections) {
        
        initialize(n);
        buildAdjacencies(n, connections);
        
        for (int idx = 0; idx < num_servers; ++idx) {
            if (color[idx] == 'W') {
                dfs(idx, INF);    
            }
        }
        
        return result;
    }
};