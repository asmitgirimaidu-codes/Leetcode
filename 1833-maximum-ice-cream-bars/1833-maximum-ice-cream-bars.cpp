#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        int max_cost = 0;
        for (int cost : costs) {
            max_cost = std::max(max_cost, cost);
        }
        
        // Frequency array for counting sort
        std::vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }
        
        int ice_creams = 0;
        
        // Buy starting from the cheapest ice cream bars
        for (int c = 1; c <= max_cost; ++c) {
            if (freq[c] == 0) continue;
            
            // If we can't afford all ice creams of price c
            if (coins < (long long)c * freq[c]) {
                ice_creams += coins / c;
                break;
            }
            
            // Otherwise, buy all ice creams of price c
            coins -= c * freq[c];
            ice_creams += freq[c];
        }
        
        return ice_creams;
    }
};