#include <vector>
#include <algorithm>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> ugly(n);
        ugly[0] = 1;
        
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n; ++i) {
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;
            
            int next_ugly = std::min({next2, next3, next5});
            ugly[i] = next_ugly;
            
            if (next_ugly == next2) i2++;
            if (next_ugly == next3) i3++;
            if (next_ugly == next5) i5++;
        }
        
        return ugly[n - 1];
    }
};