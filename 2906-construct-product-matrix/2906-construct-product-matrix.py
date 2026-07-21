class Solution(object):
    def constructProductMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        MOD = 12345
        n, m = len(grid), len(grid[0])
        
        p = [[1] * m for _ in range(n)]
        
        # Compute prefix products
        pref = 1
        for i in range(n):
            for j in range(m):
                p[i][j] = pref
                pref = (pref * grid[i][j]) % MOD
                
        # Compute suffix products and combine
        suff = 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                p[i][j] = (p[i][j] * suff) % MOD
                suff = (suff * grid[i][j]) % MOD
                
        return p