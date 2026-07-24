class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        long long cand1 = -3e9, cand2 = -3e9; // Initialize with values out of constraint range
        
        // Step 1: Find potential candidates using Boyer-Moore Voting Algorithm variant for k = 3
        for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Step 2: Verify the candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }
        
        vector<int> result;
        int threshold = nums.size() / 3;
        if (count1 > threshold) result.push_back(cand1);
        if (count2 > threshold) result.push_back(cand2);
        
        return result;
    }
};