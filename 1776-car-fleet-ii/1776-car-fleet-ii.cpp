#include <vector>
#include <stack>

class Solution {
public:
    std::vector<double> getCollisionTimes(std::vector<std::vector<int>>& cars) {
        int n = cars.size();
        std::vector<double> answer(n, -1.0);
        std::stack<int> st; // Stores indices of cars

        // Traverse backwards from the last car to the first car
        for (int i = n - 1; i >= 0; --i) {
            int p1 = cars[i][0];
            int s1 = cars[i][1];

            // Pop cars from the stack if:
            // 1. The current car is faster than or equal to the car at stack top (will never catch up).
            // 2. The collision time with the car at stack top happens *after* or *at the same time* 
            //    as the stack top car's collision with its own next car.
            while (!st.empty()) {
                int j = st.top();
                int p2 = cars[j][0];
                int s2 = cars[j][1];

                if (s1 <= s2 || (double)(p2 - p1) / (s1 - s2) >= answer[j] && answer[j] != -1.0) {
                    st.pop();
                } else {
                    break;
                }
            }

            // If stack is not empty, the current car collides with the car at the top of the stack
            if (!st.empty()) {
                int j = st.top();
                int p2 = cars[j][0];
                int s2 = cars[j][1];
                answer[i] = (double)(p2 - p1) / (s1 - s2);
            }

            st.push(i);
        }

        return answer;
    }
};