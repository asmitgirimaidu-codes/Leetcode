#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count_map;
        for (int num : nums1) {
            count_map[num]++;
        }
        
        vector<int> result;
        for (int num : nums2) {
            if (count_map[num] > 0) {
                result.push_back(num);
                count_map[num]--;
            }
        }
        
        return result;
    }
};