#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int max_c = 0;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            max_c = max(max_c, edge[2]);
        }

        int low = 0, high = max_c, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAchieve(mid, n, adj, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canAchieve(int min_val, int n, const vector<vector<pair<int, int>>>& adj, const vector<bool>& online, long long k) {
        // Dijkstra to find shortest path where all edge weights >= min_val
        // and all intermediate nodes are online
        vector<long long> dist(n, 2e18); // Use a large value for infinity
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            if (u == n - 1) return d <= k;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int cost = edge.second;

                if (cost >= min_val && online[v]) {
                    if (dist[v] > d + cost) {
                        dist[v] = d + cost;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return dist[n - 1] <= k;
    }
};