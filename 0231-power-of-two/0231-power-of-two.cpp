class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A positive integer is a power of two if and only if it has exactly one set bit.
        // n & (n - 1) drops the lowest set bit. For powers of two, this results in 0.
        return n > 0 && (n & (n - 1)) == 0;
    }
};