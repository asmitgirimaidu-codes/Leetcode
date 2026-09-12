#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list and compute in-degrees
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);
        
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Step 2: Push all nodes with 0 in-degree into the queue
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 3: Process the graph
        int processedCourses = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            processedCourses++;
            
            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: If we processed all courses, there is no cycle
        return processedCourses == numCourses;
    }
};