class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int totalCount = 1; // for x = 0
        int currentUnique = 9;
        int availableDigits = 9;
        
        for (int i = 1; i <= n && i <= 10; ++i) {
            if (i == 1) {
                totalCount += 9; // 1 to 9
            } else {
                currentUnique *= availableDigits;
                totalCount += currentUnique;
                availableDigits--;
            }
        }
        
        return totalCount;
    }
};