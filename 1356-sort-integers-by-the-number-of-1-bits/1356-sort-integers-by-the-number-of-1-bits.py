class Solution(object):
    def sortByBits(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        # Sort based on:
        # 1. Number of 1 bits (x.bit_count() in Python 3.10+, or bin(x).count('1'))
        # 2. The value of x itself (for ascending tie-breaking)
        return sorted(arr, key=lambda x: (bin(x).count('1'), x))