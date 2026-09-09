class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long start = 1;
        long long len = 1;
        
        while (start <= n) {
            long long end = start * 10 - 1;
            if (end > n) {
                end = n;
            }
            
            // Numbers with 'len' digits have:
            // 0 commas for len <= 3
            // (len - 1) / 3 commas otherwise
            long long commasPerNumber = 0;
            if (len >= 4) {
                commasPerNumber = (len - 1) / 3;
            }
            
            totalCommas += (end - start + 1) * commasPerNumber;
            
            start *= 10;
            len++;
        }
        
        return totalCommas;
    }
};