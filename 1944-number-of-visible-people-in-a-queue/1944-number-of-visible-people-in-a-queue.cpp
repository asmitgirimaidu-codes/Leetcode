#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
        int n = heights.size();
        std::vector<int> answer(n, 0);
        std::stack<int> st; // Stores heights of people to the right

        // Iterate backwards from the last person to the first person
        for (int i = n - 1; i >= 0; --i) {
            int count = 0;

            // Pop people shorter than the current person; 
            // each popped person is visible to person i.
            while (!st.empty() && st.top() < heights[i]) {
                count++;
                st.pop();
            }

            // If there is still someone taller to the right, they are also visible.
            if (!st.empty()) {
                count++;
            }

            answer[i] = count;
            st.push(heights[i]);
        }

        return answer;
    }
};