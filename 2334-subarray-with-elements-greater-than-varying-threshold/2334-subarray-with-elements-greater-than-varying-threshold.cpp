#include <vector>
#include <stack>

class Solution {
public:
    int validSubarraySize(std::vector<int>& nums, int threshold) {
        int n = nums.size();
        std::vector<int> left(n), right(n);
        std::stack<int> st;

        // Find the previous smaller element for each index
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Find the next smaller element for each index
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Check each element as the minimum of a subarray of size k
        for (int i = 0; i < n; ++i) {
            int k = right[i] - left[i] - 1;
            if (nums[i] > threshold / k) {
                return k;
            }
        }

        return -1;
    }
};