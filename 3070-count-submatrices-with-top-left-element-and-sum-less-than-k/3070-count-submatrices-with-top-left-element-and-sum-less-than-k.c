int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Calculate prefix sum for current cell (i, j)
            if (i > 0) grid[i][j] += grid[i - 1][j];
            if (j > 0) grid[i][j] += grid[i][j - 1];
            if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];

            // Check if the sum is within the limit
            if (grid[i][j] <= k) {
                count++;
            } else {
                // Since grid values are non-negative, if this cell exceeds k,
                // any further submatrix in this row or column will also exceed k.
                // However, the simplest correct approach is just to check all.
            }
        }
    }
    return count;
}