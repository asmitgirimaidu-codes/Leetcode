class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array is empty, there are no unique elements
        if (nums.empty()) {
            return 0;
        }
        
        // i will keep track of the index for the next unique element
        int i = 1; 
        
        // j iterates through the array starting from the second element
        for (int j = 1; j < nums.size(); ++j) {
            // When we find a new unique element (different from the previous one)
            if (nums[j] != nums[j - 1]) {
                // Move it to the position pointed to by i
                nums[i] = nums[j];
                // Increment i to the next position
                i++; 
            }
        }
        
        // i represents the number of unique elements found
        return i;
    }
};