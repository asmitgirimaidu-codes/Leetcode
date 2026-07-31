#include <vector>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    void dfs(int u, int p, int d, const vector<vector<int>>& adj, int& max_depth) {
        max_depth = max(max_depth, d);
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj, max_depth);
            }
        }
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int max_depth = 0;
        dfs(1, 0, 0, adj, max_depth);

        if (max_depth == 0) {
            return 0;
        }

        return power(2, max_depth - 1);
    }
};