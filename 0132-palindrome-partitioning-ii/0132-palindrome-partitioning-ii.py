class Solution(object):
    def minCut(self, s):
        """:type s: str
        :rtype: int
        """
        n = len(s)
        if n <= 1:
            return 0
            
        dp = [i for i in range(n)]
        is_pal = [[False] * n for _ in range(n)]
        
        for i in range(n):
            min_cuts = i
            for j in range(i + 1):
                if s[j] == s[i] and (i - j <= 1 or is_pal[j + 1][i - 1]):
                    is_pal[j][i] = True
                    if j == 0:
                        min_cuts = 0
                    else:
                        min_cuts = min(min_cuts, dp[j - 1] + 1)
            dp[i] = min_cuts
            
        return dp[n - 1]