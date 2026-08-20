#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

class DSU {
private:
    std::vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    int largestComponentSize(std::vector<int>& nums) {
        int maxVal = *std::max_element(nums.begin(), nums.end());
        DSU dsu(maxVal + 1);

        // Union each number with its prime factors
        for (int num : nums) {
            for (int factor = 2; factor * factor <= num; ++factor) {
                if (num % factor == 0) {
                    dsu.unite(num, factor);
                    dsu.unite(num, num / factor);
                }
            }
        }

        // Count component sizes
        std::unordered_map<int, int> count;
        int maxSize = 0;
        for (int num : nums) {
            int root = dsu.find(num);
            maxSize = std::max(maxSize, ++count[root]);
        }

        return maxSize;
    }
};