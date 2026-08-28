#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // Step 1: Sort the piles in ascending order
        sort(piles.begin(), piles.end());
        
        int n = piles.size();
        int totalCoins = 0;
        
        // Step 2: Iterate starting from the end, taking every second element in groups of 3
        // You get piles at indices: n - 2, n - 4, n - 6, ..., up to n / 3
        for (int i = n / 3; i < n; i += 2) {
            totalCoins += piles[i];
        }
        
        return totalCoins;
    }
};