#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        // Map to store all indices for each value in the array
        unordered_map<int, vector<int>> valIndices;
        for (int i = 0; i < n; ++i) {
            valIndices[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();

                // If we reach the last index
                if (curr == n - 1) {
                    return steps;
                }

                // Try jumping to curr + 1 and curr - 1
                vector<int> nextIndices = {curr - 1, curr + 1};
                
                // Add value-based jumps
                if (valIndices.find(arr[curr]) != valIndices.end()) {
                    for (int nextIdx : valIndices[arr[curr]]) {
                        nextIndices.push_back(nextIdx);
                    }
                    // Clear the map entry to prevent redundant processing of the same value group
                    valIndices.erase(arr[curr]);
                }

                for (int nextIdx : nextIndices) {
                    if (nextIdx >= 0 && nextIdx < n && !visited[nextIdx]) {
                        visited[nextIdx] = true;
                        q.push(nextIdx);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};