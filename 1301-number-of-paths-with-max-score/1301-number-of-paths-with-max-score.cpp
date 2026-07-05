class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        // DP tables initialized to -1 (unreachable) and 0 paths
        vector<vector<int>> max_score(n, vector<int>(n, -1));
        vector<vector<int>> paths(n, vector<int>(n, 0));
        
        // Base case: Starting at 'S'
        max_score[n-1][n-1] = 0;
        paths[n-1][n-1] = 1;
        
        // Iterate from bottom-right to top-left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Skip the starting cell and obstacles
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }
                
                int max_prev = -1;
                // Possible cells we could have moved from: Down, Right, Down-Right
                int dirs[3][2] = {{i + 1, j}, {i, j + 1}, {i + 1, j + 1}};
                
                // 1. Find the maximum score among valid incoming paths
                for (auto& d : dirs) {
                    int r = d[0], c = d[1];
                    if (r < n && c < n && max_score[r][c] != -1) {
                        max_prev = max(max_prev, max_score[r][c]);
                    }
                }
                
                // 2. If the current cell is reachable, calculate its state
                if (max_prev != -1) {
                    int val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    max_score[i][j] = max_prev + val;
                    
                    long long current_paths = 0;
                    // Sum the paths from the incoming cells that match the max_prev score
                    for (auto& d : dirs) {
                        int r = d[0], c = d[1];
                        if (r < n && c < n && max_score[r][c] == max_prev) {
                            current_paths = (current_paths + paths[r][c]) % MOD;
                        }
                    }
                    paths[i][j] = current_paths;
                }
            }
        }
        
        // If the destination is unreachable, max_score[0][0] remains -1
        if (max_score[0][0] == -1) {
            return {0, 0};
        }
        
        return {max_score[0][0], paths[0][0]};
    }
};