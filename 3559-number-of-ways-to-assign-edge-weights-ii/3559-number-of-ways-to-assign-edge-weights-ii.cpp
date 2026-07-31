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

    void dfs(int u, int p, int d, const vector<vector<int>>& adj, vector<int>& depth, vector<vector<int>>& up) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < 20; ++i) {
            if (up[u][i - 1] != 0) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj, depth, up);
            }
        }
    }

    int getLCA(int u, int v, const vector<int>& depth, const vector<vector<int>>& up) {
        if (depth[u] < depth[v]) swap(u, v);
        
        // Bring u to the same depth as v
        for (int i = 19; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        for (int i = 19; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> depth(n + 1, 0);
        vector<vector<int>> up(n + 1, vector<int>(20, 0));
        
        dfs(1, 0, 0, adj, depth, up);

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int lca = getLCA(u, v, depth, up);
            int path_length = depth[u] + depth[v] - 2 * depth[lca];

            if (path_length == 0) {
                answer.push_back(0);
            } else {
                long long ways = power(2, path_length - 1);
                answer.push_back(ways);
            }
        }

        return answer;
    }
};