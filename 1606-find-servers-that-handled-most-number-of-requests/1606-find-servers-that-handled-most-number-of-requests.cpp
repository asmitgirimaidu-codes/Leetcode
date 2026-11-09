#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        // Min-heap to store busy servers: {release_time, server_id}
        std::priority_queue<std::pair<long long, int>, 
                            std::vector<std::pair<long long, int>>, 
                            std::greater<std::pair<long long, int>>> busy_servers;
        
        // Ordered set to store indices of available servers
        std::set<int> available_servers;
        for (int i = 0; i < k; ++i) {
            available_servers.insert(i);
        }

        std::vector<int> request_count(k, 0);
        int max_requests = 0;

        for (int i = 0; i < arrival.size(); ++i) {
            long long current_time = arrival[i];
            long long finish_time = current_time + load[i];

            // Free up servers that have finished their tasks by the current arrival time
            while (!busy_servers.empty() && busy_servers.top().first <= current_time) {
                available_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }

            // If all servers are busy, drop the request
            if (available_servers.empty()) {
                continue;
            }

            // Find the first available server >= (i % k)
            int target = i % k;
            auto it = available_servers.lower_bound(target);

            // If no server >= target is available, wrap around to the beginning
            if (it == available_servers.end()) {
                it = available_servers.begin();
            }

            int assigned_server = *it;
            available_servers.erase(it);

            // Assign the request to this server
            busy_servers.push({finish_time, assigned_server});
            request_count[assigned_server]++;
            max_requests = std::max(max_requests, request_count[assigned_server]);
        }

        // Collect all servers that handled the maximum number of requests
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                result.push_back(i);
            }
        }

        return result;
    }
};