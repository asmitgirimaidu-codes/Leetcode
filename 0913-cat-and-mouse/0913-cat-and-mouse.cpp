#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        // color[m][c][turn]: 0 = draw, 1 = mouse win, 2 = cat win
        int color[50][50][3];
        // degree[m][c][turn]: number of valid next moves that are not yet decided
        int degree[50][50][3];

        memset(color, 0, sizeof(color));
        memset(degree, 0, sizeof(degree));

        queue<vector<int>> q;

        // Initialize degrees for all states
        for (int m = 0; m < n; ++m) {
            for (int c = 1; c < n; ++c) {
                // Mouse moves count all neighbors
                degree[m][c][1] = graph[m].size();
                
                // Cat moves cannot include node 0
                int catDegree = 0;
                for (int nextCat : graph[c]) {
                    if (nextCat != 0) {
                        catDegree++;
                    }
                }
                degree[m][c][2] = catDegree;
            }
        }

        // Helper to find previous states that can transition to (m, c, t)
        auto getPrevStates = [&](int m, int c, int t) {
            vector<vector<int>> prevs;
            int pt = 3 - t; // Previous turn
            if (pt == 1) {
                // Previous turn was Mouse, so current was Cat moving from pm to m
                for (int pm : graph[m]) {
                    if (color[pm][c][pt] == 0) {
                        prevs.push_back({pm, c, pt});
                    }
                }
            } else {
                // Previous turn was Cat, so current was Mouse moving from pc to c (pc != 0)
                if (c == 0) return prevs;
                for (int pc : graph[c]) {
                    if (pc != 0 && color[m][pc][pt] == 0) {
                        prevs.push_back({m, pc, pt});
                    }
                }
            }
            return prevs;
        };

        // Add base terminal states to queue
        for (int i = 1; i < n; ++i) {
            for (int t = 1; t <= 2; ++t) {
                // Mouse reaches hole -> Mouse wins
                color[0][i][t] = 1;
                q.push({0, i, t, 1});
                
                // Cat catches Mouse -> Cat wins
                color[i][i][t] = 2;
                q.push({i, i, t, 2});
            }
        }

        // Process queue (Topological Sort / Backward Induction)
        while (!q.empty()) {
            auto state = q.front();
            q.pop();

            int m = state[0], c = state[1], t = state[2], result = state[3];

            for (auto& prev : getPrevStates(m, c, t)) {
                int pm = prev[0], pc = prev[1], pt = prev[2];
                if (color[pm][pc][pt] != 0) continue;

                if (pt == result) {
                    color[pm][pc][pt] = result;
                    q.push({pm, pc, pt, result});
                } else {
                    degree[pm][pc][pt]--;
                    if (degree[pm][pc][pt] == 0) {
                        int losingResult = (pt == 1) ? 2 : 1;
                        color[pm][pc][pt] = losingResult;
                        q.push({pm, pc, pt, losingResult});
                    }
                }
            }
        }

        return color[1][2][1];
    }
};