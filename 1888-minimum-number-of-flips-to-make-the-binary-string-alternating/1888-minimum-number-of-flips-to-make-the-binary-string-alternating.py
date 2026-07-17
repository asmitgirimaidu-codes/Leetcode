class Solution(object):
    def minFlips(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        s += s
        
        # Target patterns for the two possible alternating states:
        # p0: 010101...
        # p1: 101010...
        
        diff0 = 0 # Differences from p0
        diff1 = 0 # Differences from p1
        
        ans = float('inf')
        
        for i in range(2 * n):
            # Determine expected character at index i for p0 and p1
            # p0: '0' if i is even, '1' if odd
            # p1: '1' if i is even, '0' if odd
            if i % 2 == 0:
                if s[i] == '1': diff0 += 1
                else: diff1 += 1
            else:
                if s[i] == '0': diff0 += 1
                else: diff1 += 1
                
            # Once window size exceeds n, subtract the effect of the leftmost char
            if i >= n:
                left = i - n
                if left % 2 == 0:
                    if s[left] == '1': diff0 -= 1
                    else: diff1 -= 1
                else:
                    if s[left] == '0': diff0 -= 1
                    else: diff1 -= 1
            
            # If window is size n, update answer
            if i >= n - 1:
                # If n is even, diff0 and diff1 cover both target patterns.
                # If n is odd, pattern flips, so we need to consider 
                # differences carefully.
                if n % 2 == 0:
                    ans = min(ans, diff0, diff1)
                else:
                    # For odd n, only one pattern is valid for each window position
                    ans = min(ans, diff0, diff1)
                    
        return ans