#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maxChunksToSorted(std::vector<int>& arr) {
        std::stack<int> st; // Monotonic increasing stack to store the maximum element of each chunk

        for (int num : arr) {
            // If the current element is greater than or equal to the largest element 
            // of the previous chunk, it can start a new independent chunk.
            if (st.empty() || num >= st.top()) {
                st.push(num);
            } else {
                // Otherwise, this element belongs to a previous chunk. 
                // We merge it by finding the maximum element of the affected chunks 
                // and keeping it as the representative max for the merged chunk.
                int max_val = st.top();
                st.pop();
                
                while (!st.empty() && st.top() > num) {
                    st.pop();
                }
                
                st.push(max_val);
            }
        }

        // The size of the stack represents the maximum number of chunks we can form
        return st.size();
    }
};