class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        
        // Iterate through each digit position: 1s, 10s, 100s, etc.
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            // Number of full cycles of (i * 10)
            count += (n / divider) * i;
            // Remainder part contributes extra ones if the current digit is >= 1
            count += std::min(std::max(0LL, (n % divider) - i + 1), i);
        }
        
        return count;
    }
};