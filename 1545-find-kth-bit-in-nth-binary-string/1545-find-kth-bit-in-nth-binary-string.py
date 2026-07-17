class Solution(object):
    def findKthBit(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        # Base case: S1 is "0"
        if n == 1:
            return "0"
        
        # Calculate the middle position
        mid = 1 << (n - 1)
        
        if k == mid:
            return "1"
        elif k < mid:
            # Bit is the same as in the previous string
            return self.findKthBit(n - 1, k)
        else:
            # Bit is the inverted value of the mirror position in the previous string
            # Mirror position: (mid * 2) - k = 2^n - k
            bit = self.findKthBit(n - 1, (1 << n) - k)
            return "0" if bit == "1" else "1"