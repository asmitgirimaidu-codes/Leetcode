class Solution {
public:
    bool isUgly(int n) {
        // Ugly numbers are strictly positive integers
        if (n <= 0) return false;

        // Continuously divide by 2, 3, and 5 while divisible
        for (int p : {2, 3, 5}) {
            while (n % p == 0) {
                n /= p;
            }
        }

        // If n is reduced to 1, then it only had 2, 3, or 5 as prime factors
        return n == 1;
    }
};