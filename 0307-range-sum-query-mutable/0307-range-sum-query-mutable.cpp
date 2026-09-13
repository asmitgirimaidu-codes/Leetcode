#include <vector>

class NumArray {
    int n;
    std::vector<int> tree;

    void build(const std::vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateTree(2 * node + 1, start, mid, idx, val);
        } else {
            updateTree(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0; // Completely outside
        }
        if (L <= start && end <= R) {
            return tree[node]; // Completely inside
        }
        int mid = start + (end - start) / 2;
        return query(2 * node + 1, start, mid, L, R) + 
               query(2 * node + 2, mid + 1, end, L, R);
    }

public:
    NumArray(std::vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        if (n > 0) {
            build(nums, 0, 0, n - 1);
        }
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */