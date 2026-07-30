#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int oddEvenJumps(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        std::vector<bool> higher(n, false);
        std::vector<bool> lower(n, false);
        
        higher[n - 1] = true;
        lower[n - 1] = true;
        
        int good_indices = 1; // The last index is always a good starting index

        // Helper to find next greater/smaller indices using monotonic stacks and sorting
        std::vector<int> next_higher = findNextHigher(arr);
        std::vector<int> next_lower = findNextLower(arr);

        for (int i = n - 2; i >= 0; --i) {
            if (next_higher[i] != -1) {
                higher[i] = lower[next_higher[i]];
            }
            if (next_lower[i] != -1) {
                lower[i] = higher[next_lower[i]];
            }
            
            if (higher[i]) {
                good_indices++;
            }
        }

        return good_indices;
    }

private:
    std::vector<int> findNextHigher(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> res(n, -1);
        std::vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 0);

        // Sort by value ascending, then by index ascending
        std::sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (arr[a] == arr[b]) return a < b;
            return arr[a] < arr[b];
        });

        std::stack<int> st;
        for (int idx : indices) {
            while (!st.empty() && st.top() < idx) {
                res[st.top()] = idx;
                st.pop();
            }
            st.push(idx);
        }
        return res;
    }

    std::vector<int> findNextLower(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> res(n, -1);
        std::vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 0);

        // Sort by value descending, then by index ascending
        std::sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (arr[a] == arr[b]) return a < b;
            return arr[a] > arr[b];
        });

        std::stack<int> st;
        for (int idx : indices) {
            while (!st.empty() && st.top() < idx) {
                res[st.top()] = idx;
                st.pop();
            }
            st.push(idx);
        }
        return res;
    }
};