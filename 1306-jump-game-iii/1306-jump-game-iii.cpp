#include <vector>
#include <queue>

class Solution {
public:
    bool canReach(std::vector<int>& arr, int start) {
        int n = arr.size();
        std::queue<int> q;
        std::vector<bool> visited(n, false);
        
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // If we reach an index with value 0, return true
            if (arr[curr] == 0) {
                return true;
            }
            
            // Possible next jump positions
            int next1 = curr + arr[curr];
            int next2 = curr - arr[curr];
            
            // Check next1
            if (next1 < n && !visited[next1]) {
                visited[next1] = true;
                q.push(next1);
            }
            
            // Check next2
            if (next2 >= 0 && !visited[next2]) {
                visited[next2] = true;
                q.push(next2);
            }
        }
        
        return false;
    }
};