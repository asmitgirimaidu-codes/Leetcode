class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> indexed_nums(n);
        for (int i = 0; i < n; ++i) {
            indexed_nums[i] = {nums[i], i};
        }
        
        // Sort based on element values
        sort(indexed_nums.begin(), indexed_nums.end());
        
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n) {
                if (j > i && indexed_nums[j].first - indexed_nums[j - 1].first > limit) {
                    break;
                }
                j++;
            }
            
            // Extract original indices and sort them
            vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(indexed_nums[k].second);
            }
            sort(indices.begin(), indices.end());
            
            // Assign sorted values back to the sorted original indices
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = indexed_nums[i + k].first;
            }
            
            i = j;
        }
        
        return result;
    }
};