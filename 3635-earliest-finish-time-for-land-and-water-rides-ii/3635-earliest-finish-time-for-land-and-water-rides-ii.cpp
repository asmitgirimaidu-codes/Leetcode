class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // Since n, m can be up to 5 * 10^4, an O(N log N) approach using sorting and prefix minimums is required.
        // Let's pair each start time with its duration and sort them.
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        vector<pair<int, int>> land(n);
        for (int i = 0; i < n; ++i) {
            land[i] = {landStartTime[i], landDuration[i]};
        }
        sort(land.begin(), land.end());
        
        vector<pair<int, int>> water(m);
        for (int j = 0; j < m; ++j) {
            water[j] = {waterStartTime[j], waterDuration[j]};
        }
        sort(water.begin(), water.end());
        
        // Precompute prefix minimums of durations and suffix minimums of finish times for water rides
        vector<int> waterMinDuration(m);
        int curMinDur = 2e9;
        for (int j = m - 1; j >= 0; --j) {
            curMinDur = min(curMinDur, water[j].second);
            waterMinDuration[j] = curMinDur;
        }
        
        vector<long long> waterSuffixFinish(m + 1, 2e18);
        long long curMinFinish = 2e18;
        for (int j = m - 1; j >= 0; --j) {
            curMinFinish = min(curMinFinish, (long long)water[j].first + water[j].second);
            waterSuffixFinish[j] = curMinFinish;
        }
        
        // Precompute prefix minimums of durations and suffix minimums of finish times for land rides
        vector<int> landMinDuration(n);
        curMinDur = 2e9;
        for (int i = n - 1; i >= 0; --i) {
            curMinDur = min(curMinDur, land[i].second);
            landMinDuration[i] = curMinDur;
        }
        
        vector<long long> landSuffixFinish(n + 1, 2e18);
        curMinFinish = 2e18;
        for (int i = n - 1; i >= 0; --i) {
            curMinFinish = min(curMinFinish, (long long)land[i].first + land[i].second);
            landSuffixFinish[i] = curMinFinish;
        }
        
        long long ans = 2e18;
        
        // Case 1: Land ride first, then Water ride
        for (int i = 0; i < n; ++i) {
            long long finish1 = (long long)land[i].first + land[i].second;
            
            // Binary search in water rides to find the boundary where water.first <= finish1
            auto it = lower_bound(water.begin(), water.end(), make_pair((int)finish1 + 1, 0));
            int idx = distance(water.begin(), it);
            
            // Group 1: water.first <= finish1
            if (idx > 0) {
                // We can pick any of the first idx water rides. To minimize finish time: finish1 + minDuration
                long long bestFinish = finish1 + waterMinDuration[0]; // wait, the min duration among the first idx elements
                // Actually, prefix minimum of durations up to idx - 1:
                // Let's compute prefix min durations properly:
                // Let's optimize this part with prefix min of durations.
                // Wait, prefix min duration up to index idx - 1:
            }
        }
        
        // Let's write a clean helper or loop approach for both directions:
        // Direction 1: Land -> Water
        // For each land ride i, finish1 = land[i].first + land[i].second.
        // We look for water rides. If water.first <= finish1, finish time is finish1 + water.second.
        // If water.first > finish1, finish time is water.first + water.second.
        
        // Let's precompute prefix minimums of water durations:
        vector<int> waterPrefixMinDur(m);
        int pmin = 2e9;
        for(int j = 0; j < m; ++j) {
            pmin = min(pmin, water[j].second);
            waterPrefixMinDur[j] = pmin;
        }
        
        for(int i = 0; i < n; ++i) {
            long long finish1 = (long long)land[i].first + land[i].second;
            // binary search for first water ride with start > finish1
            auto it = upper_bound(water.begin(), water.end(), make_pair((int)finish1, (int)2e9));
            int idx = distance(water.begin(), it);
            
            // For water rides with start <= finish1 (indices 0 to idx - 1)
            if (idx > 0) {
                ans = min(ans, finish1 + waterPrefixMinDur[idx - 1]);
            }
            // For water rides with start > finish1 (indices idx to m - 1)
            if (idx < m) {
                ans = min(ans, waterSuffixFinish[idx]);
            }
        }
        
        // Direction 2: Water -> Land
        vector<int> landPrefixMinDur(n);
        pmin = 2e9;
        for(int i = 0; i < n; ++i) {
            pmin = min(pmin, land[i].second);
            landPrefixMinDur[i] = pmin;
        }
        
        for(int j = 0; j < m; ++j) {
            long long finish1 = (long long)water[j].first + water[j].second;
            auto it = upper_bound(land.begin(), land.end(), make_pair((int)finish1, (int)2e9));
            int idx = distance(land.begin(), it);
            
            if (idx > 0) {
                ans = min(ans, finish1 + landPrefixMinDur[idx - 1]);
            }
            if (idx < n) {
                ans = min(ans, landSuffixFinish[idx]);
            }
        }
        
        return ans;
    }
};