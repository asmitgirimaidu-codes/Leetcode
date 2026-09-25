class Solution {
private:
    int power(int base, int exp) {
        int res = 1;
        base %= 1337;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1337;
            base = (base * base) % 1337;
            exp /= 2;
        }
        return res;
    }

public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        
        // Extract the last digit of the large exponent array
        int lastDigit = b.back();
        b.pop_back();
        
        // a^1234 = (a^123)^10 * a^4 mod 1337
        long long part1 = power(superPow(a, b), 10);
        long long part2 = power(a, lastDigit);
        
        return (part1 * part2) % 1337;
    }
};