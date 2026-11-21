#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> orig_adj(n);
        for (int i = 1; i < n; ++i) {
            orig_adj[parent[i]].push_back(i);
        }

        vector<vector<int>> new_adj(n);
        array<int, 26> last_seen;
        last_seen.fill(-1);

        // Pass 1: Determine new parents using the closest ancestor with the same character.
        auto build_new_tree = [&](auto& self, int u) -> void {
            int ch = s[u] - 'a';
            int prev_node = last_seen[ch];

            if (u > 0) {
                int new_parent = (prev_node != -1) ? prev_node : parent[u];
                new_adj[new_parent].push_back(u);
            }

            last_seen[ch] = u;
            for (int v : orig_adj[u]) {
                self(self, v);
            }
            last_seen[ch] = prev_node;
        };

        build_new_tree(build_new_tree, 0);

        // Pass 2: Compute subtree sizes in the resulting tree.
        vector<int> answer(n, 0);
        auto compute_sizes = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : new_adj[u]) {
                sz += self(self, v);
            }
            answer[u] = sz;
            return sz;
        };

        compute_sizes(compute_sizes, 0);
        return answer;
    }
};