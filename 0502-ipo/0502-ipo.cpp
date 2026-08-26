class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Pair up (capital, profit) for easy sorting
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        // Sort projects by required capital ascending
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxProfit; // Max-heap for profits of affordable projects
        int i = 0;
        
        // Repeat at most k times
        for (int j = 0; j < k; ++j) {
            // Push all affordable projects into the max-heap
            while (i < n && projects[i].first <= w) {
                maxProfit.push(projects[i].second);
                i++;
            }
            
            // If no projects can be afforded, break early
            if (maxProfit.empty()) {
                break;
            }
            
            // Greedily pick the project with the maximum profit
            w += maxProfit.top();
            maxProfit.pop();
        }
        
        return w;
    }
};