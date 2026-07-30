#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> st;

        // Traverse nums2 to find the next greater element for each number using a monotonic stack
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // For elements left in the stack, there is no next greater element
        while (!st.empty()) {
            next_greater[st.top()] = -1;
            st.pop();
        }

        // Build the result for nums1 using the precomputed map
        std::vector<int> result;
        result.reserve(nums1.size());
        for (int num : nums1) {
            result.push_back(next_greater[num]);
        }

        return result;
    }
};