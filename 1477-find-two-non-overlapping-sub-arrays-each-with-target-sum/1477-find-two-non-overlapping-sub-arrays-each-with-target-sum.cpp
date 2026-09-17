class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] will store the minimum length of a sub-array with sum = target 
        // ending at or before index i. Initialized to a large value.
        vector<int> min_len(n, 1e9);
        
        unordered_map<int, int> prefix_sum_map;
        prefix_sum_map[0] = -1; // To handle sub-arrays starting from index 0
        
        int current_sum = 0;
        int ans = 1e9;
        int min_so_far = 1e9;
        
        for (int j = 0; j < n; ++j) {
            current_sum += arr[j];
            
            // Check if there is a prefix sum that gives us the target
            int needed = current_sum - target;
            if (prefix_sum_map.find(needed) != prefix_sum_map.end()) {
                int i = prefix_sum_map[needed] + 1; // Start index of current valid sub-array
                int length = j - i + 1;
                
                // If there's a valid non-overlapping sub-array before index i
                if (i > 0 && min_len[i - 1] != 1e9) {
                    ans = min(ans, length + min_len[i - 1]);
                }
                
                // Update min_so_far with the minimum length ending at or before j
                min_so_far = min(min_so_far, length);
            }
            
            min_len[j] = min_so_far;
            prefix_sum_map[current_sum] = j;
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};