#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    int scoreOfParentheses(string s) {
        std::stack<int> st;
        st.push(0); // Base score for the current level

        for (char c : s) {
            if (c == '(') {
                st.push(0); // Entering a new nested scope
            } else {
                int inner = st.top();
                st.pop();
                int outer = st.top();
                st.pop();
                
                // If inner is 0, it means it was "()", so score is 1.
                // Otherwise, it was "(A)", so score is 2 * inner.
                // Add this score to the outer scope.
                st.push(outer + std::max(2 * inner, 1));
            }
        }

        return st.top();
    }
};