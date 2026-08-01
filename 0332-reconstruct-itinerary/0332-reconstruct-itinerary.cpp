#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        // Map each airport to a min-heap of destinations to ensure lexicographical order
        std::unordered_map<std::string, std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>>> adj;
        
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        
        std::vector<std::string> itinerary;
        std::string start = "JFK";
        
        // Helper lambda for DFS (Hierholzer's algorithm)
        auto dfs = [&](auto& self, const std::string& airport) -> void {
            auto& targets = adj[airport];
            while (!targets.empty()) {
                std::string next_airport = targets.top();
                targets.pop();
                self(self, next_airport);
            }
            itinerary.push_back(airport);
        };
        
        dfs(dfs, start);
        
        // The path is built in reverse order (post-order traversal), so reverse it
        std::reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};