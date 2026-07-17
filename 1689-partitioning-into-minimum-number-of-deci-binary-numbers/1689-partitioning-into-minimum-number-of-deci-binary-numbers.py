class Solution(object):
    def minPartitions(self, n):
        """
        :type n: str
        :rtype: int
        """
        # The result is simply the largest digit in the string
        return int(max(n))