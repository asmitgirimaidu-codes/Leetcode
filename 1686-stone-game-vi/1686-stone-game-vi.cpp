#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        
        // Store the combined values along with their indices
        vector<vector<int>> stones(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            stones[i][0] = aliceValues[i] + bobValues[i]; // Combined value
            stones[i][1] = aliceValues[i];
            stones[i][2] = bobValues[i];
        }
        
        // Sort in descending order based on the combined value
        sort(stones.begin(), stones.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        
        int aliceScore = 0;
        int bobScore = 0;
        
        // Take turns greedily
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                aliceScore += stones[i][1];
            } else {
                bobScore += stones[i][2];
            }
        }
        
        if (aliceScore > bobScore) return 1;
        if (aliceScore < bobScore) return -1;
        return 0;
    }
};