#include <vector>
#include <queue>

class Solution {
public:
    int shortestPathLength(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        int target_mask = (1 << n) - 1;
        std::queue<std::vector<int>> q; // Stores {node, mask, distance}
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(1 << n, false));

        // Initialize BFS with all nodes as starting points
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            q.push({i, mask, 0});
            visited[i][mask] = true;
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int u = curr[0];
            int mask = curr[1];
            int dist = curr[2];

            // If all nodes are visited, return the distance
            if (mask == target_mask) {
                return dist;
            }

            // Explore neighbors
            for (int v : graph[u]) {
                int next_mask = mask | (1 << v);
                if (!visited[v][next_mask]) {
                    visited[v][next_mask] = true;
                    q.push({v, next_mask, dist + 1});
                }
            }
        }

        return -1;
    }
};