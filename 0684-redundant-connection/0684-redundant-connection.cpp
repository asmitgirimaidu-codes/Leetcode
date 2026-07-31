#include <vector>

using namespace std;

class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            // Union by rank
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            return true; // Successfully merged (no cycle)
        }
        return false; // Already in the same set (cycle detected)
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // If unite returns false, it means u and v are already connected, 
            // so adding this edge creates a cycle.
            if (!unite(u, v)) {
                return edge;
            }
        }

        return {};
    }
};