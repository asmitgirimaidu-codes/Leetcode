class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) {
                count++;
            }
        }
        return count;
    }

private:
    bool isGood(int x) {
        bool isValidRotated = false;
        while (x > 0) {
            int digit = x % 10;
            // 3, 4, and 7 are invalid digits
            if (digit == 3 || digit == 4 || digit == 7) {
                return false;
            }
            // 2, 5, 6, and 9 change when rotated
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                isValidRotated = true;
            }
            x /= 10;
        }
        return isValidRotated;
    }
};