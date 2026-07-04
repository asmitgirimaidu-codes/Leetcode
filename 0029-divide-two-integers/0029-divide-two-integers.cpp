class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the only overflow edge case: INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result using XOR
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        
        // Convert to long long to prevent overflow when getting the absolute values
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        
        long long quotient = 0;
        
        // Subtract multiples of the divisor using bit shifting
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            long long multiple = 1;
            
            // Keep multiplying by 2 (shifting left) until the next multiple is larger than the dividend
            while (absDividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest found multiple from the dividend
            absDividend -= temp;
            // Add the corresponding multiple to the quotient
            quotient += multiple;
        }
        
        // Apply the original sign to the result
        return isNegative ? -quotient : quotient;
    }
};