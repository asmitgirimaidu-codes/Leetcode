class Solution(object):
    def sumAndMultiply(self, s, queries):
        MOD = 10**9 + 7
        n = len(s)
        
        # Precompute powers of 10
        pow10 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow10[i] = (pow10[i-1] * 10) % MOD
            
        sumD = [0] * (n + 1)
        cntN0 = [0] * (n + 1)
        p = [0] * (n + 1)
        
        for i in range(n):
            digit = int(s[i])
            sumD[i+1] = sumD[i] + digit
            # Count how many non-zero digits are in the prefix
            cntN0[i+1] = cntN0[i] + (1 if digit > 0 else 0)
            # Concatenate non-zero digits
            if digit > 0:
                p[i+1] = (p[i] * 10 + digit) % MOD
            else:
                p[i+1] = p[i]
            
        ans = []
        for l, r in queries:
            # Number of non-zero digits in range [l, r]
            n0 = cntN0[r+1] - cntN0[l]
            # Sum of all digits in range [l, r]
            sd = sumD[r+1] - sumD[l]
            
            # Extract the concatenated non-zero number x from the range
            # x = (p[r+1] - p[l] * 10^n0) % MOD
            x = (p[r+1] - (p[l] * pow10[n0]) % MOD + MOD) % MOD
            
            # The result is x * sum of digits
            ans.append((x * sd) % MOD)
            
        return ans