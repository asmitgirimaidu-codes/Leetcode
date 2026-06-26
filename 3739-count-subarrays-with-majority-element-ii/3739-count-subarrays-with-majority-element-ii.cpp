#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n + 1, 0) {}
    void update(int i, int delta) {
        for (; i < tree.size(); i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        
        // 1. Convert to +1/-1 and build prefix sums
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        // 2. Coordinate Compression for Fenwick Tree
        vector<int> sorted_pref = pref;
        sort(sorted_pref.begin(), sorted_pref.end());
        sorted_pref.erase(unique(sorted_pref.begin(), sorted_pref.end()), sorted_pref.end());

        auto get_rank = [&](int val) {
            return lower_bound(sorted_pref.begin(), sorted_pref.end(), val) - sorted_pref.begin() + 1;
        };

        // 3. Count pairs (i < j) with pref[i] < pref[j]
        FenwickTree ft(sorted_pref.size());
        long long count = 0;
        for (int x : pref) {
            int rank = get_rank(x);
            // Count how many previous prefix sums were strictly smaller
            count += ft.query(rank - 1);
            ft.update(rank, 1);
        }

        return count;
    }
};