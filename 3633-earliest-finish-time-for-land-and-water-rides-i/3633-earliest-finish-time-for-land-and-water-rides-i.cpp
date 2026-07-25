class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = 1e9;
        
        // Try all combinations: Land ride i first, then Water ride j
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Land ride i finishes at:
                int landFinish = max(landStartTime[i], 0) + landDuration[i];
                // Water ride j can start after landFinish:
                int waterFinish = max(waterStartTime[j], landFinish) + waterDuration[j];
                ans = min(ans, waterFinish);
            }
        }
        
        // Try all combinations: Water ride j first, then Land ride i
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                // Water ride j finishes at:
                int waterFinish = max(waterStartTime[j], 0) + waterDuration[j];
                // Land ride i can start after waterFinish:
                int landFinish = max(landStartTime[i], waterFinish) + landDuration[i];
                ans = min(ans, landFinish);
            }
        }
        
        return ans;
    }
};