class Solution(object):
    def minAbsDiff(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        m = len(grid)
        n = len(grid[0])
        ans = [[0] * (n - k + 1) for _ in range(m - k + 1)]
        
        for i in range(m - k + 1):
            for j in range(n - k + 1):
                # Extract all distinct values in the current k x k submatrix
                values = []
                for r in range(i, i + k):
                    for c in range(j, j + k):
                        values.append(grid[r][c])
                
                # Sort the unique values to easily find the minimum absolute difference
                unique_vals = sorted(list(set(values)))
                
                if len(unique_vals) <= 1:
                    ans[i][j] = 0
                else:
                    min_diff = float('inf')
                    for idx in range(len(unique_vals) - 1):
                        diff = unique_vals[idx + 1] - unique_vals[idx]
                        if diff < min_diff:
                            min_diff = diff
                    ans[i][j] = min_diff
                    
        return ans