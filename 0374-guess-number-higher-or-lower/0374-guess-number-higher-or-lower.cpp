class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid; // Found the picked number
            } else if (res == -1) {
                right = mid - 1; // Picked number is lower than mid
            } else {
                left = mid + 1; // Picked number is higher than mid
            }
        }
        return -1;
    }
};