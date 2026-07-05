#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        // Initialize with -1 to handle the base case for length calculation
        st.push(-1);
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Push the index of '('
                st.push(i);
            } else {
                // Pop the last index for a matching '(' or the base index
                st.pop();
                
                if (st.empty()) {
                    // If stack is empty, this ')' is a new base index
                    st.push(i);
                } else {
                    // Calculate length by subtracting current index 
                    // from the new top of the stack
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};