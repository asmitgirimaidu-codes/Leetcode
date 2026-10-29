#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 26-bit mask representation for character frequencies (a-z)
    inline int charToMask(char c) {
        return 1 << (c - 'a');
    }

    struct SegmentTree {
        int n;
        vector<int> tree;
        vector<int> lazy;

        SegmentTree(int size) {
            n = size;
            tree.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void build(int node, int start, int end, const vector<int>& initial_masks) {
            if (start == end) {
                tree[node] = initial_masks[start];
                return;
            }
            int mid = (start + end) / 2;
            build(2 * node, start, mid, initial_masks);
            build(2 * node + 1, mid + 1, end, initial_masks);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }

        void update(int node, int start, int end, int idx, int val) {
            if (start == end) {
                tree[node] = val;
                return;
            }
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }

        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l)
                return 0;
            if (l <= start && end <= r)
                return tree[node];
            int mid = (start + end) / 2;
            return query(2 * node, start, mid, l, r) ^ query(2 * node + 1, mid + 1, end, l, r);
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Heavy-Light Decomposition variables
        vector<int> parent(n, -1), depth(n, 0), heavy(n, -1), head(n, 0), pos(n, 0), sz(n, 0);
        
        auto dfs1 = [&](auto self, int u, int p, int d) -> int {
            parent[u] = p;
            depth[u] = d;
            sz[u] = 1;
            int max_sub = 0;
            for (int v : adj[u]) {
                if (v != p) {
                    int sub_sz = self(self, v, u, d + 1);
                    sz[u] += sub_sz;
                    if (sub_sz > max_sub) {
                        max_sub = sub_sz;
                        heavy[u] = v;
                    }
                }
            }
            return sz[u];
        };
        dfs1(dfs1, 0, -1, 0);

        int cur_pos = 0;
        auto dfs2 = [&](auto self, int u, int h) -> void {
            head[u] = h;
            pos[u] = cur_pos++;
            if (heavy[u] != -1) {
                self(self, heavy[u], h);
            }
            for (int v : adj[u]) {
                if (v != parent[u] && v != heavy[u]) {
                    self(self, v, v);
                }
            }
        };
        dfs2(dfs2, 0, 0);

        vector<int> initial_masks(n);
        for (int i = 0; i < n; ++i) {
            initial_masks[pos[i]] = charToMask(s[i]);
        }

        SegmentTree st(n);
        st.build(1, 0, n - 1, initial_masks);

        auto query_path = [&](int u, int v) {
            int res = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] > depth[head[v]]) {
                    res ^= st.query(1, 0, n - 1, pos[head[u]], pos[u]);
                    u = parent[head[u]];
                } else {
                    res ^= st.query(1, 0, n - 1, pos[head[v]], pos[v]);
                    v = parent[head[v]];
                }
            }
            if (depth[u] > depth[v]) {
                res ^= st.query(1, 0, n - 1, pos[v], pos[u]);
            } else {
                res ^= st.query(1, 0, n - 1, pos[u], pos[v]);
            }
            return res;
        };

        vector<bool> answer;
        for (const string& q : queries) {
            if (q[0] == 'u') {
                int u;
                char c;
                // Parse "update u c"
                int space1 = q.find(' ');
                int space2 = q.find(' ', space1 + 1);
                u = stoi(q.substr(space1 + 1, space2 - space1 - 1));
                c = q[space2 + 1];

                s[u] = c;
                st.update(1, 0, n - 1, pos[u], charToMask(c));
            } else {
                int u, v;
                // Parse "query u v"
                int space1 = q.find(' ');
                int space2 = q.find(' ', space1 + 1);
                u = stoi(q.substr(space1 + 1, space2 - space1 - 1));
                v = stoi(q.substr(space2 + 1));

                int path_mask = query_path(u, v);
                // Check if at most one bit is set: path_mask & (path_mask - 1) == 0
                bool can_form_palindrome = (path_mask & (path_mask - 1)) == 0;
                answer.push_back(can_form_palindrome);
            }
        }

        return answer;
    }
};