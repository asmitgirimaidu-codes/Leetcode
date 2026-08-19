#include <vector>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Count how many elements are <= mid
            int count = 0;
            int row = n - 1, col = 0; // Start from bottom-left corner
            
            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) {
                    count += (row + 1); // All elements above this row in this column are also <= mid
                    col++;
                } else {
                    row--;
                }
            }

            if (count < k) {
                low = mid + 1;
            } else {
                ans = mid; // Try to find a smaller valid value
                high = mid - 1;
            }
        }

        return ans;
    }
};