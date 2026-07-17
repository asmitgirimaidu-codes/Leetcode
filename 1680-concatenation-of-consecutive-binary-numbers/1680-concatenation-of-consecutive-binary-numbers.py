class Solution(object):
    def concatenatedBinary(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        MOD = 10**9 + 7
        
        for i in range(1, n + 1):
            # Calculate the number of bits in i.
            # i.bit_length() gives the number of bits required to represent i.
            bits = i.bit_length()
            
            # Shift the current result left by 'bits' and add 'i'.
            ans = ((ans << bits) | i) % MOD
            
        return ans