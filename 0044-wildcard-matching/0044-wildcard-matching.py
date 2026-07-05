class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        n, m = len(s), len(p)
        # Create a 2D DP table initialized to False
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        
        # Base case: empty string matches empty pattern
        dp[0][0] = True
        
        # Base case: empty string matches patterns like "***"
        for j in range(1, m + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]
        
        # Fill the DP table
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if p[j - 1] == '*':
                    # '*' matches empty sequence (dp[i][j-1])
                    # or one/more characters (dp[i-1][j])
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
                elif p[j - 1] == '?' or s[i - 1] == p[j - 1]:
                    # Match single character
                    dp[i][j] = dp[i - 1][j - 1]
        
        return dp[n][m]