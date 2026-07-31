#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Helper function for DFS traversal to find the path product from curr to target
    double dfs(string curr, string target, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if (curr == target) return 1.0;
        visited.insert(curr);

        for (auto& neighbor : graph[curr]) {
            string nextNode = neighbor.first;
            double weight = neighbor.second;

            if (visited.find(nextNode) == visited.end()) {
                double subResult = dfs(nextNode, target, graph, visited);
                if (subResult != -1.0) {
                    return weight * subResult;
                }
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            graph[u][v] = val;
            graph[v][u] = 1.0 / val;
        }

        vector<double> results;

        // Step 2: Process each query
        for (auto& query : queries) {
            string start = query[0];
            string end = query[1];

            // If either variable doesn't exist in the graph
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                results.push_back(-1.0);
            } else if (start == end) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double ans = dfs(start, end, graph, visited);
                results.push_back(ans);
            }
        }

        return results;
    }
};