#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Adjacency list: u -> list of pairs (v, w)
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        
        // Min-priority queue storing tuples of (weight, node, count)
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        
        // dist[u][count] stores the minimum weight to reach node u with a given consecutive count
        // Using a flattened 1D/2D lookup or a vector of vectors
        vector<vector<long long>> min_weight(n, vector<long long>(k + 1, -1));
        
        // Starting at node 0 with count 1 (since labels[0] appears 1 time) and weight 0
        pq.push({0, 0, 1});
        min_weight[0][1] = 0;
        
        while (!pq.empty()) {
            auto [w, u, count] = pq.top();
            pq.pop();
            
            // If we reached the destination node
            if (u == n - 1) {
                return w;
            }
            
            // If we found a strictly better path to this state already, skip
            if (w > min_weight[u][count]) {
                continue;
            }
            
            // Explore neighbors
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                int next_count = (labels[u] == labels[v]) ? (count + 1) : 1;
                
                if (next_count <= k) {
                    long long next_w = w + weight;
                    if (min_weight[v][next_count] == -1 || next_w < min_weight[v][next_count]) {
                        min_weight[v][next_count] = next_w;
                        pq.push({next_w, v, next_count});
                    }
                }
            }
        }
        
        return -1;
    }
};