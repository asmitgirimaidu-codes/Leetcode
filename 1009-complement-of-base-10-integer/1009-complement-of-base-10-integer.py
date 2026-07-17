class Solution(object):
    def bitwiseComplement(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Corner case: if n is 0, its complement is 1
        if n == 0:
            return 1
            
        # Create a mask with the same number of bits as n
        # bin(n) gives '0b...', so we take length - 2
        mask = (1 << n.bit_length()) - 1
        
        # XOR n with the mask to flip all bits
        return n ^ mask