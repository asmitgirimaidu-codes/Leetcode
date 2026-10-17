#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        
        // Helper lambda to calculate the sum of digits of a number
        auto getDigitSum = [](int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        // Create a vector of pairs storing (number, original_index)
        std::vector<std::pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }

        // Sort based on digit sum, and use the number value as a tiebreaker
        std::sort(arr.begin(), arr.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            int sumA = getDigitSum(a.first);
            int sumB = getDigitSum(b.first);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        });

        // Find the minimum swaps using cycle detection
        std::vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            // If the element is already visited or already in the correct position
            if (visited[i] || arr[i].second == i) {
                continue;
            }

            // Traverse the cycle
            int cycleSize = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].second;
                cycleSize++;
            }

            // If a cycle of length L has elements, it takes (L - 1) swaps to sort
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};