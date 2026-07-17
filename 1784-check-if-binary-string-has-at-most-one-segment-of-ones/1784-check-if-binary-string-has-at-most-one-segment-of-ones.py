class Solution(object):
    def checkOnesSegment(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # If there is a '0' followed by a '1', it means we have 
        # more than one segment of ones.
        return "01" not in s