#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        // Base case: if there's only one node, it's the root itself
        if (n == 1) {
            return {0};
        }

        // Build the adjacency list and compute degrees of each node
        std::vector<std::vector<int>> adj(n);
        std::vector<int> degree(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Initialize the queue with all the leaf nodes (degree == 1)
        std::queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        // Trim the leaves until 2 or fewer nodes remain (the center(s) of the tree)
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;

            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();

                // For the neighbor of the current leaf, remove the connection
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        // The remaining nodes in the queue are the MHT roots
        std::vector<int> mhts;
        while (!leaves.empty()) {
            mhts.push_back(leaves.front());
            leaves.pop();
        }

        return mhts;
    }
};