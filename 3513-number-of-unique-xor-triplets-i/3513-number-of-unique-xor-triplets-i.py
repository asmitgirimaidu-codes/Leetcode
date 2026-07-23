class Solution(object):
    def uniqueXorTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        
        if n == 1:
            return 1
        if n == 2:
            return 2
            
        # Find the highest power of 2 less than or equal to n
        msb = 1
        while msb * 2 <= n:
            msb *= 2
            
        # For n >= 3, we can generate all numbers in range [0, 2^(k+1) - 1]
        return msb * 2