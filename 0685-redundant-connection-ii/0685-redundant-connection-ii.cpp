#include <vector>

using namespace std;

class Solution {
private:
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> candidate1, candidate2;
        vector<int> incoming_parent(n + 1, 0);

        // Step 1: Check whether there is a node with two parents
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (incoming_parent[v] == 0) {
                incoming_parent[v] = u;
            } else {
                // Node v has two parents: incoming_parent[v] and u
                candidate1 = {incoming_parent[v], v};
                candidate2 = {u, v};
                break;
            }
        }

        // Step 2: Use Disjoint Set Union (Union-Find) to detect cycles
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If we found a node with two parents, we skip candidate2 initially to see if the rest forms a tree
            if (!candidate2.empty() && edge == candidate2) {
                continue;
            }

            // If a cycle is detected
            if (!unite(u, v)) {
                if (candidate1.empty()) {
                    // Case 1: No node has two parents, meaning a back-edge forms a cycle
                    return edge;
                } else {
                    // Case 2: A node has two parents, and skipping candidate2 still leaves a cycle,
                    // so candidate1 is the edge that causes the issue.
                    return candidate1;
                }
            }
        }

        // If no cycle was found when skipping candidate2, then candidate2 is the redundant edge.
        return candidate2;
    }
};