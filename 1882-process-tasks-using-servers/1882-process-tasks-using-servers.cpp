#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        // Min-heap for available servers: ordered by weight, then index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        
        // Min-heap for unavailable (busy) servers: ordered by free_time, then weight, then index
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> unavailable;
        
        // Initially all servers are available
        for (int i = 0; i < n; ++i) {
            available.push({servers[i], i});
        }
        
        vector<int> ans(m);
        long long current_time = 0;
        
        for (int j = 0; j < m; ++j) {
            // Ensure current_time is at least the arrival time of task j
            current_time = max(current_time, (long long)j);
            
            // Free up servers that have completed their tasks by current_time
            while (!unavailable.empty() && get<0>(unavailable.top()) <= current_time) {
                auto [free_time, weight, index] = unavailable.top();
                unavailable.pop();
                available.push({weight, index});
            }
            
            // If no servers are available, jump time to the earliest server release time
            if (available.empty()) {
                auto [free_time, weight, index] = unavailable.top();
                unavailable.pop();
                current_time = free_time;
                available.push({weight, index});
                
                // Free any other servers that become free at this exact new time
                while (!unavailable.empty() && get<0>(unavailable.top()) <= current_time) {
                    auto [ft, w, idx] = unavailable.top();
                    unavailable.pop();
                    available.push({w, idx});
                }
            }
            
            // Assign the task to the best available server
            auto [weight, index] = available.top();
            available.pop();
            
            ans[j] = index;
            unavailable.push({current_time + tasks[j], weight, index});
        }
        
        return ans;
    }
};