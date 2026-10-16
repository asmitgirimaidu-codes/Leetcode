#include <vector>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;
    
    struct Node {
        long long sum;
        long long lazy;
    };
    
    vector<Node> tree;

    void pushDown(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            int mid = l + (r - l) / 2;
            long long lz = tree[node].lazy;
            
            // Left child
            tree[2 * node].sum = (tree[2 * node].sum + lz * (mid - l + 1)) % MOD;
            tree[2 * node].lazy = (tree[2 * node].lazy + lz) % MOD;
            
            // Right child
            tree[2 * node + 1].sum = (tree[2 * node + 1].sum + lz * (r - mid)) % MOD;
            tree[2 * node + 1].lazy = (tree[2 * node + 1].lazy + lz) % MOD;
            
            tree[node].lazy = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[node].sum = (tree[node].sum + val * (r - l + 1)) % MOD;
            tree[node].lazy = (tree[node].lazy + val) % MOD;
            return;
        }
        pushDown(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node].sum;
        pushDown(node, l, r);
        int mid = l + (r - l) / 2;
        return (query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, {0, 0});
        
        unordered_map<int, int> last_pos;
        long long current_sum_squares = 0;
        long long total_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            int last = -1;
            if (last_pos.find(nums[i]) != last_pos.end()) {
                last = last_pos[nums[i]];
            }
            
            // Range update: add 1 to distinct counts from (last + 1) to i
            long long sum_val = query(1, 0, n - 1, last + 1, i);
            long long added = (2 * sum_val + (i - last)) % MOD;
            current_sum_squares = (current_sum_squares + added) % MOD;
            
            update(1, 0, n - 1, last + 1, i, 1);
            last_pos[nums[i]] = i;
            
            total_sum = (total_sum + current_sum_squares) % MOD;
        }
        
        return total_sum;
    }
};
