#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, -1);
        std::stack<int> st; // Stores indices of the elements

        // Traverse twice to handle the circular nature of the array
        for (int i = 0; i < 2 * n; ++i) {
            int idx = i % n;
            
            while (!st.empty() && nums[st.top()] < nums[idx]) {
                result[st.top()] = nums[idx];
                st.pop();
            }
            
            // Only push indices during the first pass to avoid redundant processing
            if (i < n) {
                st.push(idx);
            }
        }

        return result;
    }
};