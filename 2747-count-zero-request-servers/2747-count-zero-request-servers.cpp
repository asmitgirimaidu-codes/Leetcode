#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        // Store queries with their original indices: {query_time, original_index}
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        
        // Sort queries by time
        sort(sorted_queries.begin(), sorted_queries.end());
        
        // Sort logs by time: logs[i] = [server_id, time]
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        unordered_map<int, int> server_counts;
        int left = 0, right = 0;
        int num_logs = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int q_time = sorted_queries[i].first;
            int q_idx = sorted_queries[i].second;
            int window_start = q_time - x;
            int window_end = q_time;
            
            // Expand the right pointer to include logs up to window_end
            while (right < num_logs && logs[right][1] <= window_end) {
                server_counts[logs[right][0]]++;
                right++;
            }
            
            // Shrink the left pointer to remove logs older than window_start
            while (left < num_logs && logs[left][1] < window_start) {
                server_counts[logs[left][0]]--;
                if (server_counts[logs[left][0]] == 0) {
                    server_counts.erase(logs[left][0]);
                }
                left++;
            }
            
            // Servers with zero requests = total servers (n) - servers with >= 1 request
            ans[q_idx] = n - server_counts.size();
        }
        
        return ans;
    }
};