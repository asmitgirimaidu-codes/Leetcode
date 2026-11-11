class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalCost = 0;
        
        // Find how many units both needs share
        long long common = min(need1, need2);
        
        // For the common part, choose between using a type 3 item or buying one type 1 and one type 2 item separately
        totalCost += common * min((long long)costBoth, (long long)cost1 + cost2);
        
        // Remaining needs after satisfying the common part
        long long rem1 = need1 - common;
        long long rem2 = need2 - common;
        
        // For remaining type 1 needs, choose between type 1 item and type 3 item
        totalCost += rem1 * min((long long)costBoth, (long long)cost1);
        
        // For remaining type 2 needs, choose between type 2 item and type 3 item
        totalCost += rem2 * min((long long)costBoth, (long long)cost2);
        
        return totalCost;
    }
};