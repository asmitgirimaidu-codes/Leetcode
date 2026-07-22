class Solution(object):
    def reverseSubmatrix(self, grid, x, y, k):
        """
        :type grid: List[List[int]]
        :type x: int
        :type y: int
        :type k: int
        :rtype: List[List[int]]
        """
        # Swap rows from top and bottom of the submatrix until they meet in the middle
        for i in range(k // 2):
            row1 = x + i
            row2 = x + k - 1 - i
            for c in range(y, y + k):
                grid[row1][c], grid[row2][c] = grid[row2][c], grid[row1][c]
                
        return grid