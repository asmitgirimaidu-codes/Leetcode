#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumDistance(std::vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> indexMap;
        
        // Group indices by their values
        for (int i = 0; i < nums.size(); ++i) {
            indexMap[nums[i]].push_back(i);
        }
        
        int minDistance = INT_MAX;
        
        // Check triplets for each unique element
        for (const auto& pair : indexMap) {
            const auto& indices = pair.second;
            if (indices.size() >= 3) {
                // Since indices are already sorted, check every sliding window of 3 consecutive indices
                for (size_t i = 0; i + 2 < indices.size(); ++i) {
                    int idx1 = indices[i];
                    int idx3 = indices[i + 2];
                    
                    // Distance formula simplifies to 2 * (k - i) for i < j < k
                    int dist = 2 * (idx3 - idx1);
                    minDistance = std::min(minDistance, dist);
                }
            }
        }
        
        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};