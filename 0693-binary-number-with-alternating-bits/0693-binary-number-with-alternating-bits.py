class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # Convert the integer to its binary string representation
        # [2:] removes the '0b' prefix
        bits = bin(n)[2:]
        
        # Check every adjacent pair of bits
        for i in range(len(bits) - 1):
            if bits[i] == bits[i+1]:
                return False
        
        return True