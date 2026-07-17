class Solution(object):
    def numberOfStableArrays(self, zero, one, limit):
        """
        :type zero: int
        :type one: int
        :type limit: int
        :rtype: int
        """
        MOD = 10**9 + 7
        # dp[z][o][0] -> array ending in 0, dp[z][o][1] -> array ending in 1
        dp = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]
        
        # Base cases: arrays of length up to limit
        for i in range(1, min(zero, limit) + 1): dp[i][0][0] = 1
        for i in range(1, min(one, limit) + 1): dp[0][i][1] = 1
            
        for z in range(1, zero + 1):
            for o in range(1, one + 1):
                # Ending in 0: previous could have been ending in 0 or 1
                # Use sliding window / prefix sum logic
                dp[z][o][0] = (dp[z-1][o][0] + dp[z-1][o][1]) % MOD
                if z > limit:
                    dp[z][o][0] = (dp[z][o][0] - dp[z-limit-1][o][1] + MOD) % MOD
                
                # Ending in 1: 
                dp[z][o][1] = (dp[z][o-1][1] + dp[z][o-1][0]) % MOD
                if o > limit:
                    dp[z][o][1] = (dp[z][o][1] - dp[z][o-limit-1][0] + MOD) % MOD
                    
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD