#include <string>
#include <stack>
#include <numeric>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> st;
        long long current_number = 0;
        char last_operator = '+';

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                current_number = current_number * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (last_operator == '+') {
                    st.push(current_number);
                } else if (last_operator == '-') {
                    st.push(-current_number);
                } else if (last_operator == '*') {
                    int top_val = st.top();
                    st.pop();
                    st.push(top_val * current_number);
                } else if (last_operator == '/') {
                    int top_val = st.top();
                    st.pop();
                    st.push(top_val / current_number);
                }
                
                last_operator = c;
                current_number = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};