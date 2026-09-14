#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;
        
        for (int l = 0; l < layers; ++l) {
            vector<int> layer_elements;
            int r1 = l, c1 = l;
            int r2 = m - 1 - l, c2 = n - 1 - l;
            
            // Extract layer elements in counter-clockwise order:
            // 1. Top row (left to right)
            for (int c = c1; c <= c2; ++c) layer_elements.push_back(grid[r1][c]);
            // 2. Right col (top to bottom, excluding corners)
            for (int r = r1 + 1; r < r2; ++r) layer_elements.push_back(grid[r][c2]);
            // 3. Bottom row (right to left)
            for (int c = c2; c >= c1; --c) layer_elements.push_back(grid[r2][c]);
            // 4. Left col (bottom to top, excluding corners)
            for (int r = r2 - 1; r > r1; --r) layer_elements.push_back(grid[r][c1]);
            
            int len = layer_elements.size();
            int rot = k % len;
            rotate(layer_elements.begin(), layer_elements.begin() + rot, layer_elements.end());
            
            // Put back into grid
            int idx = 0;
            for (int c = c1; c <= c2; ++c) grid[r1][c] = layer_elements[idx++];
            for (int r = r1 + 1; r < r2; ++r) grid[r][c2] = layer_elements[idx++];
            for (int c = c2; c >= c1; --c) grid[r2][c] = layer_elements[idx++];
            for (int r = r2 - 1; r > r1; --r) grid[r][c1] = layer_elements[idx++];
        }
        
        return grid;
    }
};