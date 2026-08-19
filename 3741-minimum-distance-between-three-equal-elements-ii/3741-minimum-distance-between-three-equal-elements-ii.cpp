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
        
        // Check sliding windows of 3 consecutive indices for each unique element
        for (const auto& pair : indexMap) {
            const auto& indices = pair.second;
            if (indices.size() >= 3) {
                for (size_t i = 0; i + 2 < indices.size(); ++i) {
                    int dist = 2 * (indices[i + 2] - indices[i]);
                    minDistance = std::min(minDistance, dist);
                }
            }
        }
        
        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};