#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) v1.push_back({r, c});
                if (img2[r][c] == 1) v2.push_back({r, c});
            }
        }
        
        map<pair<int, int>, int> counts;
        int max_overlap = 0;
        
        for (auto& p1 : v1) {
            for (auto& p2 : v2) {
                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;
                max_overlap = max(max_overlap, ++counts[{dr, dc}]);
            }
        }
        
        return max_overlap;
    }
};