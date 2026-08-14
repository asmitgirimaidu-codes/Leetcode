class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // Directions for the 8 neighbors
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live_neighbors = 0;
                
                // Count live neighbors
                for (int k = 0; k < 8; ++k) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];
                    
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        // Original state 1 or state 2 means it was live in the current generation
                        if (board[ni][nj] == 1 || board[ni][nj] == 2) {
                            live_neighbors++;
                        }
                    }
                }
                
                // Apply rules
                if (board[i][j] == 1) {
                    // Rule 1 & Rule 3: Live cell dies
                    if (live_neighbors < 2 || live_neighbors > 3) {
                        board[i][j] = 2; // Live -> Dead
                    }
                } else {
                    // Rule 4: Dead cell becomes live
                    if (live_neighbors == 3) {
                        board[i][j] = 3; // Dead -> Live
                    }
                }
            }
        }
        
        // Update board to final state
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};