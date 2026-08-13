#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct Node {
        char left_char, right_char;
        int pref, suff, max_len;
    };

    vector<Node> tree;
    string str;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {str[start], str[start], 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    Node combine(const Node& left, const Node& right, int left_len, int right_len) {
        Node res;
        res.left_char = left.left_char;
        res.right_char = right.right_char;

        res.pref = left.pref;
        if (left.pref == left_len && left.right_char == right.left_char) {
            res.pref += right.pref;
        }

        res.suff = right.suff;
        if (right.suff == right_len && right.left_char == left.right_char) {
            res.suff += left.suff;
        }

        res.max_len = max({left.max_len, right.max_len, 
                           (left.right_char == right.left_char ? left.suff + right.pref : 0)});
        return res;
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            str[idx] = val;
            tree[node] = {val, val, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = combine(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        int n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;
        int k = queryIndices.size();
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].max_len);
        }
        return ans;
    }
};