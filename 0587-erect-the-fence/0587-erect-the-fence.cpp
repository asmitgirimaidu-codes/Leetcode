class Solution {
public:
    int crossProduct(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 3) return trees;

        // Sort points lexicographically (by x, then by y)
        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        vector<vector<int>> hull;

        // Build lower hull
        for (int i = 0; i < n; ++i) {
            while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }

        // Build upper hull
        for (int i = n - 2, t = hull.size() + 1; i >= 0; --i) {
            while (hull.size() >= t && crossProduct(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }

        // Remove the duplicate starting point that gets added at the end
        hull.pop_back();

        // Remove any remaining duplicates using std::set
        set<vector<int>> uniqueTrees(hull.begin(), hull.end());
        return vector<vector<int>>(uniqueTrees.begin(), uniqueTrees.end());
    }
};