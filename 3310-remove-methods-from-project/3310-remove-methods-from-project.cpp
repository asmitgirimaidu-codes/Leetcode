#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        // Step 2: Find all suspicious methods starting from k using BFS/DFS
        unordered_set<int> suspicious;
        queue<int> q;
        q.push(k);
        suspicious.insert(k);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (suspicious.find(neighbor) == suspicious.end()) {
                    suspicious.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Check if any non-suspicious method invokes a suspicious method
        bool canRemove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            // If an external node 'u' calls a suspicious node 'v', we cannot remove them
            if (suspicious.find(u) == suspicious.end() && suspicious.find(v) != suspicious.end()) {
                canRemove = false;
                break;
            }
        }

        // Step 4: Prepare the result
        vector<int> result;
        if (!canRemove) {
            // If removal is not possible, return all methods
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
        } else {
            // Return only the methods that are not suspicious
            for (int i = 0; i < n; ++i) {
                if (suspicious.find(i) == suspicious.end()) {
                    result.push_back(i);
                }
            }
        }

        return result;
    }
};