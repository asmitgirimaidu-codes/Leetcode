class Solution(object):
    def canPartitionGrid(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        m = len(grid)
        n = len(grid[0])
        
        # Check horizontal cuts
        total_sum = sum(sum(row) for row in grid)
        current_sum = 0
        for i in range(m - 1):
            current_sum += sum(grid[i])
            if current_sum * 2 == total_sum:
                return True
                
        # Check vertical cuts
        col_sums = [sum(grid[i][j] for i in range(m)) for j in range(n)]
        total_sum_v = sum(col_sums)
        current_sum_v = 0
        for j in range(n - 1):
            current_sum_v += col_sums[j]
            if current_sum_v * 2 == total_sum_v:
                return True
                
        return False