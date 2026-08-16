class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};
        for (int stone : stones) {
            count[stone % 3]++;
        }
        
        // If there are no stones with remainder 1 or 2, Alice cannot make any valid move.
        if (count[1] == 0 && count[2] == 0) {
            return false;
        }
        
        // If the number of 0-remainder stones is even, Alice wins if and only if 
        // both count[1] and count[2] are non-zero.
        if (count[0] % 2 == 0) {
            return count[1] > 0 && count[2] > 0;
        }
        
        // If the number of 0-remainder stones is odd, Alice wins if the absolute 
        // difference between count[1] and count[2] is strictly greater than 2.
        return abs(count[1] - count[2]) > 2;
    }
};