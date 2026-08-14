class Solution {
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int hashPos(int i, int j, int n) {
        return i * n + j;
    }

    // Returns true if the mouse can win from the current state
    bool solve(vector<string>& grid, int cat, int mouse, int turn, int catJump, int mouseJump, int m, int n, int nFloors, vector<vector<vector<int>>>& mem) {
        // If turns exceed the max possible meaningful game length, Cat wins by default rules
        if (turn >= nFloors * 2) return false;
        
        if (mem[cat][mouse][turn] != -1) {
            return mem[cat][mouse][turn];
        }
        
        bool isMouseTurn = (turn % 2 == 0);
        
        if (isMouseTurn) {
            int i = mouse / n;
            int j = mouse % n;
            // Mouse can choose to stay still or move
            for (auto& dir : dirs) {
                for (int jump = 0; jump <= mouseJump; ++jump) {
                    int x = i + dir[0] * jump;
                    int y = j + dir[1] * jump;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') break;
                    
                    int nextMouse = hashPos(x, y, n);
                    // Mouse reaches food -> Mouse wins instantly
                    if (grid[x][y] == 'F') return mem[cat][mouse][turn] = 1;
                    
                    if (solve(grid, cat, nextMouse, turn + 1, catJump, mouseJump, m, n, nFloors, mem)) {
                        return mem[cat][mouse][turn] = 1;
                    }
                }
            }
            return mem[cat][mouse][turn] = 0; // Mouse cannot win, so Cat wins/Mouse loses
        } else {
            int i = cat / n;
            int j = cat % n;
            // Cat can choose to stay still or move
            for (auto& dir : dirs) {
                for (int jump = 0; jump <= catJump; ++jump) {
                    int x = i + dir[0] * jump;
                    int y = j + dir[1] * jump;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') break;
                    
                    int nextCat = hashPos(x, y, n);
                    // Cat catches mouse or reaches food first -> Cat wins
                    if (nextCat == mouse || grid[x][y] == 'F') return mem[cat][mouse][turn] = 0;
                    
                    // If any path leads to Cat not winning (i.e., mouse winning sequence fails for cat), 
                    // wait, if cat makes a move such that mouse can STILL win, cat tries to avoid it.
                    // Specifically, cat wants to win. If any move leads to cat win, cat takes it.
                    // But standard min-max: Mouse tries to return true, Cat tries to return false.
                    if (!solve(grid, nextCat, mouse, turn + 1, catJump, mouseJump, m, n, nFloors, mem)) {
                        return mem[cat][mouse][turn] = 0; // Cat found a winning move
                    }
                }
            }
            return mem[cat][mouse][turn] = 1; // All cat moves lead to mouse winning
        }
    }

public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int m = grid.size();
        int n = grid[0].size();
        int nFloors = 0;
        int cat = 0, mouse = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '#') ++nFloors;
                if (grid[i][j] == 'C') cat = hashPos(i, j, n);
                else if (grid[i][j] == 'M') mouse = hashPos(i, j, n);
            }
        }
        
        // mem table dimensions: [cat_pos][mouse_pos][turn]
        vector<vector<vector<int>>> mem(m * n, vector<vector<int>>(m * n, vector<int>(nFloors * 2, -1)));
        
        return solve(grid, cat, mouse, 0, catJump, mouseJump, m, n, nFloors, mem);
    }
};