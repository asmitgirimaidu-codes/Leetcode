#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> solveQueries(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        std::unordered_map<int, std::vector<int>> posMap;
        
        // Group indices by element value
        for (int i = 0; i < n; ++i) {
            posMap[nums[i]].push_back(i);
        }
        
        std::vector<int> answer;
        answer.reserve(queries.size());
        
        for (int q : queries) {
            int val = nums[q];
            const auto& indices = posMap[val];
            
            // If the element appears only once
            if (indices.size() == 1) {
                answer.push_back(-1);
                continue;
            }
            
            // Use binary search to find the position of q in the sorted indices list
            auto it = std::lower_bound(indices.begin(), indices.end(), q);
            int idxInList = std::distance(indices.begin(), it);
            int m = indices.size();
            
            int minDist = n; // Initialize with maximum possible distance
            
            // Check previous index in the sorted list (handling circular boundary)
            int prevIdx = indices[(idxInList - 1 + m) % m];
            if (prevIdx != q) {
                int dist = std::abs(prevIdx - q);
                minDist = std::min(minDist, std::min(dist, n - dist));
            }
            
            // Check next index in the sorted list (handling circular boundary)
            int nextIdx = indices[(idxInList + 1) % m];
            if (nextIdx != q) {
                int dist = std::abs(nextIdx - q);
                minDist = std::min(minDist, std::min(dist, n - dist));
            }
            
            answer.push_back(minDist);
        }
        
        return answer;
    }
};